//
// Created by necromaner on 2019-01-14.
//


#include "yixin.h"
void PctGuiThread::window_Warning(QString key){
    Voice_LowBattery();           // 蜂鸣器响
    QMessageBox *msgBox = new QMessageBox(MainWindowP);//QMessageBox消息对话框
    msgBox->setStyleSheet(QStringLiteral("background-color: rgb(180, 180, 180);"));//setStyleSheet：设置图形界面的外观
    msgBox->setText(AglDeviceP->GetConfig(key));
    msgBox->setIcon(QMessageBox::Warning);//QMessageBox :: warning显示一个警告图标
    msgBox->exec();
    delete msgBox;
    Voice_pressKey();          // 按键声音
}
void PctGuiThread :: flush_icon()                           // 图标刷新函数
{
    static int battery = 0;//电池上一次电量
//    static bool other_State[3]={false,false,false};//0:network 1:udisk 2:sdisk
    static bool iCount_icon1= false;
    if (battery != AglDeviceP->yx_power) {
        battery = AglDeviceP->yx_power;
        if (battery > 0 && battery <= 11)
            /*
             * 0 初始化
             * 1 放0
             * 2 放20
             * 3 放40
             * 4 放60
             * 5 放80
             * 6 放100
             * 7 充20
             * 8 充40
             * 9 充60
             * 10充80
             * 11充100
             */
            Label_Q->setPixmap(QPixmap::fromImage(result_Q[battery - 1]));//贴图
        if (iCount_icon1) {
            if (battery > 5) {//充电状态
                if (2 == iPower)    // 如果刚才是电池状态，弹出电源链接提示
                {
                    window_Warning("sattion_connect");//电源已经连接。
                }
                iPower = 1;
            } else if (battery > 0) {//放电状态
                if (iPower == 1)  // 如果刚才是充电状态，弹出电源断开提示
                {
                    window_Warning("sattion_discon");//电源已经断开连接。
                } else if (battery < 2) {
                    window_Warning("station_low");//电池电量低，请及时充电
                }
                iPower = 2;
            }
        }
    }
    if (AglDeviceP->yx_network)//网络图标
    {
        if (isStart == true || (UiType == TesTResui && isUpload == false && isCount == false)) {
            if (isDisconnect == true) {
                if (LisSocket->state() == 3) {
                    LisSocket->disconnectFromHost();
                    LisSocket->close();
                }
                qDebug() << "网线掉落后，断开网络连接";
            }
            if (LisSocket->state() == 0) {
                bool ok;
                QString LisIp = AglDeviceP->GetPasswd("@LisIP");
                quint16 LisPort = AglDeviceP->GetPasswd("@LisPort").toUInt(&ok, 10);
                if (!LisSocket->open(QIODevice::ReadWrite)) {
                    qDebug() << "'Open Socket error";
                    return;
                }
                LisSocket->connectToHost(LisIp, LisPort);
//                qDebug() << "图标刷新函数获悉在该状态下需要重新连接网络 line 4720";
                isDisconnect = false;
            }
        }
        if (LisSocket->state() == 3) {
            if (iChange[5] > 0) {
                if (iCount_icon1) {
                    Voice_ChangStation();
                }
                iChange[5] = 0;
                iChange[6] = 1;
                iChange_socket = 1;
            }
            Label_net->setPixmap(QPixmap::fromImage(result_net[1]));
        } else {
            if (iChange_socket > 0) {
                if (iCount_icon1) {
                    Voice_ChangStation();
                }
                iChange[5] = 1;
                iChange[6] = 1;
                iChange_socket = 0;
            }
            Label_net->setPixmap(QPixmap::fromImage(result_socket));
        }
//----------------------------------------------------------------------------------------------------------------//
    } else {
        isConnect = false;
        isDisconnect = true;
        if (iChange[6] > 0) {
            if (iCount_icon1) {
                Voice_ChangStation();
            }
            iChange[5] = 1;
            iChange[6] = 0;
            iChange_socket = 1;
        }
        Label_net->setPixmap(QPixmap::fromImage(result_net[0]));
    }
    if (AglDeviceP->yx_udisk)//U盘图标
    {
        if (iChange[7] > 0) {
            if (iCount_icon1) {
                Voice_ChangStation();
            }
            iChange[7] = 0;
            iChange[8] = 1;
        }
        Label_U->setPixmap(QPixmap::fromImage(result_U));
    } else {
        if (iChange[8] > 0) {
            if (iCount_icon1) {
                Voice_ChangStation();
            }
            iChange[7] = 1;
            iChange[8] = 0;
        }
        Label_U->clear();
    }

    if (AglDeviceP->yx_sdisk)//sd卡图标
    {
        Label_SD->setPixmap(QPixmap::fromImage(result_SD));
        if (iChange[9] > 0) {
            if (iCount_icon1) {
                Voice_ChangStation();
            }
            iChange[9] = 0;
            iChange[10] = 1;
        }
    } else {
        if (iChange[10] > 0) {
            if (iCount_icon1) {
                Voice_ChangStation();
            }
            iChange[9] = 1;
            iChange[10] = 0;
        }
        Label_SD->clear();
    }
    iCount_icon1=true;
}


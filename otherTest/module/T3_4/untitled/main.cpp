#include <iostream>
using namespace std;
int main() {
    long long qq=330821199502130001;
    for (int i = 1; i <= 168; ++i) {
        if(i<10){

            std::cout <<"00";
        }else if(i<100){
            std::cout <<"0";
        }
        std::cout <<i<< std::endl;
    }
    return 0;
}

{

static bool isReadOK = false;
void PctGuiThread::ReadScanStation() {
    static bool isRead0OK = false;
    static int iRead_1_ok = 0;
    static bool isReadComData = false;
    static bool isReadEND_OK = false;
    static QByteArray Scan1Data;
    if (isReadComData) {//执行中
        return;
    }
    isReadComData = true;
    if (isReadEND_OK) {//最后
        qDebug() << "========= Read Data 2OK";
        QByteArray Station = AglDeviceP->agl_rd_data(0x0D, 0);
        if ("2OK" == (QString) Station.data()) {
            qDebug() << "<><><><><><> Read Data 2OK Over";
            if (!HandleScanOK(Scan1Data)) {//检查是否匹配
                isReadComData = false;
//                isReadOK = false;
                isRead0OK = false;
                isReadEND_OK = false;

                isBarCodeGetOK = false;
                isClickedCloseDoor = false;//检查门是否关闭
                isGetBarCodeDataError = true;

                iRead_1_ok = 0;//循环次数
                Scan1Data.clear();//清空一维码缓存
                return;
            }
            Delayms(500);
            StartTestWidget();
            isReadComData = false;
            isReadOK = false;
            isRead0OK = false;
            isReadEND_OK = false;
            iRead_1_ok = 0;
            Scan1Data.clear();
        }
        isReadComData = false;
    } else {
        if (false == isReadOK) {
            qDebug() << "======Reader OK";
            static int IError = 0;
            QByteArray Station = AglDeviceP->agl_rd_data(0x05, 0);
            if ("OK" == (QString) Station.data() || isBarCodeGetOK == true) {//仓门关闭或
                qDebug() << "<><><><><><> Read Data OK Over";
                isReadOK = true;
                IError = 0;
                emit LocationOK();
            }
            if (60 == IError) {
                isGetBarCodeDataError = true;
                IError = 0;
                Voice_ScanError();
                delete msgBox;
                if (isWidget == false) {
                    Voice_pressKey();
                }

                LCD_time->stop();
                disconnect(LCD_time, SIGNAL(timeout()), this, SLOT(LCDtimer()));
                delete LCD_time;
                KeyInput.clear();
                SamEdit->clear();
                KeyInput.clear();
                SamEdit->clear();
                if (UiType == LotKeyui) {
                    CardKeyWidget->close();
                }
                TestWidget->close();
                QString main = AglDeviceP->GetConfig("station_Main");
                Label_station->setText(main);
                UiType = MainUi;
                isClicked = false;
                isGetBarCodeDataError = false;
                isClickedCloseDoor = false;

                isStart = false;
                isNext = false;
                isMessage = false;
                if (isTimer_CodeStart) {
                    qDebug() << "225 Stop Timer";
                    Timer_ScanLOT->stop();
                    isTimer_CodeStart = false;
                }
                isReadComData = false;
                return;
            }
            IError++;
            isReadComData = false;
            return;
        }
        if (false == isRead0OK) {
            qDebug() << "======Reader 0OK";
            QByteArray Station = AglDeviceP->agl_rd_data(0x0D, 0);
            if ("0OK" == (QString) Station.data()) {
                qDebug() << "<><><><><><> Read Data 0OK Over";
                bool iRet = AglDeviceP->Scan1D_Code(Scan1Data);//获取二维码数据
                if (false == iRet || Scan1Data.length() == 0) {//二维码获取失败或长度为0
                    emit Move_Motor();
                    iRead_1_ok++;
                } else       // 扫描成功
                {
                    char CmdBuf[16] = {0x55, 0x55, '&', 'A', 'G', 'L', 0x0D, 0x00, 0x01, 0x02, 0xff, 0xff, '\n', 0x55,
                                       0x55};
                    //--------------------------------//
                    if (!AglDeviceP->agl_wr_data(CmdBuf, 16)) {
                        qDebug() << "Write BUF ERROR";
                        return;
                    }
                    isReadEND_OK = true;
                }
                isRead0OK = true;
            }
            isReadComData = false;
            return;
        }
        if (true == isReadOK && true == isRead0OK) {
            qDebug() << "======Reader 1OK";
            QByteArray Station = AglDeviceP->agl_rd_data(0x0D, 0);
            if ("1OK" == (QString) Station.data()) {
                qDebug() << "<><><><><><> Read Data 1OK Over";
                bool iRet = AglDeviceP->Scan1D_Code(Scan1Data);
                if (iRead_1_ok > 10) {//循环读取10次
                    if (isTimer_CodeStart) {
                        qDebug() << "274 Stop Timer";
                        Timer_ScanLOT->stop();
                        isTimer_CodeStart = false;
                    }
                    isReadComData = false;
                    isReadOK = false;
                    isRead0OK = false;
                    isReadEND_OK = false;
                    iRead_1_ok = 0;
                    Scan1Data.clear();
                    HandleScanError();
                    return;
                }
                if (false == iRet || Scan1Data.length() == 0) {
                    emit Move_Motor();
                    iRead_1_ok++;
                } else       // 扫描成功
                {
                    char CmdBuf[16] = {0x55, 0x55, '&', 'A', 'G', 'L', 0x0D, 0x00, 0x01, 0x02, 0xff, 0xff, '\n', 0x55,
                                       0x55};
                    //--------------------------------//
                    if (!AglDeviceP->agl_wr_data(CmdBuf, 16)) {
                        qDebug() << "Write BUF ERROR";
                        return;
                    }
                    isReadEND_OK = true;
                }
            }
        }
        isReadComData = false;
    }
}


}
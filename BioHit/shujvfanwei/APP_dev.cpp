//
// Created by necromaner on 2019-04-12.
//

#include "APP_dev.h"
#include "app_dev.h"
#include "ui_app_dev.h"

bool APP_dev::ReloadPassConfig()// 将新的文件内容（已经保存在文件中）加载值链表
{
    PasswdList->clear();
    QFile MessageFile("./password.txt");
    if (!MessageFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return false;
    }
    while(!MessageFile.atEnd())
    {
        QString lineString=QString(MessageFile.readLine());
        if(lineString.left(1) == "#")
        {
            continue;
        }
        QStringList StrTxt = lineString.split("#");
        lineString = StrTxt.at(0);
        StrTxt = lineString.split("=");
        *PasswdList +=StrTxt;
    }
    MessageFile.close();
    return true;
}
bool APP_dev::ReloadPasswdFile(QString FileData)// 将修改后的Passwd文件的内容（还未保存至文件）加载到链表
{
    if(FileData.isEmpty())
    {
        return false;
    }
    QStringList ListTemp = FileData.split("#\r\n");
    int FileLengh = ListTemp.length();
    if(FileLengh == 1)
    {
        return false;
    }
    PasswdList->clear();
    QString StrTemp;
    QStringList ListLoad;
    QStringList ListBuf;
    for(int i = 0; i < FileLengh - 1; i++)
    {
        StrTemp = ListTemp.at(i);
        ListLoad = StrTemp.split("=");
        ListBuf.append(ListLoad.at(0));
        ListBuf.append(ListLoad.at(1));
    }
    *PasswdList = ListBuf;
    return true;
}
bool APP_dev::LoadPasswdFile()
{
    PasswdList = new  QStringList();
    PasswdList->clear();
    QFile MessageFile("./password.txt");
    if (!MessageFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return false;
    }
    while(!MessageFile.atEnd())
    {
        QString lineString=QString(MessageFile.readLine());
        if(lineString.left(1) == "#")
        {
            continue;
        }
        QStringList StrTxt = lineString.split("#");
        lineString = StrTxt.at(0);
        StrTxt = lineString.split("=");
        *PasswdList += StrTxt;
    }
    MessageFile.close();
    return true;
}
bool APP_dev::ReWriteFile(QString Key, QString Data)// 将新的内容写入文件链表
{
    Key = "@"+Key;
    QStringList List_Temp;
    List_Temp.clear();
    int iLengh = PasswdList->length();
    qDebug() << "iLengh is " << iLengh;

    if(0 == iLengh)
    {
        return false;
    }
    for(int i = 0; i < iLengh - 1; i+=2)
    {
        if(PasswdList->at(i) == Key)
        {
            List_Temp.append(Key);
            List_Temp.append(Data);
            continue;
        }
        List_Temp.append(PasswdList->at(i));
        List_Temp.append(PasswdList->at(i+1));
    }
    PasswdList->clear();
    *PasswdList = List_Temp;
    return true;
}
QString APP_dev::GetPasswd(QString key)
{
    for(int i=0;i<PasswdList->size();i++)
    {
        if(key==PasswdList->at(i))
        {
            QString Txt=PasswdList->at(i+1);
            if(Txt.length()>0)
            {
                return Txt;
            }
            else
            {
                return "No";
            }
        }
    }
    return "No";
}
QStringList APP_dev::GetAllUserData()   // 获得password.txt配置文件的用户内容
{
    QStringList RetList;
    QString RetStr;
    for(int i = 0; i < PasswdList->length()-1; i+=2)
    {
        if(PasswdList->at(i).left(1) != "@")
        {
            RetStr = PasswdList->at(i) + "=" + PasswdList->at(i+1);
            RetList.append(RetStr);
        }
    }
    RetList.append(" ");
    return RetList;
}
QString APP_dev::GetAllPass()       // 获得password.txt配置文件的所有内容
{
    QString LineData;
    QString AllData;
    for(int i = 0; i < PasswdList->length() - 1; i+=2)
    {
        LineData = PasswdList->at(i) + "=" + PasswdList->at(i+1) + "#\r\n";
        AllData += LineData;
    }
    return AllData;
}
QString APP_dev::GetAllParadata()  // 获得password.txt配置文件除用户之外的内容
{
    QString LineData;
    QString AllData;
    for(int i = 0; i < PasswdList->length()-1; i+=2)
    {
        if(PasswdList->at(i).left(1) == "@")
        {
            LineData = PasswdList->at(i) + "=" + PasswdList->at(i+1) + "#\r\n";
            AllData += LineData;
        }
    }
    return AllData;
}

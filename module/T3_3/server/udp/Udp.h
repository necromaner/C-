//
// Created by necromaner on 2018/12/10.
//

#ifndef CLIENT_UDP_H
#define CLIENT_UDP_H
//#include <sys/types.h>
#include <sys/socket.h>
//#include <stdio.h>
#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <cstring>
//#include <cstdlib>
#include <zconf.h>                                         //close()
#include <string>       //string
#include <map>//map
#include <set>//set
#include "../other/Other.h"

#include "gtest/gtest_prod.h"//测试用例私有

#define         ADDRESS      "127.0.0.1"
#define         PORT         8888

#define         MAX_SEND     100
#define         NUM_BLOCK    50
#define         MAX_BLOCK    (MAX_SEND*NUM_BLOCK)
#define         NUM_OTHER    1000
#define         MAX_SEND_MAX (MAX_SEND+NUM_OTHER)
#define         MAX_RESEND   100

struct FileInformation{                                    //文件
    std::string name;                                      //文件名
    long long   size;                                      //文件大小
    int         block;                                     //文件块大小
    int         send;                                      //文件发送大小
};
struct Data{                                               //传输
    long long   num;                                       //序号
    char        buf[MAX_SEND];                             //数据
    std::string md5;                                       //数据的md5值
};
class Udp {
private:
    ////--------------------udp----------------------////
    int ss;
    std::string file1="";
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);
    ////------------------数据传输--------------------////
    char *buf = new char[MAX_SEND_MAX];                    //发送/接收的数据
    char *block = new char[MAX_BLOCK];                     //块数据
    Other other;
    File file;
    ////-------------------other--------------------////
    bool test = false;                                     //是否为测试

private:
    void Message();
    void Message(char *message);
public:
    Udp();                                                 //构造函数
    virtual ~Udp();                                        //析构函数
    void udpStart();                                       //启动udp
    void setFile(const std::string &file1);                //设置发送文件路径
    FileInformation Information();                         //发送文件信息
    void receiveFile();                                    //接收文件
    void show() const;                                     //显示文件信息
    void show(Data data);                                  //显示传输信息
};


#endif //CLIENT_UDP_H

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
#include <iostream>
#include "../other/Other.h"

#include "gtest/gtest_prod.h"//测试用例私有
#define         ADDRESS      "127.0.0.1"
#define         PORT         8888

#define         MAX_SEND     100                          //发送文件大小
#define         NUM_BLOCK    50                            //块分割数量
#define         MAX_BLOCK    (MAX_SEND*NUM_BLOCK)          //块大小
#define         NUM_OTHER    1000                          //发送其他信息
#define         MAX_SEND_MAX (MAX_SEND+NUM_OTHER)          //发送大小
#define         RESIVE       3
#define         CUT1         '|'
#define         CUT2         ','
#define         CUT3         '-'
enum Flag{
    INFDS,//文件信息数据结构
    blockdata,//
    fileEnd,
    error
};
struct FileInformation{                                    //文件
    std::string name;                                      //文件名
    long long   size;                                      //文件大小
    int         block;                                     //文件块大小
    int         send;                                      //文件发送大小
};
struct Data{                                               //传输
    Flag        flag;                                      //发送类型  1 文件 2回传
    long long   block_Num;                                 //块序号
    int         send_Num;                                  //发送序号
    char        buf[MAX_SEND];                             //数据
    std::string md5;                                       //数据的md5值
};
class Udp {
private:
    ////--------------------udp----------------------////
    int ss;
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);
    bool isEnd;                                            //是否接收完成
    ////------------------数据传输--------------------////
    char *buf = new char[MAX_SEND_MAX];                    //发送/接收的数据
    char *block = new char[MAX_BLOCK];                     //块数据
    std::map<int,bool[NUM_BLOCK]> maps;
    Other other;
    File file;
    ////------------------文件序号--------------------////
    std::map<int,std::string> mapRe;                       //接收区
    std::map<int,std::string> mapWhit;                     //等待区
    std::map<int,std::set<int>> mapNow;                    //发送区
    bool statusRe;                                         //是否在接收文件
    bool statusNow;                                        //是否在发送文件
    ////-------------------other--------------------////
    bool test = false;                                     //是否为测试
    std::vector<int> qwer;                                 //已经发送过的序号
    void Message();
    void Message(char *message);
    void Message(char *message, unsigned long length);
public:
    Udp();                                                 //构造函数
    virtual ~Udp();                                        //析构函数
    void setFile(const std::string &file1);                //设置发送文件路径
    void udpStart();                                       //启动udp
    void input_Thread();                                   //接收信息线程
    void RE_Thread();                                      //序号区域传递线程
    void Send_Thread();                                    //发送文件线程
private:
    bool File_Information();                               //发送文件信息
    void show() const;                                     //显示文件信息
    void input_Name(const std::string &file22);            //接收文件名
    bool input_RE(long long block_Num,char *bufs);         //接收序号
};


#endif //CLIENT_UDP_H

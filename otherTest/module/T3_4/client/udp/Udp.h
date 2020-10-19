//
// Created by necromaner on 2018/12/10.
//

#ifndef CLIENT_UDP_H
#define CLIENT_UDP_H
#include <sys/types.h>
#include <sys/socket.h>//socket
#include <stdio.h>
#include <netinet/in.h>//server_addr
#include <arpa/inet.h>//inet_addr()
#include <iostream>
#include <thread>
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
#define         ZERO         0                        //零
#define         FLAG_END     "end"
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
    Flag        flag;                                      //发送类型  1 文件 2回传 3结束
    long long   block_Num;                                 //块序号
    int         send_Num;                                  //发送序号
    char        buf[MAX_SEND];                             //数据
    std::string md5;                                       //数据的md5值
};
struct RE {                                                //正在接收的块
    long long int num[RESIVE];                             //块序号
    bool isnum[RESIVE];                                    //是否完成
    std::set<int> data[RESIVE];                            //分割序号
    std::map<int,char[MAX_SEND]> maps[RESIVE];
};
class Udp {
private:
    ////--------------------udp----------------------////
    int ss;
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);
    ////------------------数据传输--------------------////
    char *buf = new char[MAX_SEND_MAX];                    //发送/接收的数据
    char *block = new char[MAX_BLOCK];                     //块数据
    std::set<int> block_No;                                //需要接收的序号
    Other other;
    File file;
    RE re;
    char (*blocks)[MAX_SEND]=new char[NUM_BLOCK][MAX_SEND];
    ////-------------------other--------------------////
    bool test = false;                                     //是否为测试
    std::set<int> qwer;                                    //接收成功的序号
    int tttt;
private:
    void Message();
    void Message(char *message);
    void Message(char *message, unsigned long length);
public:
    Udp();                                                 //构造函数
    virtual ~Udp();                                        //析构函数
    void setFile(const std::string &file1);                //设置发送文件路径
    void udpStart();                                       //启动udp
    void fileName(const std::string& name);                //发送文件名
    bool File_Information();                               //接收文件信息
    void show() const;                                     //显示文件信息
    void thread_Main();

    void setBlock_No();
    std::set<int> setSet_int(long long int num);
    void eraseBlock_No(long long int num);

    std::set<int> getNowBlock(int num);

    bool setRE();//添加RE
    void sendRE();
    std::vector<std::string> stringVector_SIZE(std::string s);

    void receiveData();
};


#endif //CLIENT_UDP_H

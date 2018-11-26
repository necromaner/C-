#ifndef SERVER_UDPSERVER_H
#define SERVER_UDPSERVER_H
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <zconf.h>//close()
#include <cstring>
#include <arpa/inet.h>
#include <string>
#include <map>
#include "gtest/gtest_prod.h"

#define         PORT         8888
#define         MAX_SEND     8000
#define         MAX_BLOCK    MAX_SEND*97
#define         MAX_SEND_MAX MAX_SEND+1000
#define         MAX_RESEND   100
#define         BEGIN        0
#define         TIME_D       86400
#define         TIME_H       3600
#define         TIME_M       60
#define         TIME_S       1
#define         TIME_10      10
#define         SPEED_B      "B/s"
#define         SPEED_K      "K/s"
#define         SPEED_M      "M/s"
#define         SPEED_G      "G/s"
#define         SPEED_T      "T/s"
#define         SPEED_P      "P/s"
#define         SPEED_E      "E/s"
#define         SPEED        1024
#define         FINISH_FLAG  "FILE_TRANSPORT_FINISH"
#define         CORRECT_FLAG "FILE_TRANSPORT_CORRECT"
#define         AFFIRM_FLAG  "AFFIRM_TRANSPORT_FINISH"
struct FileInformation{
    std::string name;                        //文件名
    long long   size;                        //文件大小
    int         block;                       //文件块大小
    int         send;                        //文件发送大小
};
struct Data{
    char        buf[MAX_SEND];               //文件数据
    int         num;                         //块序号
    std::string md5;                         //块的md5值
};

class UdpServer {
private:
    int ss;
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);

    bool test=false;                          //是否为测试

    std::map<int,std::map<int,int>> xx;       //文件中未成功接收的块

    long long receiveMAX=BEGIN;               //总共接收次数
    time_t tt;                                //开始时间

    char* buf   = new char[MAX_SEND];         //接收的数据
    char* block = new char[MAX_BLOCK];        //接收的块
//    char* block1 = new char[MAX_BLOCK];       //接收的块1
//    char* block2 = new char[MAX_BLOCK];       //接收的块2
    std::map<int, int> x;                     //每块中未成功接收的序号
//    std::map<int, int> x1;                     //每块中未成功接收的序号
//    std::map<int, int> x2;                     //每块中未成功接收的序号
    /*
     * 发送端：
     * 判断x是否为空，如果为空则读取文件发送新的块
     * 判断x1是否为空，如果为空则读取文件发送新的块
     * 判断x2是否为空，如果为空则读取文件发送新的块
     *
     */

    FileInformation fl;                       //文件信息
    std::string file1="/Users/necromaner/test/receive/";
    inline std::string file(){ return file1+fl.name;}
    inline long long MAX_Block_Num(){ if(this->fl.size%this->fl.block==0){ return this->fl.size/this->fl.block; } else{ return this->fl.size/this->fl.block+1; };}
    inline int END_Buf_Size(){ return (int)((this->fl.size%this->fl.block)%this->fl.send);}
    inline int MIN_Buf_Num(){ if(((this->fl.size%this->fl.block)%this->fl.send)==0)return (int)((this->fl.size%this->fl.block)/this->fl.send); else return (int)((this->fl.size%this->fl.block)/this->fl.send)+1;}
    bool Clean();                             //释放内存清空数据
    void end();                               //结束输出信息
    std::string times(int s);                 //用时
    std::string speed(long long s,int d);     //传输速度
    std::string speed(long long s,int d,int num);   //传输速度

    FILE *fp;

    FRIEND_TEST(private, test0);              //private测试

public:
    UdpServer();                              //构造函数
    virtual ~UdpServer();                     //析构函数
    void udpStart();                          //启动udp
    char *Message();                          //接收消息
    char *Message(char *message);             //发送消息
    int sendFLAG(char* flag);                 //发送命令
    int receiveFLAG();                        //接收命令
    int FLAG(char* buf);                      //命令解析

    FileInformation Information();            //发送文件信息
    void receiveFile();                       //接收文件
    void receiveBlock(int num);               //接收数据块
    Data receiveBuf();                        //接收数据
    void writeBuf(int num,Data data);         //写入文件

    std::map<int,int> initialization(long long num,long long is);
    bool sendX();                            //发送未成功接收序号

    char *getBlock() const;
    char *getBuf() const;
    const FileInformation &getFl() const;
    void show() const;                        //显示文件信息
    void show(Data data);                     //显示传输信息

    std::string map_To_String(std::map<int,int> x);//map序列化

    void TEXT_Receive(int min,int max);
};

#endif //SERVER_UDPSERVER_H

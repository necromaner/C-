#ifndef CLIENT_UDPCLIENT_H
#define CLIENT_UDPCLIENT_H
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdlib>
#include <zconf.h>                                         //close()
#include <string>
#include <map>
#include <set>
#include <sys/time.h>                                      //时间
#include "gtest/gtest_prod.h"

#define         ADDRESS      "127.0.0.1"
#define         PORT         8888

#define         MAX_SEND     8000
#define         NUM_BLOCK    50
#define         MAX_BLOCK    (MAX_SEND*NUM_BLOCK)
#define         NUM_OTHER    1000
#define         MAX_SEND_MAX (MAX_SEND+NUM_OTHER)
#define         MAX_RESEND   100
#define         BEGIN        0
#define         CUT          " "

#define         TIME_D       86400000
#define         TIME_H       3600000
#define         TIME_M       60000
#define         TIME_S       1000
#define         TIME_MS      1
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

enum TrafficLight{RED,YELLOR,GREEN};
struct FileInformation{                                    //文件
    std::string name;                                      //文件名
    long long   size;                                      //文件大小
    int         block;                                     //文件块大小
    int         send;                                      //文件发送大小
};
struct Data{                                               //传输
    int         num;                                       //序号
    char        buf[MAX_SEND];                             //数据
    std::string md5;                                       //数据的md5值
};

class UdpClient {
private:
    ////--------------------udp----------------------////
    int ss;
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);
    ////------------------数据传输--------------------////
    char *buf = new char[MAX_SEND];                        //发送/接收的数据
    char *block = new char[MAX_BLOCK];                     //块数据
    std::set<int> y;                                       //需要发送的序号
    std::map<int, std::set<int>> yy;                       //所有需要发送的序号
    ////------------------统计信息--------------------////
    long long SR_NUM = BEGIN;                              //总共收/发数据次数
    time_t tt;                                             //开始时间
    ////------------------文件操作--------------------////
    FILE *fp;                                              //文件
    FileInformation fl;                                    //文件信息
    std::string file1 = "";                                //文件路径
    std::string file2 = "";                                //文件名
    ////-------------------other--------------------////
    bool test = false;                                     //是否为测试
    ////---------------------------------------------////
private:
    ////------------------内联函数--------------------////
    std::string file();                                    //合并路径和文件名
    long long MAX_Block_Num();                             //需要发送的块总数量
    int MAX_endbuf();                                      //最后一个数据的大小
    int MIN_Buf_Num();                                     //最后一个块中最小的序号
    long long serial();                                    //分割块数
    ////------------------清空数据--------------------////
    void Clean_Set_Y();                                    //清空set<int> y中元素
    void Clean_buf();                                      //清空buf
    void Clean_block();                                    //清空block
    ////------------------析构函数--------------------////
    bool Clean();                                          //释放内存清空数据
    void end();                                            //结束输出信息
    int64_t getCurrentTime();                              //获取毫秒级时间戳
    std::string times(long long s);                        //用时
    std::string speed(long long s, long long d);           //传输速度
    std::string speed(long long s, long long d, int num);  //传输速度

    ////------------------信息传输--------------------////
    char *Message();                                       //接收消息
    char *Message(char *message);                          //发送消息
    int sendFLAG(char *flag);                              //发送命令
    int receiveFLAG();                                     //接收命令
    int FLAG(char *buf);                                   //命令解析
    ////------------------文件收发--------------------////
    long long file_size(std::string filename);             //文件大小
    void sendBlock(int num);                               //发送数据块
    char *readFile(int num);                               //读取文件
    Data sendBuf(int num);                                 //发送数据
    std::set<int> initialization_set(long long num, long long is);//块序号初始化
    bool receiveY();                                       //接收未成功发送序号
    Data receiveBuf();                                     //接收数据

    std::set<int> string_To_Set(const std::string &str, const std::string &delim);//set反序列化
    ////-------------------gtest--------------------////
    FRIEND_TEST(private, test0);                           //private测试
public:
    ////-------------------test---------------------////
    void show() const;                                     //显示文件信息
    void show(Data data);                                  //显示传输信息
    void setFile1(const std::string &file1);               //设置文件路径

    void setFile2(const std::string &file2);               //设置文件名

    void setFl(const std::string &name, long long size, int block, int send);//设置文件传输信息

    void TEXT_Send(int min, int max);                      //测试传输

    char *getBlock() const;                                //得到块的内容
    char *getBuf() const;                                  //得到发送数据内容
    const FileInformation &getFl() const;                  //得到文件信息
    void Clean_test();                                     //清空信息

public:
    UdpClient();                                           //构造函数
    virtual ~UdpClient();                                  //析构函数
    void udpStart();                                       //启动udp
    void setFile(const std::string &file1, const std::string &file2);//设置发送文件路径及文件
    FileInformation Information();                         //发送文件信息
    void sendFile();                                       //发送文件
};

#endif                                                     //CLIENT_UDPCLIENT_H

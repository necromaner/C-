#ifndef CLIENT_UDPCLIENT_H
#define CLIENT_UDPCLIENT_H
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdlib>
#include <zconf.h>//close()
#include <string>
#include <map>

#define         ADDRESS      "127.0.0.1"
#define         PORT         8888
#define         MAX_SEND     8000
#define         MAX_BLOCK    MAX_SEND*97
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
enum TrafficLight{RED,YELLOR,GREEN};
struct FileInformation{
    std::string name;                         //文件名
    long long   size;                         //文件大小
    int         block;                        //文件块大小
    int         send;                         //文件发送大小
};
struct Data{
    char        buf[MAX_SEND];                //文件数据
    int         num;                          //块序号
    std::string md5;                          //块的md5值
};
class UdpClient {
private:
    int ss;
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);

    std::map<int, int> x;                     //每块中需要发送的序号
    std::map<int,std::map<int,int>> xx;       //文件中需要发送的块

    long long sendMAX=BEGIN;                  //总共发送次数
    time_t tt;                                //开始时间
    
    char* buf = new char[MAX_SEND];           //发送的数据
    char* block = new char[MAX_BLOCK];        //读取的块
//    char* block1 = new char[MAX_BLOCK];       //读取的块1

    FileInformation fl;                       //文件信息
    std::string file1="";                     //文件路径
    std::string file2="";                     //文件名
    long long file_size(std::string filename);//文件大小
    inline std::string file(){ return file1+file2;}
    inline long long serial(){ if(this->fl.size%this->fl.block==0){ return this->fl.size/this->fl.block; } else{ return this->fl.size/this->fl.block+1; };}
    inline int MAX_endbuf(){ return (int)((this->fl.size%this->fl.block)%this->fl.send);}

    bool Clean();                             //释放内存清空数据
    void end();                               //结束输出信息
    std::string times(int s);                 //用时
    std::string speed(long long s,int d,int num);   //传输速度
public:
    UdpClient();                              //构造函数
    virtual ~UdpClient();                     //析构函数
    char *Message();                          //接收消息
    char *Message(char *message);             //发送消息
    int sendFLAG(char* flag);                 //发送命令
    int receiveFLAG();                        //接收命令
    int FLAG(char* buf);                      //命令解析


    FileInformation Information();            //发送文件信息
    void sendFile();                          //发送文件
    void sendBlock(int num);                  //发送数据块
    char *readFile(int num);                  //读取文件
    Data sendBuf(int num);                    //发送数据

    std::map<int,int> initialization(long long num,long long is);
    bool receiveX();//接收未成功发送序号

    void setFile(const std::string &file1,const std::string &file2);//设置发送文件路径及文件
    char *getBlock() const;                   //得到块的内容
    char *getBuf() const;                     //得到发送数据内容
    const FileInformation &getFl() const;     //得到文件信息
    void show() const;                        //显示文件信息
    void show(Data data);                     //显示传输信息


    void TEXT_Send(int min,int max);
};

#endif //CLIENT_UDPCLIENT_H

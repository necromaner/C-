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
//#include <vector>
using namespace std;

#define         PORT         8888
#define         MAX_BLOCK    1000
#define         MAX_SEND     100
struct FileInformation{
    string      name;                   //文件名
    long long   size;                   //文件大小
    int         block;                  //文件块大小
    int         send;                   //文件发送大小
};
struct Data{
    char        buf[MAX_SEND];          //文件数据
    int         num;                    //块序号
    string      md5;                    //块的md5值
};

class UdpServer {
private:
    int ss;
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);
    
    char* buf = new char[MAX_SEND];      //发送的数据
    char* block = new char[MAX_BLOCK];   //读取的块
    
    
    FileInformation fl;                  //文件信息
    string file1="/Users/necromaner/test/receive/";
    inline string file(){ return file1+fl.name;}
    inline int serial(){ return (int)(fl.size/MAX_BLOCK+1);}
public:
    UdpServer();                        //构造函数
    virtual ~UdpServer();               //析构函数
    char *Message();                    //接收消息
    char *Message(char *message);       //发送消息
    FileInformation Information();      //发送文件信息
    
    
    Data receiveFile();                 //接收数据
    char *manage(int num);
    char *writeFile(int num);           //写入文件
    
    
    
    
    
    char *getBlock() const;
    
    char *getBuf() const;
    const FileInformation &getFl() const;
    void show() const;                   //显示文件信息
    void show(Data data);                //显示传输信息
};


#endif //SERVER_UDPSERVER_H

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

#define         PORT         8888
#define         MAX_BLOCK    1000
#define         MAX_SEND     100
#define         FINISH_FLAG  "FILE_TRANSPORT_FINISH"
#define         CORRECT_FLAG "FILE_TRANSPORT_CORRECT"
#define         AFFIRM_FLAG  "AFFIRM_TRANSPORT_FINISH"
struct FileInformation{
    std::string      name;                   //文件名
    long long   size;                   //文件大小
    int         block;                  //文件块大小
    int         send;                   //文件发送大小
};
struct Data{
    char        buf[MAX_SEND];          //文件数据
    int         num;                    //块序号
    std::string      md5;               //块的md5值
};

class UdpServer {
private:
    int ss;
    std::map<int, int> x;                //发送序号
    long long receiveMAX=0;              //总共接收次数
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);
    
    char* buf = new char[MAX_SEND];      //读取的数据
    char* block = new char[MAX_BLOCK];   //读取的块
    
    
    FileInformation fl;                  //文件信息
    std::string file1="/Users/necromaner/test/receive/";
    inline std::string file(){ return file1+fl.name;}
    inline int serial(){ return (int)(fl.size/MAX_BLOCK+1);}

    FILE *fp;
public:
    UdpServer();                         //构造函数
    virtual ~UdpServer();                //析构函数
    char *Message();                     //接收消息
    char *Message(char *message);        //发送消息
    FileInformation Information();       //发送文件信息
    

    char *manage(int num);               //
    char *writeFile(int num);            //写入文件


    char *sendFLAG(char* flag);          //发送命令
    char *receiveFLAG();                 //接收命令

    Data receiveBuf();                   //接收数据
    void receiveBlock(int num);
    void receiveFile();
    std::map<int,int> initialization(long long num,long long is);
    char *getBlock() const;
    
    char *getBuf() const;
    const FileInformation &getFl() const;
    void show() const;                   //显示文件信息
    void show(Data data);                //显示传输信息
    void writeBuf(int num,Data data);    //写入
};


#endif //SERVER_UDPSERVER_H

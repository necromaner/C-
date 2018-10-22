//
// Created by 温亚奇 on 2018/10/21.
//

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

using namespace std;

#define         PORT         8888
#define         MAX_BLOCK    10000
#define         MAX_SEND     1000

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
    FileInformation fl;
public:
    UdpServer();                //构造函数
    virtual ~UdpServer();       //析构函数
    char *Message();
    char *Message(char *message);
    FileInformation Information();
    
    const FileInformation &getFl() const;
    void show() const;
};


#endif //SERVER_UDPSERVER_H

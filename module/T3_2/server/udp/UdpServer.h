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
    string      name;
    long        size;
    int         max;
};
struct Data{
    char        buf[MAX_SEND];
    int         num;
    string      md5;
};
class UdpServer {
private:
    int ss;
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);
    FileInformation Information;
public:
    UdpServer();                //构造函数
    virtual ~UdpServer();       //析构函数
    string Message();
    string Message(char *message);
};


#endif //SERVER_UDPSERVER_H

//
// Created by 温亚奇 on 2018/10/21.
//

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
using namespace std;

#define         ADDRESS      "127.0.0.1"
#define         PORT         8888
#define         MAX_BLOCK    10000
#define         MAX_SEND     1000
enum TrafficLight{RED,YELLOR,GREEN};
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
class UdpClient {
private:
    int ss;
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);
    FileInformation fl;
    long long file_size(string filename);
public:
    UdpClient();                       //构造函数
    virtual ~UdpClient();              //析构函数
    char *Message();                   //接收消息
    char *Message(char *message);      //发送消息
    FileInformation Information(string file1,string file2);
    const FileInformation &getFl() const;
    void show() const;
};


#endif //CLIENT_UDPCLIENT_H

#ifndef SERVER_UDPSERVER_H
#define SERVER_UDPSERVER_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
using std::string;
#define    PORT           8888
#define    FINISH_FLAG    "FILE_TRANSPORT_FINISH"
#define    CORRECT_FLAG    "FILE_TRANSPORT_CORRECT"
#define    AFFIRM_FLAG    "AFFIRM_TRANSPORT_FINISH"
struct sockaddr_in server_addr;
static int ss;
struct FileInformation{
    string name;//文件名
    long long size;//文件大小
    int block;//块大小
    int max;//每次发送大小
};
struct Data{
    char buf[984];
    int num1;
    int num2;
    string md5;
};


#endif //SERVER_UDPSERVER_H

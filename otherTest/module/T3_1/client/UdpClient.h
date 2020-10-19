//
// Created by 温亚奇 on 2018/10/12.
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
#include <string>
using namespace std;
#define    PORT           8888
#define    FINISH_FLAG    "FILE_TRANSPORT_FINISH"
#define    CORRECT_FLAG    "FILE_TRANSPORT_CORRECT"
#define    AFFIRM_FLAG    "AFFIRM_TRANSPORT_FINISH"
struct sockaddr_in server_addr;
static int sc;
struct FileInformation{
    string name;//文件名
    long long size;//文件大小
    int block;//块大小
    int max;//每次发送大小
};
struct Data{
    char buf[984];
    int num1;//读取块序号
    int num2;//发送块序号
    string md5;
};

#endif //CLIENT_UDPCLIENT_H

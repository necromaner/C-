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
class UdpClient {
private:
    int ss;
    struct sockaddr_in server_addr;
    const socklen_t len = sizeof(server_addr);
public:
    UdpClient();
    virtual ~UdpClient();
    string SendMessage(char *message);
};


#endif //CLIENT_UDPCLIENT_H

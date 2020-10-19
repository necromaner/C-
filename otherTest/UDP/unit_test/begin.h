//
// Created by 温亚奇 on 2018/10/11.
//

#ifndef UNIT_TEST_BEGIN_H
#define UNIT_TEST_BEGIN_H
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <zconf.h>
#include <cstring>
#include <vector>
#include <arpa/inet.h>
#include "Send.h"
#define    PORT           8888


using namespace std;
struct sockaddr_in server_addr;

void udpServer();

class begin {

};


#endif //UNIT_TEST_BEGIN_H

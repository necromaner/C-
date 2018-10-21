//
// Created by 温亚奇 on 2018/10/21.
//

#include "UdpClient.h"

UdpClient::UdpClient() {
/*1.socket()*/
    this->ss = socket(AF_INET, SOCK_STREAM, 0);//tcp
    printf("1.socket()\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(ADDRESS);
    
    /*2.connect()*/
    if (connect(this->ss, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) < 0) {
        printf("2.connect()-UDP连接\n");
        this->ss = socket(AF_INET, SOCK_DGRAM, 0);
    } else {
        printf("2.connect()-TCP连接\n");
    }
}

UdpClient::~UdpClient() {
    printf("------end------\n");
    close(this->ss);
}
string UdpClient::SendMessage(char *message){
    sendto(ss, message, strlen(message) + 1, 0, (struct sockaddr *) &server_addr, len);
    return message;
}
#include "UdpServer.h"

UdpServer::UdpServer() {
    printf("*------------start------------*\n");
    /*1.socket()*/
    this->ss = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    /*2.bind()*/
    if (bind(this->ss, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("*--------创建套接字失败!--------*\n");
        exit(1);
    }
}

UdpServer::~UdpServer() {
    close(this->ss);
    printf("*-------------end-------------*\n");
}
char * UdpServer::Message(){
    char buf[BUFSIZ]={0};
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
    return buf;
}
char * UdpServer::Message(char *message){
    sendto(ss, message, strlen(message) + 1, 0, (struct sockaddr *) &server_addr, len);
    return message;
}
FileInformation UdpServer::Information(){
    char buf[BUFSIZ]={0};
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
    memcpy(&this->fl,buf,sizeof(fl)+1);
    return fl;
}

const FileInformation &UdpServer::getFl() const {
    return fl;
}
void UdpServer::show() const {
    printf(" 文件信息：\n");
    printf(" name: %s\n",this->fl.name.c_str());
    printf(" size: %ld\n",this->fl.size);
    printf(" block:%d\n",this->fl.block);
    printf(" send: %d\n",this->fl.send);
    printf("*-----------------------------*\n");
}
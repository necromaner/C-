#include "UdpServer.h"

UdpServer::UdpServer() {
    /*1.socket()*/
    this->ss = socket(AF_INET, SOCK_DGRAM, 0);
    printf("1.socket()\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    
    /*2.bind()*/
    if (bind(this->ss, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        
        printf("创建套接字失败!\n");
        exit(1);
    } else
        printf("2.bind()\n");
}

UdpServer::~UdpServer() {
    close(this->ss);
    printf("------end------\n");
}
string UdpServer::Message(){
    char buf[BUFSIZ]={0};
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
    return buf;
}
string UdpServer::Message(char *message){
    sendto(ss, message, strlen(message) + 1, 0, (struct sockaddr *) &server_addr, len);
    return message;
}
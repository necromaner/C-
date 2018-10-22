//
// Created by 温亚奇 on 2018/10/21.
//

#include "UdpClient.h"

UdpClient::UdpClient() {
    printf("*------------start------------*\n");
/*1.socket()*/
    this->ss = socket(AF_INET, SOCK_DGRAM, 0);//tcp
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(ADDRESS);
    
//    /*2.connect()*/
//    if (connect(this->ss, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) < 0) {
//        printf("*            -UDP-            *\n");
//        this->ss = socket(AF_INET, SOCK_DGRAM, 0);
//    } else {
//        printf("*            -TCP-            *\n");
//    }
}

UdpClient::~UdpClient() {
    close(this->ss);
    printf("*-------------end-------------*\n");
}
char * UdpClient::Message(){
    char buf[BUFSIZ]={0};
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
    return buf;
}
char * UdpClient::Message(char *message){
    sendto(ss, message, strlen(message) + 1, 0, (struct sockaddr *) &server_addr, len);
    return message;
}
long long UdpClient::file_size(string filename) {
    FILE *fp=fopen(filename.c_str(),"r");
    if(!fp) return -1;
    fseek(fp,0L,SEEK_END);
    long size=ftell(fp);
    fclose(fp);
    return size;
}
FileInformation UdpClient::Information(string file1,string file2){
    long long x=file_size(file1+file2);
    this->fl={file2,x,BUFSIZ};
    sendto(ss,(char*)&fl,sizeof(fl)+1,0,(struct sockaddr*)&server_addr,len);
    return fl;
}

const FileInformation &UdpClient::getFl() const {
    return fl;
}

void UdpClient::show() const {
    printf(" 文件信息：\n");
    printf(" name: %s\n",this->fl.name.c_str());
    printf(" size: %ld\n",this->fl.size);
    printf(" block:%d\n",this->fl.block);
    printf(" send: %d\n",this->fl.send);
    printf("*-----------------------------*\n");
}

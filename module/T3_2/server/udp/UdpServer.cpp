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
    delete[] buf;
    delete[] block;
    printf("*-------------end-------------*\n");
}

char * UdpServer::Message(){
    bzero(buf, MAX_SEND);
    recvfrom(ss, buf, MAX_SEND, 0, (struct sockaddr *) &server_addr, &len);
    return buf;
}
char * UdpServer::Message(char *message){
    sendto(ss, message, strlen(message) + 1, 0, (struct sockaddr *) &server_addr, len);
    return message;
}
FileInformation UdpServer::Information(){
    Message();
    memcpy(&this->fl,buf,sizeof(fl)+1);
    FILE *fp;
    fp=fopen(file().c_str(),"w+");
    fclose(fp);
    return fl;
}

Data UdpServer::receiveFile(){
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
    Data data;
    memcpy(&data, buf, sizeof(data) + 1);
    return data;
}
char *UdpServer::writeFile(int num){
    FILE *fp;
    fp=fopen(file().c_str(),"rb+");
    fseek(fp, num*fl.block, SEEK_SET);
    if (num == serial()) {
        fwrite(block, sizeof(char), (size_t) fl.size % fl.block, fp);
    } else {
        fwrite(block, sizeof(char), (size_t) fl.block, fp);
    }
    fclose(fp);
    return block;
}




char *UdpServer::getBuf() const {
    return buf;
}
const FileInformation &UdpServer::getFl() const {
    return fl;
}
void UdpServer::show() const {
    printf(" 接收信息：\n");
    printf(" name: %s\n",this->fl.name.c_str());
    printf(" size: %lld\n",this->fl.size);
    printf(" block:%d\n",this->fl.block);
    printf(" send: %d\n",this->fl.send);
    printf("*-----------------------------*\n");
}
void UdpServer::show(Data data){
    printf(" 接收数据：\n");
    printf(" buf: \n%s\n",data.buf);
    printf(" num: %d\n",data.num);
    printf(" md5:%s\n",data.md5.c_str());
    printf("*-----------------------------*\n");
}
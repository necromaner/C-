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
    delete[] buf;
    delete[] block;
    printf("*-------------end-------------*\n");
}
char * UdpClient::Message(){
    bzero(buf, MAX_SEND);
    recvfrom(ss, buf, MAX_SEND, 0, (struct sockaddr *) &server_addr, &len);
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
FileInformation UdpClient::Information(){
    
    FILE *fp;
    if ((fp = fopen(file().c_str(), "r")) == NULL) {
        this->fl={"文件不存在",0,0,0};
    } else{
        this->fl={file2,file_size(file()),MAX_BLOCK,MAX_SEND};
    }
    fclose(fp);
    sendto(ss,(char*)&fl,sizeof(fl)+1,0,(struct sockaddr*)&server_addr,len);
    return fl;
}
const FileInformation &UdpClient::getFl() const {
    return fl;
}
void UdpClient::show() const {
    printf(" 发送信息：\n");
    printf(" name: %s\n",this->fl.name.c_str());
    printf(" size: %lld\n",this->fl.size);
    printf(" block:%d\n",this->fl.block);
    printf(" send: %d\n",this->fl.send);
    printf("*-----------------------------*\n");
}

char * UdpClient::readFile(int num){
    bzero(block, MAX_BLOCK);
    FILE *fp;
    fp = fopen(file().c_str(), "rb+");
    fseek(fp, num*fl.block, SEEK_SET);
    fread(block, sizeof(char), (size_t )fl.block, fp);
    fclose(fp);
    return block;
}
char * UdpClient::sendFile(int num){
    bzero(buf, MAX_SEND);
    memcpy(&suc,buf,sizeof(suc)+1);
    return buf;
}

char *UdpClient::getBlock() const {
    return block;
}

void UdpClient::setFile(const string &file1,const string &file2) {
    UdpClient::file1 = file1;
    UdpClient::file2 = file2;
}

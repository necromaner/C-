//
// Created by necromaner on 2018/12/10.
//

#include "Udp.h"
Udp::Udp() {
    test=false;
//    fl.send=0;
//    fl.size=0;
//    fl.block=0;
//    fl.name="";
}
Udp::~Udp() {
    if(test){
//        end();
//        Clean();
        printf("*-------------end-------------*\n");
    }
}
void Udp::udpStart(){
    printf("*------------start------------*\n");
    test=true;
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
void Udp::setFile(const std::string &file1){
    this->file1=file1;
}
void Udp::Message(){//接收消息
    bzero(buf, MAX_SEND_MAX);
    recvfrom(ss, buf, MAX_SEND_MAX, 0, (struct sockaddr *) &server_addr, &len);
}
void Udp::Message(char *message){//发送消息
    sendto(ss, message, strlen(message) + 1, 0, (struct sockaddr *) &server_addr, len);
}
FileInformation Udp::Information(){
    Message();
    FileInformation fl;
    memcpy(&fl,buf,sizeof(fl)+1);
    file.setFile(fl.size,fl.block,fl.send);
    file.setFileName(file1,fl.name);
//    FILE *fp;
//    fp=fopen(file().c_str(),"w+");
//    fclose(fp);
//    tt=getCurrentTime();
    return fl;
}
void Udp::show() const {
    printf("* Send information:           *\n");
    printf("* Name: %-22s*\n",file.getFile2().c_str());
    printf("* size: %-22lld*\n",file.getSize());
    printf("* Block:%-22lld*\n",file.getBlock());
    printf("* Send: %-22lld*\n",file.getSend());
    printf("*-----------------------------*\n");
//    printf("* Analysis:                   *\n");
//    if(this->fl.size%this->fl.send==0){
//        printf("* Send number:%-16lld*\n",this->fl.size/this->fl.send);
//    } else{
//        printf("* Send number:%-16lld*\n",this->fl.size/this->fl.send+1);
//    }
//    if(this->fl.size%this->fl.block==0){
//        printf("* Read number:%-16lld*\n",this->fl.size/this->fl.block);
//
//    } else{
//        printf("* Read number:%-16lld*\n",this->fl.size/this->fl.block+1);
//    }
}
void Udp::receiveFile(){

}
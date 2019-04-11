//
// Created by necromaner on 2018/12/10.
//

#include "Udp.h"
Udp::Udp() {
    test=false;
}
Udp::~Udp() {
    if(test){
//        end();
//        Clean();
        printf("*-------------end-------------*\n");
    }
}
void Udp::setFile(const std::string &file1,const std::string &file2) {
    file.setFileName(file1,file2);
}
void Udp::udpStart(){
    printf("*------------start------------*\n");
    test=true;
//    tt=getCurrentTime();
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
void Udp::Message(){//接收消息
    bzero(buf, MAX_SEND_MAX);
    recvfrom(ss, buf, MAX_SEND_MAX, 0, (struct sockaddr *) &server_addr, &len);
}
void Udp::Message(char *message){//发送消息
    sendto(ss, message, strlen(message) + 1, 0, (struct sockaddr *) &server_addr, len);
}
FileInformation Udp::Information(){//发送文件信息
    FILE *fp;
    FileInformation fl;                                    //文件信息
    if ((fp = fopen(file.getFileName().c_str(), "r")) == nullptr) {
        fl={"文件不存在",ZERO,ZERO,ZERO};
        file.setFile(ZERO,ZERO,ZERO);
    } else{
        fl={file.getFile2(),file.file_Size(),MAX_BLOCK,MAX_SEND};
        file.setFile(fl.size,fl.block,fl.send);
    }
    fclose(fp);
    sendto(ss,(char*)&fl,sizeof(fl)+1,0,(struct sockaddr*)&server_addr,len);
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

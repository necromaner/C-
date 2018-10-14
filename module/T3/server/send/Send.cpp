//
// Created by 温亚奇 on 2018/9/23.
//
#include <iostream>
#include <map>
#include "Send.h"
#include "../output/Output.h"
#include "../md5/md5.h"
// 获取文件大小
long file_size(string filename) {
    FILE *fp=fopen(filename.c_str(),"r");
    if(!fp) return -1;
    fseek(fp,0L,SEEK_END);
    long size=ftell(fp);
    fclose(fp);
    return size;
}
//发送命令
void sendFlag(int ss,sockaddr_in server_addr,char* flag) {
    char buf[BUFSIZ]={0};
    socklen_t len = sizeof(server_addr);
    strcpy(buf, flag);
    buf[strlen(buf)] = '\0';//strlen()用来计算字符串的长度
    sendto(ss, buf, strlen(buf) + 1, 0, (struct sockaddr *) &server_addr, len);
}
//接收命令
void receiveFlag(int ss,sockaddr_in server_addr){
    char buf[BUFSIZ]={0};
    socklen_t len1 = sizeof(server_addr);
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len1);
    printf("接收到：%s\n",buf);
}
//发送文件信息
FileInformation sendInformation(int ss,sockaddr_in server_addr,string file,long x,int block, int bigblock){
    FileInformation fl={file,x,block,bigblock};
    socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
    sendto(ss,(char*)&fl,sizeof(fl)+1,0,(struct sockaddr*)&server_addr,len);
    printf("发送：文件名：%s;大小：%ld字节,每次发送大小：%d字节,每大块大小：%d字节\n",fl.name.c_str(),fl.size,fl.max,fl.bigblock);
    receiveFlag(ss,server_addr);
    return fl;
}

void printMD5(const string message) {
    cout << "md5 = "<< MD5(message).toStr() << endl;
}

void sendData(int ss,sockaddr_in server_addr,map<int,bool> mymap,char *buf){
    for (auto it = mymap.begin(); it != mymap.end(); it++) {
        Data data;
//        strcpy(data.buf, it->second);
//        memcpy(data.buf,mymap[it->first],sizeof(mymap[it->first]));
        int first=it->first;
        data.num=first;
        socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
        sendto(ss,(char*)&data,sizeof(data)+1,0,(struct sockaddr*)&server_addr,len);
    }
    sendFlag(ss,server_addr,(char*)FINISH_FLAG);
}

char* bigBlock(map<int,bool> &mymap,string file,FileInformation fl,int j) {
    char *buf=new char[fl.bigblock];
    FILE *fp;
    fp = fopen(file.c_str(), "r");
    fseek(fp, j * fl.bigblock, SEEK_SET);
    fread(buf, sizeof(char), (size_t) fl.bigblock, fp);
    return buf;
}


void send(int ss,sockaddr_in server_addr,string file1,string file2,int max,int bigblock) {
    char buf[BUFSIZ];
    socklen_t len = sizeof(server_addr);
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
    printf("接收到：%s\n", buf);
    
    FILE *fp;
    string file = file1 + file2;
    long x = file_size(file);//文件大小
    if ((fp = fopen(file.c_str(), "r")) == NULL) {
        perror("打不开文件\n");
        exit(0);
    }
    fclose(fp);
    FileInformation fl = sendInformation(ss, server_addr, file2, x,max,bigblock);
    
    map<int,int> mymap;
    int j=0;
    char* buf1=bigBlock(mymap,file,fl,j);
    sendData(ss, server_addr,mymap,buf1);
    printf("传输完成-end\n");
}
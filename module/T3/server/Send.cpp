//
// Created by 温亚奇 on 2018/9/23.
//
#include <iostream>
#include <map>
#include "Send.h"
#include "Output.h"
#include "md5.h"
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
FileInformation sendInformation(int ss,sockaddr_in server_addr,string file,long x,int block){
    FileInformation fl={file,x,block};
    socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
    sendto(ss,(char*)&fl,sizeof(fl)+1,0,(struct sockaddr*)&server_addr,len);
    printf("发送：文件名：%s;大小：%ld字节,每次发送大小：%d字节\n",fl.name.c_str(),fl.size,fl.max);
    receiveFlag(ss,server_addr);
    return fl;
}

void printMD5(const string& message) {
    cout << "md5 = "
         << MD5(message).toStr() << endl;
}
void sendData(int ss,sockaddr_in server_addr,map<int,char*> mymap){
    for (auto it = mymap.begin(); it != mymap.end(); it++) {
        Data data;
        strcpy(data.buf, it->second);
        for (int i = 0; i < (int)sizeof(data.buf); ++i) {
            data.buf[i]=mymap[it->first][i];
        }
        int first=it->first;
        data.num=first;
        printf("send1 %d-",it->first);
        printMD5(data.buf);
        socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
        sendto(ss,(char*)&data,sizeof(data)+1,0,(struct sockaddr*)&server_addr,len);
    }
    sendFlag(ss,server_addr,(char*)FINISH_FLAG);
}
void sendData(int ss,sockaddr_in server_addr,string file,FileInformation fl) {
    FILE *fp;
    Data data;
    map<int,char*> mymap;
    fp = fopen(file.c_str(), "r");
    int xxs = (int) fl.size / fl.max + 1;
    for (int i = 0; i < xxs; ++i) {
        fseek(fp, i * fl.max, SEEK_SET);
        fread(data.buf, sizeof(char), (size_t) fl.max, fp);
        data.num = i;
        socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
        sendto(ss, (char *) &data, sizeof(data) + 1, 0, (struct sockaddr *) &server_addr, len);
        mymap[data.num] = data.buf;
        printf("send2 %d-",i);
        printMD5(data.buf);
    }
    sendFlag(ss, server_addr, (char *) FINISH_FLAG);
}

void block(map<int,char*> &mymap,string file,FileInformation fl) {
    FILE *fp;
    fp = fopen(file.c_str(), "r");

    int xs = (int) fl.size / fl.max + 1;
    for (int i = 0; i < xs; ++i) {
        Data data;
        data.num = i;
        fseek(fp, i * fl.max, SEEK_SET);
        fread(data.buf, sizeof(char), (size_t) fl.max, fp);
        char * buf=new char[fl.max];
        strcpy(buf, data.buf);
        mymap[data.num] = buf;
        printf("block %d-",i);
        printMD5(mymap[data.num]);
    }
    fclose(fp);
}





















void send(int ss,sockaddr_in server_addr,string file1,string file2,int max) {
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
    FileInformation fl = sendInformation(ss, server_addr, file2, x,max);
    
    map<int,char*> mymap;
    
    block(mymap,file,fl);
    
//    for (auto it=mymap.begin(); it != mymap.end(); it++)
//    {
//        printf("key:%d->%s\n",it->first,it->second);
//    }

//    sendData(ss, server_addr,file,fl);
    sendData(ss, server_addr,mymap);
    printf("传输完成-end\n");
}
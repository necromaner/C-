//
// Created by 温亚奇 on 2018/9/23.
//
#include <iostream>
#include "Send.h"
#include "../md5/md5.h"
#include "../output/Output.h"

// 获取文件大小
// filename:文件路径
// 返回值:文件大小（字节）
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
vector<vector<int>> newVector(int max,int size){
    vector<vector<int >> xx;
    int y=max/size+1;
    for (int i = 0; i < y; ++i) {
        vector<int> xs;
        for (int j = 0; j < size; ++j) {
            int z = i * size + j + 1;
            if (z <= max)
                xs.push_back(z);
            else
                xs.push_back(0);
        }
        xx.push_back(xs);
    }
    return xx;
}
//发送文件信息
//sc：UDP连接
//server_addr：连接地址
//file：发送文件名
//x:文件大小
//返回值：返回接到到的文件信息
FileInformation sendInformation(int ss,sockaddr_in server_addr,string file,long x){
    FileInformation fl={file,x,MAXSIZE};
    socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
    sendto(ss,(char*)&fl,sizeof(fl)+1,0,(struct sockaddr*)&server_addr,len);
    printf("发送：文件名：%s;大小：%ld字节,每次发送大小：%d字节\n",fl.name.c_str(),fl.size,fl.max);
    
    receiveFlag(ss,server_addr);
    return fl;
}

//发送文件数据
//sc：UDP连接
//server_addr：连接地址
//xx：为当前正确接收到的序号
//fl：为文件的信息
void sendData(int ss,sockaddr_in server_addr,FILE *fp,vector<vector<int>> xx,FileInformation fl){
    int xxs=(int)xx.size();
    for (int i = 0; i <xxs ; ++i) {
        int xxxs=(int)xx[i].size();
        for (int j = 0; j < xxxs; ++j) {
            if(xx[i][j]!=0){
                Data data;
                fseek(fp, (xx[i][j]-1)*fl.max, SEEK_SET);
                fread(data.buf, sizeof(char), (size_t )fl.max, fp);
                data.num=xx[i][j]-1;
                socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
                sendto(ss,(char*)&data,sizeof(data)+1,0,(struct sockaddr*)&server_addr,len);
            } else
                break;
        }
    }
    sendFlag(ss,server_addr,(char*)FINISH_FLAG);
}

//接收服务器端接收失败序号
//sc：UDP连接
//server_addr：连接地址
//e：判断是否传输完成
//返回值：未成功接收的二维数组
vector<vector<int>> receiveSuccess(int ss,sockaddr_in server_addr, bool& e){
    int num2=0;
    vector<vector<int>> qq;
    while (1){
        Success suc{};
        socklen_t len = sizeof(server_addr);
        
        char buf[BUFSIZ]={0};
        recvfrom(ss,buf,BUFSIZ,0,(struct sockaddr *) &server_addr,&len);
        if (strstr(buf, FINISH_FLAG) != NULL) {
            break;
        }
        if (strstr(buf, CORRECT_FLAG) != NULL) {
            e=false;
            break;
        }
        
        memcpy(&suc,buf,sizeof(suc)+1);
        for (int i = 0; i < MAXLENGTH; ++i) {
            if (suc.suc[i] != 0)
                num2++;
        }
        vector<int> x(suc.suc,suc.suc+100);
        qq.push_back(x);
    }
    sendFlag(ss,server_addr,(char*)AFFIRM_FLAG);
    return qq;
}


//发送数据
//sc：UDP连接
//server_addr：连接地址
void Send::send(int ss,sockaddr_in server_addr){
    char buf[BUFSIZ];
    socklen_t len = sizeof(server_addr);
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
    printf("接收到：%s\n",buf);
    
//    receiveFlag(ss,server_addr);
    
    FILE *fp;
    string file1="/Users/necromaner/test/send/";
    string file2="4.zip";
    string file=file1+file2;
    long x=file_size(file);//文件大小
    if ((fp = fopen(file.c_str(), "r")) == NULL) {
        perror("打不开文件\n");
        exit(0);
    }
    
    FileInformation fl=sendInformation(ss,server_addr,file2,x);
    vector<vector<int>> xx=newVector(fl.size/fl.max+1,100);
    
    bool e= true;
    while (e){
        sendData(ss,server_addr,fp,xx,fl);
        xx=receiveSuccess(ss,server_addr,e);
    }
    printf("传输完成-end\n");
    fclose(fp);
}


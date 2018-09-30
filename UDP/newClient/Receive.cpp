//
// Created by 温亚奇 on 2018/9/23.
//

#include "Receive.h"
#include "Md5.h"
#include "SHA1.h"
void sendFlag(int sc,sockaddr_in server_addr,char* flag) {
    //发送结束命令
    char buf[BUFSIZ]={0};
    socklen_t len = sizeof(server_addr);
    strcpy(buf, flag);
    buf[strlen(buf)] = '\0';//strlen()用来计算字符串的长度
    sendto(sc, buf, strlen(buf) + 1, 0, (struct sockaddr *) &server_addr, len);
}
//接收命令
void receiveFlag(int ss,sockaddr_in server_addr){
    char buf[BUFSIZ]={0};
    socklen_t len = sizeof(server_addr);
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
    printf("接收到：%s\n",buf);
}
bool check(unsigned char* old,unsigned char* chSha1) {
    for (int i = 0; i < 20; ++i) {
        if (old[i] != chSha1[i]) {
            return false;
        }
    }
    return true;
}
//接收文件数据
//sc：UDP连接
//server_addr：连接地址
//fp：写入的文件
//xx：为当前正确接收到的序号
//fl：为文件的信息
//返回值：返回当前接收文件正确信息
vector<bool> receiveData(int sc,sockaddr_in server_addr,FILE *fp,vector<bool> &xx,FileInformation fl){
    vector<int> css;
    while (1){
        socklen_t len = sizeof(server_addr);
        char recvBuf[BUFSIZ] = {0};
        recvfrom(sc, recvBuf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
        Data data;
        Md5Encode md5;
        if (strstr(recvBuf, FINISH_FLAG) != NULL) {
            break;
        }
        memcpy(&data, recvBuf, sizeof(data) + 1);
        CSHA1 sha1;
        sha1.Update((unsigned char*)data.buf,strlen(data.buf));
        sha1.Final();
        unsigned char chSha1[20] = "";
        sha1.GetHash(chSha1);
        
        if(check(data.chSha1,chSha1)){
            fseek(fp, data.num * fl.max, SEEK_SET);
            xx[data.num]=false;
            if (data.num == xx.size() - 1) {
                fwrite(data.buf, sizeof(char), (size_t )fl.size%fl.max, fp);
            } else{
                fwrite(data.buf, sizeof(char), (size_t )fl.max, fp);
            }
        }
    }
    return xx;
}

//接收文件信息
//sc：UDP连接
//server_addr：连接地址
//返回值：返回接到到的文件信息
FileInformation receiveInformation(int sc,sockaddr_in server_addr){
    socklen_t len = sizeof(server_addr);
    char recvBuf[1024]={0};
    recvfrom(sc,recvBuf,1024,0,(struct sockaddr *) &server_addr,&len);
    FileInformation fl;
    memcpy(&fl,recvBuf,sizeof(fl)+1);
    printf("接收到：文件名：%s;大小：%d字节,每次发送大小：%d字节\n",fl.name.c_str(),fl.size,fl.max);

    sendFlag(sc,server_addr,(char*)AFFIRM_FLAG);
    return fl;
}

//发送回复接收成功
//sc：UDP连接
//server_addr：连接地址
//xx1:接收正确的集合
void sendSuccess(int sc,sockaddr_in server_addr,vector<bool>& xx1,bool & e){
    Success suc;
    int q=0;
    int max2=0;
    int xs=(int)xx1.size();
    for (int i = 0; i < xs; ++i) {
        if(xx1[i]){
            suc.suc[q]=i+1;
            q++;
            max2++;
        }
        if(q==100||i==xs-1){
            for (int j = q; j<100; ++j) {
                suc.suc[j]=0;
            }
            suc.max=q;
            socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
            sendto(sc,(char*)&suc,sizeof(suc)+1,0,(struct sockaddr*)&server_addr,len);
            q=0;
        }
    }
    outPut(0,max2);
//    sendEnd(sc,server_addr,max2,e);
    if(max2==0){
        e= false;
        sendFlag(sc,server_addr,(char*)CORRECT_FLAG);
    } else
        sendFlag(sc,server_addr,(char*)FINISH_FLAG);
    
    receiveFlag(sc,server_addr);
}


//接收数据
//sc：UDP连接
//server_addr：连接地址
void receive(int sc,sockaddr_in server_addr){
    sendFlag(sc,server_addr,(char*)AFFIRM_FLAG);
    
    FileInformation fl=receiveInformation(sc,server_addr);
    FILE *fp;
    string file1="/Users/necromaner/test/receive/";
    string file2=fl.name;
    string file=file1+file2;
    fp=fopen(file.c_str(),"w+");
    fclose(fp);
    fp=fopen(file.c_str(),"rb+");
    vector<bool> xx((unsigned long)fl.size/fl.max+1, true);
    
    int complete=0;
    bool e= true;
    while (e){
        xx=receiveData(sc,server_addr,fp,xx,fl);
        sendSuccess(sc,server_addr,xx,e);
    }
    printf("传输完成-end\n");
    fclose(fp);
}
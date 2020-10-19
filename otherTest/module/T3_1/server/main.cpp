#include "UdpServer.h"
#include <gtest/gtest.h>
void sendFlag(char* flag) {
    //发送结束命令
    char buf[BUFSIZ]={0};
    socklen_t len = sizeof(server_addr);
    strcpy(buf, flag);
    buf[strlen(buf)] = '\0';//strlen()用来计算字符串的长度
    sendto(ss, buf, strlen(buf) + 1, 0, (struct sockaddr *) &server_addr, len);
}
//接收命令
void receiveFlag(){
    char buf[BUFSIZ]={0};
    socklen_t len = sizeof(server_addr);
    recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
    printf("接收到：%s\n",buf);
}
void receiveData(char *block,FileInformation fl){
    while (1) {
        socklen_t len = sizeof(server_addr);
        char recvBuf[BUFSIZ] = {0};
        recvfrom(ss, recvBuf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
        Data data;
        if (strstr(recvBuf, FINISH_FLAG) != NULL) {
            break;
        }
        memcpy(&data, recvBuf, sizeof(data) + 1);
        
//        memcpy(block+data.num*fl.max,data.buf,strlen(data.buf));
        printf("接收序号：%d---%s\n",data.num2, data.buf);
    }
}
void blockChange(char*block,FileInformation fl){
//    for (int i = 0; i < fl.block; ++i) {
//        block[i]='0';
//    }
    receiveData(block,fl);
}
void open(int i,string file,FileInformation fl){
//    char block[fl.block];
//    blockChange(block,fl);
//
//    printf("%s\n",block);
//
//    FILE *fp;
//    fp=fopen(file.c_str(),"rb+");
//
//    fseek(fp, i* fl.block, SEEK_SET);
//
//    if (i == fl.size/fl.block) {
//        fwrite(block, sizeof(char), (size_t) fl.size%fl.block, fp);
//    } else {
//        fwrite(block, sizeof(char), (size_t) fl.block, fp);
//    }
//
//    fclose(fp);

    FILE *fp;
    fp=fopen(file.c_str(),"rb+");
    
    while (1) {
        socklen_t len = sizeof(server_addr);
        char recvBuf[BUFSIZ] = {0};
        recvfrom(ss, recvBuf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
        Data data;
        if (strstr(recvBuf, FINISH_FLAG) != NULL) {
            break;
        }
        memcpy(&data, recvBuf, sizeof(data) + 1);
    
        printf("接收序号：%d---%s\n", data.num2, data.buf);
        printf("写入位置：%d\n",data.num1 * fl.block + data.num2 * fl.max);
        fseek(fp, data.num1 * fl.block + data.num2 * fl.max, SEEK_SET);
        if (data.num1 * fl.block + data.num2 * fl.max > fl.size - fl.max) {
            fwrite(data.buf, sizeof(char), (size_t) fl.size % fl.max, fp);
        } else {
            fwrite(data.buf, sizeof(char), (size_t) fl.max, fp);
        }
    }

    fclose(fp);
}

FileInformation receiveInformation(){
    socklen_t len = sizeof(server_addr);
    char recvBuf[1024]={0};
    recvfrom(ss,recvBuf,1024,0,(struct sockaddr *) &server_addr,&len);
    FileInformation fl;
    memcpy(&fl,recvBuf,sizeof(fl)+1);
    printf("发送：文件名：%s;大小：%lld字节,块大小%d,每次发送大小：%d字节\n",fl.name.c_str(),fl.size,fl.block,fl.max);
    
    sendFlag((char*)AFFIRM_FLAG);
    return fl;
}
void udp(){
    FILE *fp;
    FileInformation fl=receiveInformation();
    
    string file1="/Users/necromaner/test/receive/";
    string file2=fl.name;
    string file=file1+file2;
    fp=fopen(file.c_str(),"w+");
    fclose(fp);
    for (int i = 0; i < fl.size/fl.block+1; ++i) {
        open(i,file,fl);
    }
}
void udpServer(){
    ss = socket(AF_INET, SOCK_DGRAM, 0);
    printf("1.socket()\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    if (bind(ss, (struct sockaddr *) &server_addr, (int)sizeof(server_addr)) < 0) {
        perror("socket");
    } else
        printf("2.bind()\n");
    udp();
}

int main(int argc, char ** argv) {
    udpServer();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // 执行所有的 test case
}
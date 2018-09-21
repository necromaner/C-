#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <zconf.h>
#include <cstring>
#include "Md5.hpp"

#define    FINISH_FLAG    "FILE_TRANSPORT_FINISH"
#define    MAXLINE        1024
#define    PORT           8888

struct Data{
    char buf[30];
    int num;
    char md5[32];
};
int file_size(string filename) {
    FILE *fp=fopen(filename.c_str(),"r");
    if(!fp) return -1;
    fseek(fp,0L,SEEK_END);
    int size=ftell(fp);
    fclose(fp);
    
    return size;
}
int main() {
    /*1.socket()*/
    int ss = socket(AF_INET, SOCK_DGRAM, 0);
    printf("1.socket()\n");
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    
    /*2.bind()*/
    if (bind(ss, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        
        printf("创建套接字失败!\n");
        exit(1);
    } else
        printf("2.bind()\n");
    FILE *fp;
    /*3.recvfrom()*/
    socklen_t len = sizeof(server_addr);
    char recvBuf[100]={0};
    Data data;
    recvfrom(ss,recvBuf,1024,0,(struct sockaddr *) &server_addr,&len);
    memcpy(&data,recvBuf,sizeof(data)+1);
    printf("接收到：%s--%d--%s\n",data.buf,data.num,data.md5);
    
    
    
//    string file="/Users/necromaner/program/C-/UDP/test/send/send.txt";
//
//    if ((fp = fopen(file.c_str(), "r")) == NULL) {
//        perror("打不开文件\n");
//        exit(0);
//    } else
//        printf("-|1.打开文件\n");
//    int file1=file_size(file);
//    printf("%d\n",file1);
    
    return 0;
}
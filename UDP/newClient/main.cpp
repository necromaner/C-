#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include "Md5.hpp"

#define    FINISH_FLAG    "FILE_TRANSPORT_FINISH"
#define    MAXLINE        1024
#define    PORT           8888

struct Data{
    char buf[30];
    int num;
    char md5[32];
};

int main() {
    /*1.socket()*/
    int sc = socket(AF_INET, SOCK_STREAM, 0);//tcp
    printf("1.socket()\n");
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    /*2.connect()*/
    if (connect(sc, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) < 0) {
        printf("2.connect()-UDP连接\n");
        sc = socket(AF_INET, SOCK_DGRAM, 0);
    } else {
        printf("2.connect()-TCP连接\n");
    }
    FILE *fp;
    Data data={"Hello everybody!",1,"md5测试"};
    /*3.send()*/
    socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
    sendto(sc,(char*)&data,sizeof(data)+1,0,(struct sockaddr*)&server_addr,len);
    printf("发送：%s--%d--%s\n",data.buf,data.num,data.md5);
    
    
    
    
    
    
    
    return 0;
}
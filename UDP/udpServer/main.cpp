#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <zconf.h>
#include <cstring>

#define    FINISH_FLAG    "FILE_TRANSPORT_FINISH"
#define PORT 8888
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
    
    char buf[BUFSIZ];
    int count = 0;
    FILE *fp;
    while (1) {
        socklen_t len = sizeof(server_addr);
        /*3.recvfrom()*/
        if (recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len) <= 0) {
            printf("接收数据失败!\n");
            exit(1);
        }
        
        if (!strcmp(buf, "exit")) {
            close(ss);
            exit(1);
        }
        printf("client:%s\n", buf);
        if (!strcmp(buf, "send")) {
            if ((fp = fopen("/Users/necromaner/program/C-/UDP/test/send/send.txt.zip", "r")) == NULL) {
                perror("打开文件失败\n");
                exit(0);
            } else{
                printf("打开文件成功!\n");
            }
            fread(buf, sizeof(char), sizeof(buf), fp);
            printf("读取:%s\n", buf);
            sprintf(buf, "%d", count);  //回复client
            count++;
    
            /*4.sendto()*/
            sendto(ss, buf,sizeof(buf), 0, (struct sockaddr *) &server_addr, len);
            printf("send:%s\n", buf);
        } else {
            sprintf(buf, "已收到%d条\n", count);  //回复client
            count++;

            /*4.sendto()*/
            sendto(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, len);
            printf("send:%s\n", buf);
        }
//        sprintf(buf, "已收到%d条\n", count);  //回复client
//        count++;
//
//        /*4.sendto()*/
//        sendto(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, len);
//        printf("send:%s\n", buf);
        
        
    }
    
    /*5.close()*/
    close(ss);
    printf("5.close()\n");
    
}
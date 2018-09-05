#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <zconf.h>
#include <cstring>

#include <sys/stat.h>
int file_size2(char* filename)
{
    struct stat statbuf;
    stat(filename,&statbuf);
    int size=statbuf.st_size;
    
    return size;
}

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
    
//    char buf[BUFSIZ];
    char buf[BUFSIZ];
    int count = 0;
    FILE *fp;
    while (1) {
        socklen_t len = sizeof(server_addr);
        /*3.recvfrom()*/
        bzero(buf, BUFSIZ);
        if (recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len) <= 0) {
            printf("接收数据失败!\n");
            exit(1);
        }
        
        if (!strcmp(buf, "exit")) {
            close(ss);
            exit(1);
        }
        char* filename="/Users/necromaner/program/C-/UDP/test/send/send.txt.zip";
        char* name="send.txt";
        
        printf("client:%s\n", buf);
        if (!strcmp(buf, "send")) {
            if ((fp = fopen(filename, "r")) == NULL) {
                perror("打开文件失败\n");
                exit(0);
            } else{
                printf("打开文件成功!\n");
            }
            bzero(buf, BUFSIZ);
//            buf[0]=;
            fread(buf, sizeof(char), sizeof(buf), fp);
            count++;
            printf("文件内容：%s\n",buf);
            /*4.sendto()*/
            char x[BUFSIZ];
            sprintf(x, "%d", file_size2(filename));
            printf("文件大小：：%s字节\n",x);
            sendto(ss,x,sizeof(buf), 0, (struct sockaddr *) &server_addr, len);
            sendto(ss,buf,sizeof(buf), 0, (struct sockaddr *) &server_addr, len);
            printf("send:%s\n\n", buf);
        } else {
            sprintf(buf, "已收到%d条\n", count);  //回复client
            count++;

            /*4.sendto()*/
            sendto(ss, buf, sizeof(buf), 0, (struct sockaddr *) &server_addr, len);
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
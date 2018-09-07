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
#define    MAXLINE        1024
#define    PORT           8888
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
//--------------------------------------------------------------------------------
    char buf[BUFSIZ];
    FILE *fp;
    int count = 1;
    
    while (1) {
        bzero(buf, BUFSIZ);
        /*3.recvfrom()*/
        socklen_t len = sizeof(server_addr);
        if (recvfrom(ss, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len) <= 0) {
            printf("接收数据失败!\n");
            exit(1);
        }
        printf("3.recvfrom()\n");
        
        if (!strcmp(buf, "exit")) {
            break;
        }
        printf("client:%s\n", buf);
        if (!strcmp(buf, "send")) {
            printf("-|开始发送文件\n");
            int send_len;
            //1。打开文件
            if ((fp = fopen("/Users/necromaner/program/C-/UDP/test/send/123.zip", "r")) == NULL) {
                perror("打不开文件\n");
                exit(0);
            } else
                printf("-|1.打开文件\n");
            bzero(buf, MAXLINE);
            //2。读取并发送
            printf("-|2.读取并发送");
            int num=0;
            while ((fread(buf, sizeof(char), MAXLINE, fp)) > 0) {
                num++;
                send_len = sendto(ss, buf, sizeof(buf), 0, (struct sockaddr *) &server_addr, len);
                if (send_len < 0) {
                    perror("发送失败\n");
                    exit(0);
                }
                bzero(buf, MAXLINE);
            }
            printf("%d次\n",num);
            bzero(buf, MAXLINE);
            //3。发送结束命令
            strcpy(buf, FINISH_FLAG);
            buf[strlen(buf)] = '\0';//strlen()用来计算字符串的长度
            sendto(ss, buf, strlen(buf) + 1, 0, (struct sockaddr *) &server_addr, len);
            printf("-|3.发送结束命令：%s\n",buf);
            
            printf("-|发送完成\n\n");
        } else {
            sprintf(buf, "已收到%d条文字信息\n", count);
            count++;

            /*4.sendto()*/
            sendto(ss, buf, sizeof(buf), 0, (struct sockaddr *) &server_addr, len);
            printf("send:%s\n", buf);
        }

    }
    
    /*5.close()*/
    close(ss);
    printf("5.close()\n");
    
}
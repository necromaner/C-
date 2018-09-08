#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define    FINISH_FLAG    "FILE_TRANSPORT_FINISH"
#define    MAXLINE        1024
#define    PORT           8888

int main()
{
    /*1.socket()*/
    int ss = socket(AF_INET, SOCK_STREAM, 0);//tcp
    printf("1.socket()\n");
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    /*2.connect()*/
    if (connect(ss, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) < 0) {
        printf("2.connect()-UDP连接\n");
        ss = socket(AF_INET, SOCK_DGRAM, 0);
        if (connect(ss, (struct sockaddr *)&server_addr, sizeof(struct sockaddr))<0) {
            perror("Connect socket failed!\n");
            exit(0);
        }
    } else{
        printf("2.connect()-TCP连接\n");
    }
//--------------------------------------------------------------------------------
    char buf[MAXLINE];
    FILE *fp;
    
    int read_len;
    int send_len;
    sprintf(buf, "send");
    
    if ((fp = fopen("/Users/necromaner/program/C-/UDP/test/send/receive的副本.txt.zip","r")) == NULL) {
        perror("打不开文件\n");
        exit(0);
    }
    bzero(buf, MAXLINE);
    while ( (read_len = fread(buf, sizeof(char), MAXLINE, fp)) > 0 ) {
        
        send_len = send(ss, buf, read_len, 0);
        if ( send_len < 0 ) {
            perror("发送失败\n");
            exit(0);
        }
        bzero(buf, MAXLINE);
    }
    fclose(fp);
    
    bzero(buf, MAXLINE);
    
    strcpy(buf, FINISH_FLAG);
    buf[strlen(buf)] = '\0';
    for (int i = 10; i>0; i--) {
        send(ss, buf, strlen(buf)+1, 0);
        if ( send_len < 0 ) {
            printf("完成发送\n");
            break;
        }
    }
    close(ss);
    
    
    printf("close()\n");
    return 0;
}
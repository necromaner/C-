#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>

#define     FINISH_FLAG     "FILE_TRANSPORT_FINISH"
#define     MAXLINE          1024
#define     PORT             8888

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
//--------------------------------------------------------------------------------
    char buf[BUFSIZ];
    FILE *fp;
    while (1) {
        printf("发送消息：");
        sprintf(buf, "send");
        scanf("%s", buf);
        
        /*3.send()*/
        socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
        sendto(sc, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, len);
        printf("3.sendto():%s\n", buf);
        if (!strcmp(buf, "exit")) {
            break;
        }
    
        /*4.recv()*/
        if (!strcmp(buf, "send")) {
            printf("-|开始接收文件\n");
            int recv_len;
            //1。打开文件
            if ((fp = fopen("/Users/necromaner/program/C-/UDP/test/send/receive2.txt.zip", "w")) == NULL) {
                perror("打不开文件\n");
                exit(0);
            } else
                printf("-|1.打开文件\n");
            bzero(buf, MAXLINE);
            //2。接收并写入
            printf("-|2.接收并写入");
            int num=0;
            while (1) {
                //接收
                socklen_t len = sizeof(server_addr);
                recv_len = recvfrom(sc, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
                if (recv_len < 0) {
                    break;
                }
                //判断是否为结束命令
                if (strstr(buf, FINISH_FLAG) != NULL) {
                    printf("%d次\n-|3.收到结束命令:%s\n",num,buf);
                    break;
                }
                //写入文件
                int write_length = fwrite(buf, sizeof(char), recv_len, fp);
                if (write_length < recv_len) {
                    printf("文件写入失败");
                    break;
                }
                bzero(buf, MAXLINE);
                num++;
            }
            fclose(fp);
            printf("-|接收完成\n\n");
        } else{
            recvfrom(sc, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
            printf("server:%s\n", buf);
        }
//        sleep(1);
    }
    /*5.close()*/
    close(sc);
    printf("5.close()\n");
}















#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>

#define    FINISH_FLAG    "FILE_TRANSPORT_FINISH"
#define PORT  8888

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
    while (1) {
        char buf[BUFSIZ] = "send";
//        scanf("%s", buf);
        if (!strcmp(buf, "exit")) {
            close(sc);
            exit(1);
        }
    
        socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
    
        /*2.send()*/
        sendto(sc, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, len);
        printf("3.send():%s\n", buf);
    
        /*3.recv()*/
        if (!strcmp(buf, "send")) {
            bzero(buf, BUFSIZ);
            recvfrom(sc, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
            int x=atoi(buf);
            bzero(buf, BUFSIZ);
            printf("文件大小：%d字节\n",x);
            recvfrom(sc, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
            printf("4.recv():%s\n", buf);
            int min=0,sizeMax=0,sizeNow=0;
            char* name;
    
            if ((fp = fopen("/Users/necromaner/program/C-/UDP/test/send/receive.txt.zip", "w")) == NULL) {
                perror("新建文件失败");
                exit(0);
            } else{
                printf("新建文件成功\n");
            }
            int num=0;
            for(int i=sizeof(buf);i>=0 ;i--){
                if(buf[i]==0)
                    num=i;
            }
            printf("buf有效长度：%d\n",num);
            printf("传输大小:%d字节\n", num);
            if (fwrite(buf, sizeof(char), x, fp)) {
                printf("文件写入成功\n");
                break;
            } else{
                printf("文件写入失败\n");
            }
        } else{
            recvfrom(sc, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
            printf("server:%s\n", buf);
        }
        sleep(1);
    }
    /*close()*/
    close(sc);
    printf("close()\n");
}















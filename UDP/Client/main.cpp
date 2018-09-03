#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>

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
    bool udp = 1;
    if (connect(sc, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        udp = 0;
        sc = socket(AF_INET, SOCK_DGRAM, 0);
        printf("UDP连接\n");
    } else
        printf("TCP连接\n");
    
    while (1) {
        char buf[BUFSIZ] = "测试发送!";
        scanf("%s", buf);
        if (!strcmp(buf, "exit"))
            break;
        
        socklen_t len = sizeof(*(struct sockaddr *) &server_addr);
        
        /*2.send()*/
        sendto(sc, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, len);
        printf("send:%s\n", buf);
        
        /*3.recv()*/
        recvfrom(sc, buf, BUFSIZ, 0, (struct sockaddr *) &server_addr, &len);
        printf("server:%s\n", buf);
        sleep(1);
    }
    /*close()*/
    close(sc);
    printf("close()\n");
}















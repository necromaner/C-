#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define PORT  8888
int main()
{
    /*1.socket()*/
    int sc = socket(AF_INET,SOCK_STREAM, 0);
    printf("1.socket()\n");
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);  ///服务器端口
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  ///服务器ip

    /*2.connect()*/
    if (connect(sc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(1);
    } else
        printf("2.connect()\n");
    
    while(1)
    {
        char buf[BUFSIZ] = "";
        scanf("%s\n",buf);
        if(!strcmp(buf,"quit"))
            break;
    
        /*3.send()*/
        send(sc,buf,strlen(buf),0);
        printf("send:%s\n",buf);
        
        /*4.recv()*/
        recv(sc,buf,BUFSIZ,0);
        printf("server: %s",buf);
    }
    
    /*5.close()*/
    close(sc);
}
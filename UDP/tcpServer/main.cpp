#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#define PORT 7000
#define QUEUE 20

int main(){
    
    /*1.socket()*/
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    printf("1.socket()\n");
    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(PORT);
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    /*2.bind()*/
    if(bind(ss, (struct sockaddr* ) &server_sockaddr, sizeof(server_sockaddr))==-1) {
        printf("创建套接字失败!\n");
        exit(1);
    } else
        printf("2.bind()\n");
    
    /*3.listen()*/
    if(listen(ss, QUEUE) == -1) {
        printf("监听失败!\n");
        exit(1);
    } else
        printf("3.listen()\n");
    
    /*4.accept()*/
    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    int conn = accept(ss, (struct sockaddr*)&client_addr, &len);
    if( conn < 0 ) {
        printf("连接失败!\n");
        exit(1);
    } else
        printf("4.accept()\n");
    int sin_size;
    
    
    char buf[BUFSIZ];
    int count=0;
    while(1)
    {
        /*5.recv()*/
        if((recv(conn,buf,BUFSIZ,0))<=0)
        {
            printf("接收错误\n");
            return 1;
        }
        printf("client: %s\n",buf);
        
        
//        fgets(buf, sizeof(buf), stdin);
    
        sprintf(buf, "已收到%d\n",count);  //回复client
        count++;
        
        /*6.send()*/
        send(conn,"收到\n",sizeof(buf),0);
        printf("send: %s\n",buf);
    }
    
    /*7.close()*/
    close(conn);
    close(ss);
}
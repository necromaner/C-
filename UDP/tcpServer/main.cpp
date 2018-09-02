#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 8888

int main(){
    
    /*1.socket()*/
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    printf("1.socket()\n");
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    /*2.bind()*/
    if(bind(ss, (struct sockaddr* ) &server_addr, sizeof(server_addr))<0) {
        printf("创建套接字失败!\n");
        exit(1);
    } else
        printf("2.bind()\n");
    
    /*3.listen()*/
    if(listen(ss, 20) == -1) {
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
    
    
    char buf[BUFSIZ];
    int count=0;
    while(1)
    {
        /*5.recv()*/
        if((recv(conn,buf,BUFSIZ,0))<=0)
        {
            printf("接收数据失败!\n");
            return 1;
        }
        printf("client: %s",buf);
        
        
//        fgets(buf, sizeof(buf), stdin);
    
        sprintf(buf, "已收到%d条\n",count);  //回复client
        count++;
        
        /*6.send()*/
        send(conn,buf,sizeof(buf),0);
        printf("send: %s\n",buf);
    }
    
    /*7.close()*/
    close(conn);
    close(ss);
}
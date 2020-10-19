#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <zconf.h>

#define PORT 8888


int main(){
    /*1.socket()*/
    int sc=socket(AF_INET,SOCK_DGRAM,0);
    printf("1.socket()\n");
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    

    while (1){
        char buf[BUFSIZ] = "测试发送!";
//        scanf("%s",buf);
//        if(!strcmp(buf,"quit"))
//            break;
        
        socklen_t len = sizeof(*(struct sockaddr*)&server_addr);

        /*2.sendto()*/
        sendto(sc, buf, BUFSIZ, 0, (struct sockaddr*)&server_addr, len);
        printf("send:%s\n",buf);

        /*3.recvfrom()*/
        recvfrom(sc, buf, BUFSIZ, 0, (struct sockaddr*)&server_addr, &len);
        printf("server:%s\n",buf);
        sleep(1);
    }
    
    /*4.close()*/
    close(sc);
    printf("4.close()\n");
}
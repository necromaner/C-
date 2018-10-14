//#include <stdio.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <cstdlib>
//#include <zconf.h>
//#include <cstring>
//#include <arpa/inet.h>
#include <string>
#include <netinet/in.h>//
//#include "send/Send.h"
#define    PORT           8888


using namespace std;
//struct sockaddr_in server_addr;

//void udpServer(string file1,string file2,int max,int bigblock){
//    int ss = socket(AF_INET, SOCK_DGRAM, 0);
//    printf("1.socket()\n");
//    server_addr.sin_family = AF_INET;
//    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
//    server_addr.sin_port = htons(PORT);
//    if (bind(ss, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
//        printf("创建套接字失败!\n");
//        exit(1);
//    } else
//        printf("2.bind()\n");
////    send(ss,server_addr,file1,file2,max,bigblock);
//}
int main() {
    string file1 = "/Users/necromaner/test/send/";
    string file2 = "2.zip";
//    string file2 = "send.txt";
    int max=984;
    int bigblock=98400;
//    udpServer(file1,file2,max,bigblock);
    return 0;
}
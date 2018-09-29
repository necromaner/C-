#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <zconf.h>
#include <cstring>
#include <vector>
#include <arpa/inet.h>
#include "Send.h"
#define    PORT           8888


using namespace std;
struct sockaddr_in server_addr;


/**
 * @brief 根据数组发送文件序号
 * @param xx    未成功发送数据
 * @param t        参数2 @see CTest
 *
 * @return 返回说明
 *     -<em>false</em> fail
 *     -<em>true</em> succeed
 */

void udpServer(){
    /*1.socket()*/
    int ss = socket(AF_INET, SOCK_DGRAM, 0);
    printf("1.socket()\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    
    /*2.bind()*/
    if (bind(ss, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        
        printf("创建套接字失败!\n");
        exit(1);
    } else
        printf("2.bind()\n");
    /*----------------------------------------------------------*/

    
    send(ss,server_addr);
}
int main() {
    udpServer();
    return 0;
}
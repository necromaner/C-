#include "udp/UdpServer.h"
#include <iostream>
using namespace std;
int main() {
    UdpServer udp;
    udp.Information();
    udp.show();
    
//    udp.receiveFile();
    printf("num=%d\n",udp.receiveFile().num);
//    printf("接收内容：\n%s\n",udp.getBuf());
    return 0;
}
#include "udp/UdpClient.h"

#include <iostream>
using namespace std;
int main() {
    UdpClient udp;
    udp.setFile("/Users/necromaner/test/send/","send.txt");
    udp.Information();
    udp.show();
    udp.readFile(0);
//    printf("读取内容：%s\n",udp.getBlock());
    udp.sendFile(5);
//    printf("读取内容：\n%s\n",udp.getBuf());
    return 0;
}
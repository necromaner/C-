#include "udp/UdpClient.h"

#include <iostream>
using namespace std;
int main() {
    UdpClient udp;
    udp.setFile("/Users/necromaner/test/send/","send.txt");
    udp.Information();
    udp.show();
    udp.readFile(3);
    printf("读取内容：%s\n",udp.getBlock());
    return 0;
}
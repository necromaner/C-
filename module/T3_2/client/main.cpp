#include "udp/UdpClient.h"

#include <iostream>
using namespace std;
int main() {
    UdpClient udp;
    udp.setFile("/Users/necromaner/test/send/","1.zip");
    //1.发送信息
    udp.Information();
    udp.show();
    //2.发送数据
    udp.sendFile();

    return 0;
}
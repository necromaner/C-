#include "udp/UdpClient.h"
int main() {
    UdpClient udp;
    udp.setFile("/Users/necromaner/test/send/","3.zip");
    //1.发送信息
    udp.Information();
    udp.show();
    //2.发送数据
    udp.sendFile();
//    udp.TEXT_Send(1,100);
    return 0;
}
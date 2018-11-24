#include "udp/UdpServer.h"
#include <iostream>
using namespace std;
int main() {
    UdpServer udp;
    //1.接收信息
    udp.Information();
    udp.show();

    //2.接收数据
    udp.receiveFile();

//    udp.TEXT_Receive(1,100);


}
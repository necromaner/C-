#include "udp/UdpServer.h"
#include "gtest/gtest.h"

void udp(){
    UdpServer udp;
    //0.设置发送路径及文件名
    udp.setFile("/Users/necromaner/test/receive/");
    //1.启动udp
    udp.udpStart();
    //2.发送信息
    udp.Information();
//    udp.show();
//    //3.发送数据
//    udp.receiveFile();
//    udp.TEXT_Receive(1,100);
}
int test(int argc, char ** argv){
    gtest gtest1;
    gtest1.test(argc,argv);
}
int main(int argc, char ** argv) {
    int x = 0;
    switch (x) {
        case 0:
            udp();
            break;
        case 1:
            test(argc, argv);
            break;
        default:
            break;
    }
}
#include "udp/UdpClient.h"
#include "gtest/gtest.h"


void udp(){
    UdpClient udp;
    //0.设置发送路径及文件名
    udp.setFile("/Users/necromaner/test/send/","2.txt");
    //1.启动udp
    udp.udpStart();
    //2.发送信息
    udp.Information();
    udp.show();
    //3.发送数据
    udp.sendFile();
//    udp.TEXT_Send(1,100);
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
#include "test/Test.h"
void test(int argc, char ** argv){
    Test test;
    test.test(argc,argv);
}
void udp(){
    Udp udp;
    //0.设置发送路径及文件名
    udp.setFile("/Users/necromaner/test/send/","2.txt");
    //1.启动udp
    udp.udpStart();
//    //2.发送信息
    udp.Information();
    udp.show();
//    //3.发送数据
    udp.sendFile();
}
int main(int argc, char ** argv) {
//    int i=2;
//    while(i--){
//        printf("-\n");
//        if(i==1)
//            break;
//    }
    int x = 1;
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
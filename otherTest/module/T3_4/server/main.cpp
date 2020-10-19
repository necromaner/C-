
#include <thread>
#include "udp/Udp.h"
#include "test/Test.h"

Udp udp;
void test(int argc, char ** argv){
    Test test;
    test.test(argc,argv);
}
void input_Thread() {
    udp.input_Thread();
    printf("thread_Send end1\n");
}
void RE_Thread(){
    udp.RE_Thread();
    printf("RE_Thread end2\n");
}
void Send_Thread(){
    udp.Send_Thread();
    printf("Send_Thread end3\n");
}
void udp1(){
    //0.设置文件路径
    udp.setFile("/Users/necromaner/test/send/");
    //1.启动udp服务器
    udp.udpStart();
    //2.开启线程
    std::thread t1(input_Thread);
    std::thread t2(RE_Thread);
    std::thread t3(Send_Thread);
    t1.join();
    t2.join();
    t3.join();
}
int main(int argc, char ** argv) {
    int x;
    x = 0;
//    x = 1;
    switch (x) {
        case 0:
            udp1();
            break;
        case 1:
            test(argc, argv);
            break;
        default:
            break;
    }
}
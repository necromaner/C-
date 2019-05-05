#include "test/Test.h"
void test(int argc, char ** argv){
    Test test;
    test.test(argc,argv);
}
void udp(){
    Udp udp;
    //0.设置文件路径
    udp.setFile("/Users/necromaner/test/receive/");
    //2.启动udp客户端连接服务器
    udp.udpStart();
    //3.发送文件名
    udp.fileName("2.txt");
    //7.接收文件信息
    if(!udp.File_Information())
        return;
    udp.show();
    //8.主线程:发送需要接收文件块序及块分割的序号
    udp.thread_Main();
    //9.启动线程1：开始接收文件
    //6.主线程：接收到结尾发送新的需要接收到序号(如果接收完成)
    //7.如果一个块接收完成启动线程2：写入到文件中，写入完成关闭线程
    //8.
    //9.
}
int main(int argc, char ** argv) {

    int x;
    x=0;
//    x = 1;
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
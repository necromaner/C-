#include <gtest/gtest.h>
#include "udp/UdpClient.h"
TEST(private, test0){
    UdpClient udp;

    ////-----------string file()
    udp.setFile1("/Users/necromaner/test/send/");
    udp.setFile2("3.zip");
    std::string a01="/Users/necromaner/test/send/3.zip";
    EXPECT_EQ(a01,udp.file());

    ////-----------long long serial()
    long long a11=12509;
    udp.setFl("123",123456789,9870,987);
    EXPECT_EQ(a11,udp.serial());
    long long a12=100001;
    udp.setFl("123",1000000123,10000,100);
    EXPECT_EQ(a12,udp.serial());

    ////-----------int MAX_endbuf()
    int a21=855;
    udp.setFl("123",123456789,9870,987);
    EXPECT_EQ(a21,udp.MAX_endbuf());
    int a22=23;
    udp.setFl("123",1000000123,10000,100);
    EXPECT_EQ(a22,udp.MAX_endbuf());
}
TEST(TEXT_Send,test0){
    UdpClient udp;

}
void udp(){
    UdpClient udp;
    //0.启动udp
    udp.udpStart();
    udp.setFile("/Users/necromaner/test/send/","3.zip");
    //1.发送信息
    udp.Information();
    udp.show();
    //2.发送数据
    udp.sendFile();
//    udp.TEXT_Send(1,100);
}
int test(int argc, char ** argv){
    printf("\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // 执行所有的 test case
}
int main(int argc, char ** argv) {
//    udp();
//    test(argc,argv);

    UdpClient udp;
    udp.test1();
}
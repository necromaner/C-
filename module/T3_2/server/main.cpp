#include <gtest/gtest.h>
#include "udp/UdpServer.h"
//using namespace std;

//TEST(time, test0){
//    UdpServer udp;
//    printf("111\n");
//    EXPECT_EQ("1-1,2-2,",udp.map_To_String());
//}

TEST(private, test0){
    UdpServer udp;

    ////-----------string times(int s)
    std::string a01="01:01:25";
    std::string a02="2d 01:01:01";
    std::string a03="14288d 23:31:30";
    std::string a04="ERROR";
    EXPECT_EQ(a01,udp.times(24+3600+60+1));
    EXPECT_EQ(a02,udp.times(7200*24+3600+60+1));
    EXPECT_EQ(a03,udp.times(1234567890));
    EXPECT_EQ(a04,udp.times(-1000));

    ////-----------string speed(long long s,int d)
    std::string a11="  1.00 K/s";
    std::string a12="  1.00 M/s";
    std::string a13="  0.00 B/s";
    std::string a14=" 14.54 M/s";
    std::string a15="  ERROR   ";
    EXPECT_EQ(a11,udp.speed(1024,1));
    EXPECT_EQ(a12,udp.speed(1024*1024,1));
    EXPECT_EQ(a13,udp.speed(0,1));
    EXPECT_EQ(a13,udp.speed(0,0));
    EXPECT_EQ(a14,udp.speed(1234567890,9));
    EXPECT_EQ(a15,udp.speed(-100,1));
    EXPECT_EQ(a15,udp.speed(-100,-1));


}
TEST(map_To_String, test0){
    UdpServer udp;
    std::map<int,int> s;
    s[1]=1;
    s[2]=2;
    EXPECT_EQ("1-1,2-2,",udp.map_To_String(s));
    std::map<int,int> s1;
    EXPECT_EQ("",udp.map_To_String(s1));
}


void udp(){
    UdpServer udp;
    //0.启动udp
    udp.udpStart();
    //1.接收信息
    udp.Information();
    udp.show();

    //2.接收数据
    udp.receiveFile();

//    udp.TEXT_Receive(1,100);
}
int test(int argc, char ** argv){
    printf("\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // 执行所有的 test case
}
int main(int argc, char ** argv) {
    udp();
//    test(argc,argv);
}

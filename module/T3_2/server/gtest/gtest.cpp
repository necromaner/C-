//
// Created by necromaner on 2018/12/8.
//

#include "gtest.h"

gtest::gtest(){
    printf("-------------begin-------------");
}
gtest::~gtest(){
    printf("--------------end--------------");
}
int gtest::test(int argc, char ** argv){
    printf("\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // 执行所有的 test case
}
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
//TEST(set_To_String, test0){
//    UdpServer udp;
//    std::set<int> s;
//    s.insert(1);
//    s.insert(2);
//    EXPECT_EQ("1 2 ",udp.set_To_String(s));
//    std::set<int> s1;
//    EXPECT_EQ("",udp.set_To_String(s1));
//}



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
TEST(private, test0){
    UdpClient udp;

    ////-----------string file()
    udp.setFile1("/Users/necromaner/test/send/");
    udp.setFile2("3.zip");
    std::string a01="/Users/necromaner/test/send/3.zip";
    EXPECT_EQ(a01,udp.file());
    udp.Clean_test();
    ////-----------long long serial()
    long long a11=12509;
    udp.setFl("123",123456789,9870,987);
    EXPECT_EQ(a11,udp.serial());
    udp.Clean_test();
    long long a12=100001;
    udp.setFl("123",1000000123,10000,100);
    EXPECT_EQ(a12,udp.serial());
    udp.Clean_test();

//    ////-----------int MAX_endbuf()
//    int a21=855;
//    udp.setFl("123",123456789,9870,987);
//    EXPECT_EQ(a21,udp.MAX_endbuf());
//    int a22=23;
//    udp.setFl("123",1000000123,10000,100);
//    EXPECT_EQ(a22,udp.MAX_endbuf());


    ////-----------std::set<int> initialization_set(long long num,long long is)
    udp.setFl("initialization_set",123456,10000,1000);
    std::set<int> a31={1,2,3,4,5,6,7,8,9,0};
    EXPECT_EQ(a31,udp.initialization_set(10,udp.serial()-1));
    udp.Clean_test();
    ////-----------std::vector<int> split(const std::string& str, const std::string& delim)
    std::set<int> a41={1, 2, 3, 4, 5, 9};
    std::string a42=" 9, 4, 1,2,3,4,5,";
    EXPECT_EQ(a41,udp.string_To_Set(a42,","));
    udp.Clean_test();
    ////-----------string times(int s)
    std::string a51="00:00:00.000";
    std::string a52="00:00:00.001";
    std::string a53="00:00:00.010";
    std::string a54="00:00:00.100";
    std::string a55="00:00:00.999";
    std::string a56="00:00:59.999";
    std::string a57="00:01:01";
    std::string a58="1d 03:46:40";
    EXPECT_EQ(a51,udp.times(0));
    EXPECT_EQ(a52,udp.times(1));
    EXPECT_EQ(a53,udp.times(10));
    EXPECT_EQ(a54,udp.times(100));
    EXPECT_EQ(a55,udp.times(999));
    EXPECT_EQ(a56,udp.times(59999));
    EXPECT_EQ(a57,udp.times(60999));
    EXPECT_EQ(a58,udp.times(99999999));
    ////-----------string speed(long long s,int d)

}

TEST(TEXT_Send,test0){
    UdpClient udp;
}
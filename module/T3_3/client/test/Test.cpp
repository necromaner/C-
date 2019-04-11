#include "Test.h"
Test::Test() {
    printf("-------------test-begin------------\n");
}
Test::~Test() {
    printf("-------------test--end-------------\n");
}
int Test::test(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // 执行所有的 test case
}
////-------------------md5----------------------////
TEST(md5,test0) {
    std::map<std::string, std::string> s;
    s["123"] = "202cb962ac59075b964b07152d234b70";
    s["123456"] = "e10adc3949ba59abbe56e057f20f883e";
    s["abc"] = "900150983cd24fb0d6963f7d28e17f72";
    s["abc\n"] = "0bee89b07a248e27c83fc3d5951213c1";
    s["\\n"] = "1d78758685e5e2f4efeeb490f8521abd";
    s["\n"] = "68b329da9893e34099c7d8ad5cb9c940";
    s["温"] = "35c8a8b071f57b058ef3c777c0b02f04";
    s[""] = "d41d8cd98f00b204e9800998ecf8427e";
    std::map<string, string>::iterator iter;
    for (iter = s.begin(); iter != s.end(); ++iter) {
        MD5 md5(iter->first);
        char x[100];
        sprintf(x, "error:-%s-", iter->first.c_str());
        EXPECT_EQ(iter->second, md5.toStr()) << x;
    }
}
////------------------other---------------------////
TEST(time,theJetLag){
    Other other;
    EXPECT_EQ("00:00:00.000",other.theJetLag(TIME_10,TIME_10))<<"1.1 0毫秒";
    EXPECT_EQ("00:00:00.001",other.theJetLag(ZERO,TIME_MS))<<"1.2 1毫秒";
    EXPECT_EQ("00:00:00.010",other.theJetLag(ZERO,TIME_MS*TIME_10))<<"1.3 10毫秒";
    EXPECT_EQ("00:00:00.100",other.theJetLag(ZERO,TIME_MS*TIME_10*TIME_10))<<"1.4 100毫秒";
    EXPECT_EQ("00:00:01.000",other.theJetLag(ZERO,TIME_S))<<"1.5 1分钟";
    EXPECT_EQ("00:00:01.999",other.theJetLag(ZERO,TIME_S*2-1))<<"1.6 1秒999毫秒";
    EXPECT_EQ("    00:01:01",other.theJetLag(ZERO,TIME_M+TIME_S+TIME_HALF-1))<<"1.7 大于1分钟，舍错误";
    EXPECT_EQ("    00:01:02",other.theJetLag(ZERO,TIME_M+TIME_S+TIME_HALF))<<"1.8 大于1分钟，入错误";
    EXPECT_EQ("    01:01:02",other.theJetLag(ZERO,TIME_H+TIME_M+TIME_S+TIME_HALF))<<"1.9 1小时1分2秒";
    EXPECT_EQ(" 1d 01:01:02",other.theJetLag(ZERO,TIME_D+TIME_H+TIME_M+TIME_S+TIME_HALF))<<"1.10 1天1小时1分2秒";
    EXPECT_EQ("10d 01:01:02",other.theJetLag(ZERO,TIME_10*TIME_D+TIME_H+TIME_M+TIME_S+TIME_HALF))<<"1.11 11天1小时1分2秒";
    EXPECT_EQ(" >100 days  ",other.theJetLag(ZERO,TIME_MAX))<<"1.12 100天";

    EXPECT_EQ("    00:09:59",other.theJetLag(ZERO,TIME_10*TIME_M-TIME_HALF-1))<<"2.1 10分钟-501毫秒";
    EXPECT_EQ("    00:10:00",other.theJetLag(ZERO,TIME_10*TIME_M-TIME_HALF))<<"2.2 10分钟-500毫秒";
    EXPECT_EQ("    00:59:59",other.theJetLag(ZERO,TIME_H-TIME_HALF-1))<<"2.3 1小时-501毫秒";
    EXPECT_EQ("    01:00:00",other.theJetLag(ZERO,TIME_H-TIME_HALF))<<"2.4 1小时-500毫秒";
    EXPECT_EQ("    23:59:59",other.theJetLag(ZERO,TIME_D-TIME_HALF-1))<<"2.5 1天-501毫秒";
    EXPECT_EQ(" 1d 00:00:00",other.theJetLag(ZERO,TIME_D-TIME_HALF))<<"2.6 1天-500毫秒";
    EXPECT_EQ("99d 23:59:59",other.theJetLag(ZERO,TIME_MAX-TIME_HALF-1))<<"2.7 100天-501毫秒";
    EXPECT_EQ(" >100 days  ",other.theJetLag(ZERO,TIME_MAX-TIME_HALF))<<"2.8 100天-500毫秒";

    EXPECT_EQ(" begin=end=0",other.theJetLag(0,0))<<"开始结束为0";
    EXPECT_EQ("   end=0    ",other.theJetLag(10,0))<<"结束为0";
    EXPECT_EQ(" begin<0    ",other.theJetLag(-10,20))<<"开始为负";
    EXPECT_EQ(" begin<0    ",other.theJetLag(-11,-1))<<"开始结束为负";
    EXPECT_EQ(" begin>end  ",other.theJetLag(20,10))<<"结束大于开始";
}
TEST(time,date){
    Other other;
    EXPECT_EQ("1970/01/01 08:00:00",other.date(0))<<"1";
    EXPECT_EQ("1970/01/01 08:00:00",other.date(499))<<"2";
    EXPECT_EQ("1970/01/01 08:00:00",other.date(999))<<"3";
    EXPECT_EQ("1970/01/01 08:01:01",other.date(61000))<<"4";
    EXPECT_EQ("1970/01/01 09:01:01",other.date(3661000))<<"5";
    EXPECT_EQ("1970/01/02 09:01:01",other.date(90061000))<<"6";
    EXPECT_EQ("1970/02/02 09:01:01",other.date(2768461000))<<"7";
    EXPECT_EQ("1971/02/02 09:01:01",other.date(34304461000))<<"8";
    EXPECT_EQ("1971/12/12 23:59:59",other.date(61401599000))<<"9";
    EXPECT_EQ("2018/12/12 23:59:59",other.date(1544630399000))<<"10";
    EXPECT_EQ("2100/12/12 23:59:59",other.date(4132310399000))<<"11";
    EXPECT_EQ("3100/12/12 23:59:59",other.date(35689219199000))<<"12";
}
TEST(time,getCurrentTime) {
    Other other;
    time_t t;
    time(&t);
    EXPECT_EQ(t,other.getCurrentTime()/1000)<<"与秒级别时间戳做对比";
}
TEST(speed,speed){
    Other other;
    EXPECT_EQ("     0 B/s",other.speed(0,1000))<<"1.1 0字节";
    EXPECT_EQ("     1 B/s",other.speed(1,1000))<<"1.2 1b/s";
    EXPECT_EQ("     1 K/s",other.speed(1024,1000))<<"1.3 1k/s";
    EXPECT_EQ("     1 M/s",other.speed(1048576,1000))<<"1.4 1m/s";
    EXPECT_EQ("     1 G/s",other.speed(1073741824,1000))<<"1.5 1g/s";
    EXPECT_EQ("     1 T/s",other.speed(1099511627776,1000))<<"1.6 1t/s";
    EXPECT_EQ("     1 P/s",other.speed(1125899906842624,1000))<<"1.7 1p/s";
    EXPECT_EQ("    10 P/s",other.speed(1125899906842624*10,1000))<<"1.8 10p/s";
    EXPECT_EQ("    11 P/s",other.speed(SPEED_MAX,1000))<<"1.9 11p/s";
    EXPECT_EQ("   >11 P/s",other.speed(SPEED_MAX+1,1000))<<"1.10 >11 p/s";
    EXPECT_EQ("   >11 P/s",other.speed(9223372036854775,1))<<"1.11 >11 P/s";

    EXPECT_EQ("  0.98 K/s",other.speed(500,500))<<"2.1 0.98k/s";
    EXPECT_EQ(" 102.4 K/s",other.speed(1048576,10000))<<"2.1 0.1k/s";
    EXPECT_EQ(" 10.24 K/s",other.speed(1048576,100000))<<"2.1 0.01k/s";
    EXPECT_EQ("  0.99 M/s",other.speed(103809024,100000))<<"2.1 0.99m/s";
    EXPECT_EQ("time error",other.speed(0,0))<<"时间=0";
    EXPECT_EQ("time error",other.speed(0,-1))<<"时间<0";
    EXPECT_EQ("   >11 P/s",other.speed(-1,10))<<"数据<0";
}
TEST(change,set_To_String) {
    Other other;
    std::set<long long> y;
    EXPECT_EQ("COMPLETE", other.set_To_String(y, "-")) << "";
    y.insert(1);
    EXPECT_EQ("2", other.set_To_String(y, "-")) << "1";
    y.insert(2);
    EXPECT_EQ("2-3", other.set_To_String(y, "-")) << "1-2";
    y.insert(3);
    EXPECT_EQ("2-3-4", other.set_To_String(y, "-")) << "1-2-3";
    y.insert(5);
    EXPECT_EQ("2-3-4-6", other.set_To_String(y, "-")) << "1-2-3-5";
    y.insert(4);
    EXPECT_EQ("2-3-4-5-6", other.set_To_String(y, "-")) << "1-2-3-4-5";
    y.insert(1099511627776);
    EXPECT_EQ("2-3-4-5-6-1099511627777", other.set_To_String(y, "-")) << "1-2-3-4-5-1099511627776";
    y.insert(-1);
    EXPECT_EQ("ERROR", other.set_To_String(y, "-")) << "error";
}
TEST(change,string_to_Set) {
    Other other;
    std::set<long long> y;
    std::set<long long> error;
    error.insert(-1);
    EXPECT_EQ(y, other.string_to_Set("", "-")) << "";
    EXPECT_EQ(y, other.string_to_Set("-", "-")) << "";
    y.insert(1);
    EXPECT_EQ(y, other.string_to_Set("2", "-")) << "1";
    y.insert(2);
    EXPECT_EQ(y, other.string_to_Set("2-3", "-")) << "1 2";
    y.insert(3);
    EXPECT_EQ(y, other.string_to_Set("2-3-4", "-")) << "1 2 3";
    y.insert(5);
    EXPECT_EQ(y, other.string_to_Set("2-3-4-6", "-")) << "1 2 3 5";
    y.insert(4);
    EXPECT_EQ(y, other.string_to_Set("2-3-4-5-6", "-")) << "1 2 3 4 5";
    EXPECT_EQ(y, other.string_to_Set("2-3-4-5-6--", "-")) << "1 2 3 4 5";
    EXPECT_EQ(error, other.string_to_Set("2-3-4-5-6-d", "-")) << "error";
}
TEST(change,initialization_Set) {
    Other other;
    std::set<long long> y;
    EXPECT_EQ(y, other.initialization_Set(0)) << "无";
    y.insert(0);
    EXPECT_EQ(y, other.initialization_Set(1)) << "0";
    y.insert(1);
    EXPECT_EQ(y, other.initialization_Set(2)) << "0 1";
    y.insert(2);
    EXPECT_EQ(y, other.initialization_Set(3)) << "0 1 2";
    y.insert(3);
    y.insert(4);
    y.insert(5);
    EXPECT_EQ(y, other.initialization_Set(6)) << "0 1 2 3 4 5";
}
////------------------file---------------------////
TEST(File,getFile2) {
    File file;
    file.setFileName("/Users/necromaner/test/receive/", "1.txt");
    EXPECT_EQ("1.txt", file.getFile2()) << "文件名";
    EXPECT_EQ("/Users/necromaner/test/receive/1.txt", file.getFileName()) << "文件完整路径";
}
TEST(File,get_set) {
    File file;
    file.setFile(1, 2, 3);
    EXPECT_EQ(1, file.getSize()) << 1;
    EXPECT_EQ(2, file.getBlock()) << 2;
    EXPECT_EQ(3, file.getSend()) << 3;
}
TEST(File,checkProblem) {
    File file;
    file.setFile(0, 2, 3);
    EXPECT_EQ(-1, file.checkProblem()) << "参数小于等于0";
    file.setFile(1, 0, 3);
    EXPECT_EQ(-1, file.checkProblem()) << "参数小于等于0";
    file.setFile(1, 2, 0);
    EXPECT_EQ(-1, file.checkProblem()) << "参数小于等于0";
    file.setFile(1, 2, 3);
    EXPECT_EQ(-2, file.checkProblem()) << "发送大小大于块大小";
}
TEST(File,get_Block_Num) {
    File file;
    file.setFile(0, 2, 3);
    EXPECT_EQ(-1, file.get_Block_Num()) << "参数小于等于0";
    file.setFile(1, 0, 3);
    EXPECT_EQ(-1, file.get_Block_Num()) << "参数小于等于0";
    file.setFile(1, 2, 0);
    EXPECT_EQ(-1, file.get_Block_Num()) << "参数小于等于0";
    file.setFile(1, 2, 3);
    EXPECT_EQ(-2, file.get_Block_Num()) << "发送大小大于块大小";
    file.setFile(100, 10, 5);
    EXPECT_EQ(9, file.get_Block_Num()) << "全部倍数情况";
    file.setFile(100, 15, 5);
    EXPECT_EQ(6, file.get_Block_Num()) << "块、数据倍数";
    file.setFile(100, 10, 3);
    EXPECT_EQ(9, file.get_Block_Num()) << "文件、块倍数";
    file.setFile(100, 15, 10);
    EXPECT_EQ(6, file.get_Block_Num()) << "文件、数据倍数";
    file.setFile(100, 15, 6);
    EXPECT_EQ(6, file.get_Block_Num()) << "全部不倍数";
    file.setFile(100, 100, 6);
    EXPECT_EQ(0, file.get_Block_Num()) << "块大小等于文件大小";
    file.setFile(100, 200, 6);
    EXPECT_EQ(0, file.get_Block_Num()) << "块大小大于文件大小";
    file.setFile(100, 200, 100);
    EXPECT_EQ(0, file.get_Block_Num()) << "块大小大于文件大小";
    file.setFile(100, 200, 100);
    EXPECT_EQ(0, file.get_Block_Num()) << "发送大小等于文件大小";
    file.setFile(100, 200, 150);
    EXPECT_EQ(0, file.get_Block_Num()) << "发送大小大于文件大小";
}
TEST(File,get_Block_Size) {
    File file;
    file.setFile(0, 2, 3);
    EXPECT_EQ(-1, file.get_Block_Size(0)) << "参数小于等于0";
    file.setFile(1, 0, 3);
    EXPECT_EQ(-1, file.get_Block_Size(0)) << "参数小于等于0";
    file.setFile(1, 2, 0);
    EXPECT_EQ(-1, file.get_Block_Size(0)) << "参数小于等于0";
    file.setFile(1, 2, 3);
    EXPECT_EQ(-2, file.get_Block_Size(0)) << "发送大小大于块大小";
    file.setFile(100, 10, 5);
    EXPECT_EQ(10, file.get_Block_Size(0)) << "全部倍数情况，块首";
    EXPECT_EQ(10, file.get_Block_Size(9)) << "全部倍数情况，块尾";
    file.setFile(100, 15, 5);
    EXPECT_EQ(15, file.get_Block_Size(0)) << "块、数据倍数，块首";
    EXPECT_EQ(10, file.get_Block_Size(6)) << "块、数据倍数，块尾";
    file.setFile(100, 10, 3);
    EXPECT_EQ(10, file.get_Block_Size(0)) << "文件、块倍数，块首";
    EXPECT_EQ(10, file.get_Block_Size(9)) << "文件、块倍数，块尾";
    file.setFile(100, 15, 10);
    EXPECT_EQ(15, file.get_Block_Size(0)) << "文件、数据倍数，块首";
    EXPECT_EQ(10, file.get_Block_Size(6)) << "文件、数据倍数，块尾";
    file.setFile(100, 15, 6);
    EXPECT_EQ(15, file.get_Block_Size(0)) << "全部不倍数，块首";
    EXPECT_EQ(10, file.get_Block_Size(6)) << "全部不倍数，块尾";
    EXPECT_EQ(-21, file.get_Block_Size(7)) << "块序号超过最大";
    file.setFile(100, 100, 6);
    EXPECT_EQ(100, file.get_Block_Size(0)) << "块大小等于文件大小";
    file.setFile(100, 200, 6);
    EXPECT_EQ(100, file.get_Block_Size(0)) << "块大小大于文件大小";
    file.setFile(100, 200, 100);
    EXPECT_EQ(100, file.get_Block_Size(0)) << "块大小大于文件大小";
    file.setFile(100, 200, 150);
    EXPECT_EQ(100, file.get_Block_Size(0)) << "发送大小等于文件大小";
    file.setFile(100, 200, 150);
    EXPECT_EQ(100, file.get_Block_Size(0)) << "发送大小大于文件大小";
}
TEST(File,get_Buf_Num) {
    File file;
    file.setFile(0, 2, 3);
    EXPECT_EQ(-1, file.get_Buf_Num(0)) << "参数小于等于0";
    file.setFile(1, 0, 3);
    EXPECT_EQ(-1, file.get_Buf_Num(0)) << "参数小于等于0";
    file.setFile(1, 2, 0);
    EXPECT_EQ(-1, file.get_Buf_Num(0)) << "参数小于等于0";
    file.setFile(1, 2, 3);
    EXPECT_EQ(-2, file.get_Buf_Num(0)) << "发送大小大于块大小";
    file.setFile(100, 10, 5);
    EXPECT_EQ(1, file.get_Buf_Num(0)) << "全部倍数情况，块首";
    EXPECT_EQ(1, file.get_Buf_Num(9)) << "全部倍数情况，块尾";
    file.setFile(100, 15, 5);
    EXPECT_EQ(2, file.get_Buf_Num(0)) << "块、数据倍数，块首";
    EXPECT_EQ(1, file.get_Buf_Num(6)) << "块、数据倍数，块尾";
    file.setFile(100, 10, 3);
    EXPECT_EQ(3, file.get_Buf_Num(0)) << "文件、块倍数，块首";
    EXPECT_EQ(3, file.get_Buf_Num(9)) << "文件、块倍数，块尾";
    file.setFile(100, 15, 10);
    EXPECT_EQ(1, file.get_Buf_Num(0)) << "文件、数据倍数，块首";
    EXPECT_EQ(0, file.get_Buf_Num(6)) << "文件、数据倍数，块尾";
    file.setFile(100, 15, 6);
    EXPECT_EQ(2, file.get_Buf_Num(0)) << "全部不倍数，块首";
    EXPECT_EQ(1, file.get_Buf_Num(6)) << "全部不倍数，块尾";
    EXPECT_EQ(-21, file.get_Buf_Num(7)) << "块序号超过最大";
    file.setFile(100, 100, 6);
    EXPECT_EQ(16, file.get_Buf_Num(0)) << "块大小等于文件大小";
    file.setFile(100, 200, 6);
    EXPECT_EQ(16, file.get_Buf_Num(0)) << "块大小大于文件大小";
    file.setFile(100, 200, 100);
    EXPECT_EQ(0, file.get_Buf_Num(0)) << "块大小大于文件大小";
    file.setFile(100, 200, 150);
    EXPECT_EQ(0, file.get_Buf_Num(0)) << "发送大小等于文件大小";
}
TEST(File,get_Buf_Size) {
    File file;
    file.setFile(0, 2, 3);
    EXPECT_EQ(-1, file.get_Buf_Size(0, 0)) << "参数小于等于0";
    file.setFile(1, 0, 3);
    EXPECT_EQ(-1, file.get_Buf_Size(0, 0)) << "参数小于等于0";
    file.setFile(1, 2, 0);
    EXPECT_EQ(-1, file.get_Buf_Size(0, 0)) << "参数小于等于0";
    file.setFile(1, 2, 3);
    EXPECT_EQ(-2, file.get_Buf_Size(0, 0)) << "发送大小大于块大小";
    file.setFile(100, 10, 5);
    EXPECT_EQ(5, file.get_Buf_Size(0, 0)) << "全部倍数情况，块首,数据首";
    EXPECT_EQ(5, file.get_Buf_Size(0, 1)) << "全部倍数情况，块首,数据尾";
    EXPECT_EQ(5, file.get_Buf_Size(9, 0)) << "全部倍数情况，块尾,数据首";
    EXPECT_EQ(5, file.get_Buf_Size(9, 1)) << "全部倍数情况，块尾,数据尾";
    file.setFile(100, 15, 5);
    EXPECT_EQ(5, file.get_Buf_Size(0, 0)) << "块、数据倍数，块首,数据首";
    EXPECT_EQ(5, file.get_Buf_Size(0, 2)) << "块、数据倍数，块首,数据尾";
    EXPECT_EQ(5, file.get_Buf_Size(6, 0)) << "块、数据倍数，块尾,数据首";
    EXPECT_EQ(5, file.get_Buf_Size(6, 1)) << "块、数据倍数，块尾,数据尾";
    file.setFile(100, 10, 3);
    EXPECT_EQ(3, file.get_Buf_Size(0, 0)) << "文件、块倍数，块首,数据首";
    EXPECT_EQ(1, file.get_Buf_Size(0, 3)) << "文件、块倍数，块首,数据尾";
    EXPECT_EQ(3, file.get_Buf_Size(9, 0)) << "文件、块倍数，块尾,数据首";
    EXPECT_EQ(1, file.get_Buf_Size(9, 3)) << "文件、块倍数，块尾,数据尾";
    file.setFile(100, 15, 10);
    EXPECT_EQ(10, file.get_Buf_Size(0, 0)) << "文件、数据倍数，块首,数据首";
    EXPECT_EQ(5, file.get_Buf_Size(0, 1)) << "文件、数据倍数，块首,数据尾";
    EXPECT_EQ(10, file.get_Buf_Size(6, 0)) << "文件、数据倍数，块尾,数据首";
    EXPECT_EQ(10, file.get_Buf_Size(6, 0)) << "文件、数据倍数，块尾,数据尾";
    file.setFile(100, 15, 6);
    EXPECT_EQ(6, file.get_Buf_Size(0, 0)) << "全部不倍数，块首,数据首";
    EXPECT_EQ(3, file.get_Buf_Size(0, 2)) << "全部不倍数，块首,数据尾";
    EXPECT_EQ(6, file.get_Buf_Size(6, 0)) << "全部不倍数，块尾,数据首";
    EXPECT_EQ(4, file.get_Buf_Size(6, 1)) << "全部不倍数，块尾,数据尾";
    EXPECT_EQ(-21, file.get_Buf_Size(7, 0)) << "块序号超过最大";
    file.setFile(100, 100, 6);
    EXPECT_EQ(6, file.get_Buf_Size(0, 0)) << "块大小等于文件大小,数据首";
    EXPECT_EQ(4, file.get_Buf_Size(0, 16)) << "块大小等于文件大小,数据尾";
    EXPECT_EQ(-31, file.get_Buf_Size(0, 17)) << "数据序号超过最大";
    file.setFile(100, 200, 6);
    EXPECT_EQ(6, file.get_Buf_Size(0, 0)) << "块大小大于文件大小,数据首";
    EXPECT_EQ(4, file.get_Buf_Size(0, 16)) << "块大小大于文件大小,数据尾";
    file.setFile(100, 200, 100);
    EXPECT_EQ(100, file.get_Buf_Size(0, 0)) << "块大小大于文件大小";
    file.setFile(100, 200, 150);
    EXPECT_EQ(100, file.get_Buf_Size(0, 0)) << "发送大小等于文件大小";
}
TEST(File,file_SIZE){
    File file;
    EXPECT_EQ(-1,file.file_Size())<<"未初始化文件名";
    file.setFileName(PATH, "11.txt");
    EXPECT_EQ(-2,file.file_Size())<<"文件或路径错误";
    file.setFileName(PATH, "1.txt");
    EXPECT_EQ(3099,file.file_Size())<<"正确3099";
}
TEST(File,newFile){
    File file;
    EXPECT_EQ(false,file.newFile())<<"未定义文件名及路径";
    file.setFileName(PATH, "newFile.txt");
    EXPECT_EQ(true,file.newFile())<<"文件不存在，创建文件";
    file.setFileName(PATH, "newFile.txt");
    EXPECT_EQ(true,file.newFile())<<"文件存在，清空文件所有内容";
    EXPECT_EQ(0,remove("/Users/necromaner/test/gtest/newFile.txt"))<<"文件删除失败";
}
TEST(File,readWrite) {
    File file;
    std::string zzz = "1.zip";
    std::string zz1 = "Text_" + zzz;
    file.setFileName(PATH, zz1);
    file.newFile();
    file.setFileName(PATH, zzz);
    file.setFile(file.file_Size(), 1000000, 10);
    long long int bN=file.get_Block_Num();

    std::string xx;
    std::string xx1;
    for (int i = 0; i <=bN ; ++i) {
        char *x = file.readFile(i);
        file.setFileName(PATH, zz1);
        file.writeFile(x, i);
        file.setFileName(PATH, zzz);
        char *x1 = file.readFile(i);
        xx=x;
        xx1=x1;
        EXPECT_EQ(xx, xx1) << i << "行错误";
        delete[] x;
        delete[] x1;
    }
}
TEST(File,readFile){
    File file;
    file.setFileName(PATH, "read.zip");     //1.设置文件信息
    file.setFile(file.file_Size(), 10, 10); //2.设置传输信息

    char *x = file.readFile(0);
    std::string xx=x;
    std::string xx1="PK\x3\x4\x14";
    EXPECT_EQ(xx,xx1)<<"首";
    MD5 md5_0(xx);
    MD5 md5_1(xx1);
    EXPECT_EQ(md5_0.toStr(),md5_1.toStr())<<"md5-首";
    file.setFile(file.file_Size(), 100, 10);
    char *x2 = file.readFile(1000);
    std::string xx2=x2;
    EXPECT_EQ(xx2,"error")<<"超过序号范围";
}
TEST(File,writeFile){
    File file;
    file.setFileName(PATH, "write.zip");   //1.设置文件信息
    file.newFile();                        //2.新建文件
    file.setFile(20, 10, 10);              //3.设置传输信息

    char x[11]="PK\x3\x4\x14";
    EXPECT_EQ(false,file.writeFile(x,10000))<<"超过序号范围";
    EXPECT_EQ(true,file.writeFile(x,0))<<"0";
    char *x1 = file.readFile(0);
    std::string xx1=x1;
    char *x2 = file.readFile(1);
    std::string xx2=x2;
    EXPECT_EQ(x,xx1)<<"首";
    MD5 md5_0(x);
    MD5 md5_1(x1);
    EXPECT_EQ(md5_0.toStr(),md5_1.toStr())<<"md5-首";
//    EXPECT_EQ("",xx2)<<"1无";
//    MD5 md5_2("");
//    MD5 md5_3(xx2);
//    EXPECT_EQ(md5_2.toStr(),md5_3.toStr())<<"md5-1无";
    EXPECT_EQ(true,file.writeFile(x,1))<<"1";
    EXPECT_EQ(x,xx1)<<"1有";
    MD5 md5_4(x);
    MD5 md5_5(xx1);
    EXPECT_EQ(md5_4.toStr(),md5_5.toStr())<<"md5-1有";
    EXPECT_EQ(false,file.writeFile(x,2))<<"error";
}
TEST(File,addMap){
    File file;
    Other other;
    std::map<int,char*> x;
    std::set<long long> y;
    file.setFile(40, 20, 5);
    int blocknum=0;
    bool yes=false;
    EXPECT_EQ(20,file.get_Block_Size(blocknum))<<"块大小";
    char* block=new char[file.get_Block_Size(blocknum)];
    EXPECT_EQ(3,file.get_Buf_Num(blocknum))<<"传输序号";
    y=other.initialization_Set(file.get_Buf_Num(blocknum)+1);
    EXPECT_EQ(4,y.size())<<"set序号长度";
    EXPECT_EQ(0,x.size())<<"map序号长度";

    int nums=0;
    int error=0;
    while (1){
        char* buf=new char[5];
        sprintf(buf,"--%d--",nums);
        if(file.addMap(x,y,block,buf,blocknum,nums++)){
            yes=true;
            break;
        }
        if(error++>20){
            EXPECT_EQ(4,x.size())<<"map error";
            EXPECT_EQ(0,y.size())<<"set error";
            break;
        }
    }
    if(yes){

    }

    delete[] block;
}
TEST(File,mergeMap){
    File file;
    Other other;
    std::map<int,char*> x;
    char* block=new char[20];
    char* result=new char[20];
    char* buf1=new char[5];
    char* buf2=new char[5];
    char* buf3=new char[5];
    char* buf4=new char[5];
    sprintf(buf1,"1111");
    sprintf(buf2,"2222");
    sprintf(buf3,"3333");
    sprintf(buf4,"4444");
    sprintf(result,"1111222233334444");
    string s=result;
    x[0]=buf1;
    x[3]=buf4;
    x[1]=buf2;
    x[2]=buf3;
    block=file.mergeMap(x,0);
    EXPECT_EQ(s,block)<<"合并";
    delete[] block;
}
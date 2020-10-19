#include <iostream>
#include <gtest/gtest.h>
#include "Send.h"
#include "md5.h"










//int Foo(int a, int b)
//{
//    if (a == 0 || b == 0)
//    {
//        throw "别这样做";
//    }
//    int c = a % b;
//    if (c == 0)
//        return b;
//    return Foo(b, c);
//}
//TEST(FooTest, HandleZeroInput)
//{
//    EXPECT_ANY_THROW(Foo(10, 0));
////    EXPECT_THROW(Foo(10, 0), char*);
//}
//TEST(testCase, test6){
//    string str1 = "Abc";
//    string str2 = "abc";
//    ASSERT_STRCASEEQ(str1.c_str(),str2.c_str());
//}
//testing::AssertionResult AssertFoo(const char* m_expr, const char* n_expr, const char* k_expr, int m, int n, int k) {
//    if (Foo(m, n) == k)
//        return testing::AssertionSuccess();
//    testing::Message msg;
//    msg << m_expr << " 和 " << n_expr << " 的最大公约数应该是：" << Foo(m, n) << " 而不是：" << k_expr;
//    return testing::AssertionFailure(msg);
//}
//
//TEST(AssertFooTest, HandleFail)
//{
//    EXPECT_PRED_FORMAT3(AssertFoo, 3, 6, 3);
//}








TEST(testCase, test0){
    EXPECT_EQ(149732669, file_size("/Users/necromaner/test/send/4.zip"));
    EXPECT_EQ(480, file_size("/Users/necromaner/test/send/"));
}
TEST(testCase, test1){
    EXPECT_EQ("1bc29b36f623ba82aaf6724fd3b16718",MD5("md5").toStr());
    EXPECT_EQ("8d6c0760e7dae464f181d5fb9f6d3cb0",MD5("Md5").toStr());
    EXPECT_EQ("e091051e305878ec231cbd7cc0ad38f7",MD5("Md\n5").toStr());
}

void charBegin(char*block){
    for (int i = 0; i < 50; ++i) {
        block[i]='0';
    }
    
}

string andchar(){
    char q[51]="";
    printf("==%s\n",q);
    charBegin(q);
    printf("==%s\n",q);
    char x1[11]="1111111111";
    char x2[11]="2222222222";
    char x3[11]="3333333333";
    char x4[11]="4444444444";
    char x5[11]="5555555555";
    memcpy(q,x1,strlen(x1));
    memcpy(q+20,x3,strlen(x3));
    memcpy(q+10,x2,strlen(x2));
    memcpy(q+30,x4,strlen(x4));
    memcpy(q+40,x5,strlen(x5));
    printf("==%s\n",q);
    return q;
}

TEST(testCase, andchar){
    EXPECT_EQ("11111111112222222222333333333344444444445555555555",andchar());
}

string split(){
    char q[51]="11111111112222222222333333333344444444445555555555";
    char x[11]="";
    memcpy()
    printf("\n++%s\n",x);
    return x;
}


TEST(testCase, split){
    EXPECT_EQ("1",split());
}

void open(int i){
    string file1="/Users/necromaner/test/send/";
    string file2="1.zip";
    string file=file1+file2;
    char block[1000];
    FILE *fp;
    fp = fopen(file.c_str(), "r");
    fseek(fp, i*1000, SEEK_SET);
    fread(block, sizeof(char),1000, fp);
    fclose(fp);
    printf("%s\n",block);
}







int main(int argc, char ** argv) {
    open(0);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // 执行所有的 test case
}
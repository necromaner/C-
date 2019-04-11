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

TEST(APP_dev,T1){
    MD5_add md5_add("/Users/necromaner/file/md5test/md5.txt","/Users/necromaner/file/md5test/test.txt");
}
TEST(APP_dev,md5){
    MD5 md5("1");
    EXPECT_EQ("c4ca4238a0b923820dcc509a6f75849b", md5.toStr());
}
TEST(APP_dev,readFile){
    File file;
    MD5 md5(file.readFile("/Users/necromaner/file/md5test/md5.txt"));
    EXPECT_EQ("c4ca4238a0b923820dcc509a6f75849b", md5.toStr());
}
TEST(APP_dev,file_Size){
    File file;
    EXPECT_EQ(1, file.file_Size("/Users/necromaner/file/md5test/md5.txt"))<<"文件存在返回文件大小";
    EXPECT_EQ(-2, file.file_Size("/Users/necromaner/file/md5test/md51.txt"))<<"文件不存在返回-2";
    EXPECT_EQ(-2, file.file_Size("/Users/necromaner/file/md5tes/md51.txt"))<<"路径不存在返回-2";
}
TEST(APP_dev,writeFile){
    File file;
    file.newFile("/Users/necromaner/file/md5test/test.txt");
    EXPECT_EQ(false, file.writeFile("/Users/necromaner/file/md5test/test.txt","123",3))<<"追加写入";
    EXPECT_EQ(false, file.writeFile("/Users/necromaner/file/md5test/test.txt","123",3))<<"追加写入";
    EXPECT_EQ(false, file.writeFile("/Users/necromaner/file/md5test/test.txt","123",3))<<"追加写入";
}
TEST(APP_dev,ADD){
    File file;
    string old_file="/Users/necromaner/file/md5test/AglMcu.bin";
    string new_file="/Users/necromaner/file/md5test/AglMcu1.bin";

    unsigned long file_Size=file.file_Size(old_file);
    char *file_Data=file.readFile(old_file,64);
    MD5 md5(file_Data);

    string file_Md5=md5.toStr();
    EXPECT_EQ("5e897be6821b8b7bbaf01d5b3990cb90", md5.toStr());
    unsigned long md5_Size=file_Md5.length();
    EXPECT_EQ(32, md5_Size);

    file.newFile(new_file);
    char *data=new char[md5_Size];
    sprintf(data,"%s",file_Md5.c_str());
    file.writeFile(new_file,data,md5_Size);
    file.writeFile(new_file,file_Data,file_Size);


    char *file_Data1=file.readFile(old_file,0,64);
    printf("----------------------------\n%s\n----------------------------",file_Data1);
}
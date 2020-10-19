//
// Created by necromaner on 2018/12/10.
//

#ifndef CLIENT_OTHER_H
#define CLIENT_OTHER_H

#include <sys/time.h>                                 //时间
#include <string>                                     //string
#include <set>                                        //set
//#include "gtest/gtest_prod.h"                         //私有测试
#define         TIME_MAX     8640000000                 //100天
#define         TIME_D       86400000                   //1天
#define         TIME_H       3600000                    //1小时
#define         TIME_M       60000                      //1分钟
#define         TIME_S       1000                       //1秒
#define         TIME_MS      1                          //1毫秒
#define         TIME_10      10                         //用于进位
#define         TIME_HALF    500                        //半秒

#define         SPEED_B      " B/s"
#define         SPEED_K      " K/s"
#define         SPEED_M      " M/s"
#define         SPEED_G      " G/s"
#define         SPEED_T      " T/s"
#define         SPEED_P      " P/s"
#define         SPEED        1024                     //速度进制
#define         SPEED_MAX    (1125899906842624*11)    //最大文件大小 0x44'000'000'000'000
#define         ZERO         0                        //零
class Other {                                         //其他类
private:
    std::string speed(long long bs);                  //速度主要方法
public:
    int64_t getCurrentTime();                         //获取毫秒级试时间戳
    std::string theJetLag(time_t beginTime,time_t endTime);//时间差
    std::string date(time_t unix);                    //日期
    std::string speed(unsigned long long byte,time_t unix);//速度

    std::string set_To_String(std::set<long long> y,const std::string& delim);//set序列化
    std::set<long long> string_to_Set(std::string str,const std::string& delim);//set反序列化
    std::set<long long> initialization_Set(long long num);//块序号初始化
};
class File {                                          //文件操作类
private:
    FILE *fp;                                         //文件
    long long size;                                   //文件大小
    int block;                                        //文件块大小
    int send;                                         //文件发送大小
    std::string file1 = "";                           //文件路径
    std::string file2 = "";                           //文件名
    char error[6]="error";
    bool fileName;                                    //判断文件路径是否定义
    bool fileMessage;                                 //判断文件信息是否定义
    int checkProblem();                               //检查问题文件大小问题-已创建测试用例
    void Initialize();                                //初始化
//    FRIEND_TEST(File, checkProblem);                  //private测试
public:
    File();                                           //构造函数
    virtual ~File();                                  //析构函数

    long long file_Size();                            //文件大小-已创建测试用例
    void setFileName(const std::string &file1, const std::string &file2);//设置文件名及路径-已创建测试用例
    const std::string &getFile2() const;              //获得文件名-已创建测试用例
    std::string getFileName();                        //文件完整路径-已创建测试用例

    int setFile(long long int size, int block, int send);//设置文件信息-已创建测试用例
    long long int getSize() const;                    //获取文件大小-已创建测试用例
    long long int getBlock() const;                   //获取文件块大小-已创建测试用例
    long long int getSend() const;                    //获取文件发送大小-已创建测试用例

    long long int get_Block_Num();                    //获得块最大块序-已创建测试用例
    int get_Block_Size(long long int blockNum);       //当前块的理论大小-已创建测试用例
    int get_Buf_Num(long long int blockNum);          //获取当前块的发送最大序号-已创建测试用例
    int get_Buf_Size(long long int blockNum, int bufNum);//当前数据的理论大小-已创建测试用例

    char *readFile(long long num);                    //读取文件块-已创建测试用例
    bool writeFile(char *buf, long long num);         //写入文件块-已创建测试用例
    bool newFile();                                   //创建新文件-已创建测试用例
};
#endif                                                //CLIENT_OTHER_H

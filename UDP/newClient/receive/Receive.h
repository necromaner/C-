//
// Created by 温亚奇 on 2018/9/23.
//

#ifndef NEWCLIENT_RECEIVE_H
#define NEWCLIENT_RECEIVE_H

#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>


#define    FINISH_FLAG    "FILE_TRANSPORT_FINISH"
#define    CORRECT_FLAG    "FILE_TRANSPORT_CORRECT"
#define    AFFIRM_FLAG    "AFFIRM_TRANSPORT_FINISH"
#define    MAXSIZE          984
#define    MAXLENGTH        100

using namespace std;

//文件信息
//name：文件名称
//size:文件大小
//max：一次最多发送数据的大小
struct FileInformation{
    string name;
    long size;
    int max;
};
//数据块
//buf：当前发送的数据
//num:当前发送的数据的序号
//md5:数据对应的md5
struct Data{
    char buf[984];
    int num;
//    char md5[32];
    unsigned char chSha1[20]= "";
};
//成功写入的序号
//suc:成功写入片段
//max:未成功接收量
struct Success{
//    vector<int> suc;
    int suc[100]={0};
    int max=0;
};
//enum FLAG{FINISH,CORRECT，AFFIRM};
class Receive{
private:
public:
    void receive(int sc,sockaddr_in server_addr);
};

#endif //NEWCLIENT_RECEIVE_H

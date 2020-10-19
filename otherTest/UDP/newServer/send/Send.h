
#ifndef NEWSERVER_SEND_H
#define NEWSERVER_SEND_H

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
struct FileInformation{
    string name;
    long size;
    int max;
};
struct Data{
    char buf[MAXSIZE];
    int num;
    string md5;
};
//成功写入的序号
//suc:成功写入片段
//max:一次最多发送的量
struct Success {
    int suc[MAXLENGTH];
    int max;
};
class Send{
private:
public:
    void send(int ss,sockaddr_in server_addr);
};


#endif //NEWSERVER_SEND_H

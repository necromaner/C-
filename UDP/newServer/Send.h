
#ifndef NEWSERVER_SEND_H
#define NEWSERVER_SEND_H

#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

#define    FINISH_FLAG    "FILE_TRANSPORT_FINISH"
#define    CORRECT_FLAG    "FILE_TRANSPORT_CORRECT"
#define    AFFIRM_FLAG    "AFFIRM_TRANSPORT_FINISH"

using namespace std;

struct FileInformation{
    string name;
    long size;
    int max;
};
struct Data{
    char buf[984];
    int num;
    string md5;
};

//成功写入的序号
//suc:成功写入片段
//max:一次最多发送的量
struct Success{
//    vector<int> suc;
    int suc[100];
    int max;
};
void send(int ss,sockaddr_in server_addr);


void outPut();

void outPut(vector<int> s);
void outPut(int output,vector<int> s);
void outPut(string output,vector<int> s);

void outPut(vector<bool> s);
void outPut(int output,vector<bool> s);
void outPut(string output,vector<bool> s);

void outPut(vector<string> s);
void outPut(int output,vector<string> s);
void outPut(string output,vector<string> s);

//void outPut(vector<ListNode*>& s);
//void outPut(int output,vector<ListNode*>& s);
//void outPut(string output,vector<ListNode*>& s);


void outPut(vector<vector<int>> s);
void outPut(int output,vector<vector<int>> s);
void outPut(string output,vector<vector<int>> s);

void outPut(int s);
void outPut(int output,int s);
void outPut(string output,int s);

void outPut(bool s);
void outPut(int output,bool s);
void outPut(string output,bool s);

void outPut(string s);
void outPut(int output,string s);
void outPut(string output,string s);

void outPut(double s);
void outPut(int output,double s);
void outPut(string output,double s);

//void outPut(ListNode *s);
//void outPut(int output,ListNode *s);
//void outPut(string output,ListNode *s);
#endif //NEWSERVER_SEND_H

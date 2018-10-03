#ifndef T2_LISTNODE_H
#define T2_LISTNODE_H
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void outPut(ListNode *s);//输出
ListNode* build(vector<int> x);//新建
void insert(ListNode *&s,int x);//添加
void close(ListNode *&s,int x);//删除
void closeAll(ListNode *&s);//清空链表
#endif //T2_LISTNODE_H

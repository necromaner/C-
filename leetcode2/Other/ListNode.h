//
// Created by necromaner on 2020/9/14.
//

#ifndef LEETCODE2_LISTNODE_H
#define LEETCODE2_LISTNODE_H
#include <vector>
struct ListNode {                                                            //链表
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *SetListNode(std::vector<int> list);
std::vector<int> GetListNode(ListNode *list);



#endif //LEETCODE2_LISTNODE_H

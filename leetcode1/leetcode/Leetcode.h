//
// Created by necromaner on 2019-10-30.
//

#ifndef LEETCODE1_LEETCODE_H
#define LEETCODE1_LEETCODE_H

#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *SetListNode(vector<int> list);
    vector<int> GetListNode(ListNode * list);
    //1-50
    vector<int> twoSum(vector<int>& nums, int target);//1. 两数之和
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);//2. 两数相加
    int reverse(int x);//7. 整数反转
    //51-100
};



#endif //LEETCODE1_LEETCODE_H

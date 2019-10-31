//
// Created by necromaner on 2019-10-30.
//

#ifndef LEETCODE1_LEETCODE_H
#define LEETCODE1_LEETCODE_H

#include <vector>
#include <string>
#include <iostream>
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
    bool isPalindrome(int x);//9. 回文数
    int romanToInt(string s);//13. 罗马数字转整数
    string longestCommonPrefix(vector<string>& strs);//14. 最长公共前缀
    vector<vector<int>> threeSum(vector<int> &nums);//15. 三数之和
    void threeSum1(vector<int> &nums,vector<vector<int>> &answer,vector<int> &answer1,int i,int j,int k);//15. 三数之和
    bool isValid(string s);//20. 有效的括号
    vector<string> generateParenthesis(int n);//22. 括号生成
    void dfs(vector<string> &answer, string &answer1, int n, int digit, int leftparenthesis);//22. 括号生成
    int removeDuplicates(vector<int> &nums);//26. 删除排序数组中的重复项
    int removeElement(vector<int> &nums, int val);//27. 移除元素
    vector<int> searchRange(vector<int> &nums, int target);//34. 在排序数组中查找元素的第一个和最后一个位置
    string countAndSay(int n);//38. 报数
    void countAndSay1(string &answer);//38. 报数
    //51-100
    vector<vector<int>> subsets(vector<int> &nums);//78. 子集
    void subsets1(vector<vector<int>> &answer, vector<int> &answer1, vector<int> &nums, int k, int st);//78. 子集
    //101-150
    int minimumTotal(vector<vector<int>> &triangle);
    void minimumTotal1(vector<vector<int>> triangle,vector<vector<int>> &xx, int &aa, int i, int j);
    //151-200
    //201-250
    //251-300
    void moveZeroes(vector<int>& nums);//283. 移动零
};



#endif //LEETCODE1_LEETCODE_H

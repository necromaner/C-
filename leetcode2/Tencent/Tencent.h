//
// Created by necromaner on 2020/7/22.
//

#ifndef LEETCODE2_TENCENT_H
#define LEETCODE2_TENCENT_H

#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

//struct ListNode {//链表
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//struct TreeNode {//二叉树
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
class Tencent {
public:
    ////数组与字符串
    vector<int> twoSum(vector<int>& nums, int target);//1 两数之和
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);//T2 两个排序数组的中位数
    string longestPalindrome(string s);//T3 最长回文子串
    int myAtoi(string str);//T4 字符串转整数 (atoi)
    string longestCommonPrefix(vector<string>& strs);//T5 最长公共前缀
    vector<vector<int>> threeSum(vector<int>& nums);//T6 三数之和
    vector<vector<int>> threeSum1(vector<int>& nums);//T6 三数之和
    int threeSumClosest(vector<int> nums, int target);//T7 最接近的三数之和
    bool isValid(string s);//T8 有效的括号
    int removeDuplicates(vector<int>& nums);//T9 删除排序数组中的重复项
    int maxArea1(vector<int>& height);//T10 盛最多水的容器
    int maxArea(vector<int>& height);//T10 盛最多水的容器
    string multiply(string num1, string num2);//T11 字符串相乘
    string reverseString(string s);//T11 字符串相乘
    string reverseWords(string s);//T12 反转字符串
    vector<int> productExceptSelf1(vector<int>& nums);//T13 反转字符串中的单词 III
    vector<int> productExceptSelf(vector<int>& nums);//T14 除自身以外数组的乘积
    bool containsDuplicate(vector<int>& nums);//T15 存在重复元素
    vector<int> spiralOrder(vector<vector<int>>& matrix);//T16 螺旋矩阵
    vector<vector<int>> generateMatrix(int n);//T17 螺旋矩阵 II
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);//T18 合并两个有序数组





};


#endif //LEETCODE2_TENCENT_H

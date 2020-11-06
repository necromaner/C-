#include "../leetcode.h"
//349. 两个数组的交集
/*
给定两个数组，编写一个函数来计算它们的交集。

示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]

说明：
    输出结果中的每个元素一定是唯一的。
    我们可以不考虑输出结果的顺序。
 */
vector<int> Leetcode::intersection(vector<int>& nums1, vector<int>& nums2) {//2020-11-02
////    执行用时：16 ms, 在所有 C++ 提交中击败了39.19% 的用户
////    内存消耗：11 MB, 在所有 C++ 提交中击败了5.05% 的用户
//    vector<int> ans;
//    unordered_set<int> num1, num2;
//    for (auto i:nums1)
//        num1.insert(i);
//    for (auto i:nums2)
//        num2.insert(i);
//    for (auto i:num1) {//求交集
//        if (num2.find(i) != num2.end())
//            ans.push_back(i);
//    }
//    return ans;

//    执行用时：8 ms, 在所有 C++ 提交中击败了96.25% 的用户
//    内存消耗：10.3 MB, 在所有 C++ 提交中击败了62.24% 的用户
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int size1 = nums1.size(), size2 = nums2.size(), n1 = 0, n2 = 0;
    vector<int> ans;
    while (n1 < size1 && n2 < size2) {
        if (nums1[n1] > nums2[n2])
            n2++;
        else if (nums1[n1] < nums2[n2])
            n1++;
        else {
            if (ans.empty() || nums1[n1] != ans.back())
                ans.push_back(nums1[n1]);
            n1++;
            n2++;
        }
    }
    return ans;
}
vector<int> t349_1(unordered_set<int>& set1, unordered_set<int>& set2) {
    if (set1.size() > set2.size()) {
        return t349_1(set2, set1);
    }
    vector<int> intersection;
    for (auto& num : set1) {
        if (set2.count(num)) {
            intersection.push_back(num);
        }
    }
    return intersection;
}
vector<int> intersection_1(vector<int>& nums1, vector<int>& nums2) {//抄
////    执行用时：16 ms, 在所有 C++ 提交中击败了39.19% 的用户
////    内存消耗：11.1 MB, 在所有 C++ 提交中击败了5.05% 的用户
////    方法一：两个集合
//    unordered_set<int> set1, set2;
//    for (auto& num : nums1) {
//        set1.insert(num);
//    }
//    for (auto& num : nums2) {
//        set2.insert(num);
//    }
//    return t349_1(set1, set2);

//    执行用时：8 ms, 在所有 C++ 提交中击败了96.25% 的用户
//    内存消耗：10.3 MB, 在所有 C++ 提交中击败了61.36% 的用户
//    方法二：排序 + 双指针
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int length1 = nums1.size(), length2 = nums2.size();
    int index1 = 0, index2 = 0;
    vector<int> intersection;
    while (index1 < length1 && index2 < length2) {
        int num1 = nums1[index1], num2 = nums2[index2];
        if (num1 == num2) {
            // 保证加入元素的唯一性
            if (!intersection.size() || num1 != intersection.back()) {
                intersection.push_back(num1);
            }
            index1++;
            index2++;
        } else if (num1 < num2) {
            index1++;
        } else {
            index2++;
        }
    }
    return intersection;
}

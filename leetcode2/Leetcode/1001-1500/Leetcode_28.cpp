#include "../leetcode.h"

//1365. 有多少小于当前数字的数字
/*
给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。
以数组形式返回答案。

示例 1：
输入：nums = [8,1,2,2,3]
输出：[4,0,1,1,3]
解释：
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。
对于 nums[3]=2 存在一个比它小的数字：（1）。
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。

示例 2：
输入：nums = [6,5,4,8]
输出：[2,1,0,3]

示例 3：
输入：nums = [7,7,7,7]
输出：[0,0,0,0]

提示：
    2 <= nums.length <= 500
    0 <= nums[i] <= 100
 */
vector<int> Leetcode::smallerNumbersThanCurrent(vector<int>& nums) {//2020-10-26
//    执行用时：8 ms, 在所有 C++ 提交中击败了85.34% 的用户
//    内存消耗：10.3 MB, 在所有 C++ 提交中击败了5.90% 的用户
        vector<int> num(101, 0);
        int size = nums.size();
        for (auto c:nums) {
            num[c]++;
        }
        for (int i = 1; i < 101; ++i) {
            num[i] += num[i - 1];
        }
        vector<int> ans(size);
        for (int j = 0; j < size; ++j) {
            if (nums[j] == 0)
                ans[j] = 0;
            else
                ans[j] = num[nums[j] - 1];
        }
        return ans;
}
vector<int> smallerNumbersThanCurrent_1(vector<int>& nums) {//抄
////    执行用时：60 ms, 在所有 C++ 提交中击败了34.34% 的用户
////    内存消耗：10 MB, 在所有 C++ 提交中击败了16.50% 的用户
////    方法一：暴力
//    vector<int> ret;
//    int n = nums.size();
//    for (int i = 0; i < n; i++) {
//        int cnt = 0;
//        for (int j = 0; j < n; j++) {
//            if (nums[j] < nums[i]) {
//                cnt++;
//            }
//        }
//        ret.push_back(cnt);
//    }
//    return ret;
//    执行用时：12 ms, 在所有 C++ 提交中击败了70.52% 的用户
//    内存消耗：10.6 MB, 在所有 C++ 提交中击败了5.06% 的用户
//    方法二：快速排序
    vector<pair<int, int>> data;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        data.emplace_back(nums[i], i);
    }
    sort(data.begin(), data.end());

    vector<int> ret(n, 0);
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (prev == -1 || data[i].first != data[i - 1].first) {
            prev = i;
        }
        ret[data[i].second] = prev;
    }
    return ret;
}
#include "../leetcode.h"
//416. 分割等和子集
/*
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
注意:
    每个数组中的元素不会超过 100
    数组的大小不会超过 200

示例 1:
输入: [1, 5, 11, 5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].

示例 2:
输入: [1, 2, 3, 5]
输出: false
解释: 数组不能分割成两个元素和相等的子集.
 */
bool T416_1(vector<int>& nums,int numsSum,int now) {
    while (now >= 0) {
        int nowSum = numsSum - nums[now];
        if (nowSum == 0)
            return true;
        else if (nowSum < 0)
            return false;
        int now1 = now;
        while (now1 >= 0) {
            if (T416_1(nums, nowSum, --now1))
                return true;
        }
        now--;
    }
    return false;
}
bool Leetcode::canPartition(vector<int>& nums) {
    /*思考:
     * 1.数组和必定为偶数
     * 2.最大数字不能大于数组和
     * 3.从大到小能够累加到数组和的一半即可
     */
    //超时
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (auto aa:nums)
        sum += aa;
    if (sum % 2 != 0 || nums[nums.size() - 1] > sum / 2)
        return false;
    return T416_1(nums, sum / 2, (int) nums.size() - 1);
}
bool Leetcode::canPartition_1(vector<int>& nums) {
//    执行用时：232 ms, 在所有 C++ 提交中击败了69.21% 的用户
//    内存消耗：73.6 MB, 在所有 C++ 提交中击败了5.02% 的用户
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
}
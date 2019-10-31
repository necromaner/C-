#include "Leetcode.h"
//78. 子集
/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。

示例:
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */
//执行用时 :4 ms, 在所有 cpp 提交中击败了99.85% 的用户
//内存消耗 :9.1 MB, 在所有 cpp 提交中击败了67.75%的用户
vector<vector<int>> Solution::subsets(vector<int> &nums) {//nums.begin()+k
    vector<vector<int>> answer;
    vector<int> answer1;
    for (int k = 0; k <= nums.size(); k++) {            //控制输出个数
        subsets1(answer, answer1, nums, k, 0);
    }
    return answer;
}
void Solution::subsets1(vector<vector<int>> &answer, vector<int> &answer1, vector<int> &nums, int k, int st) {
    if (k == 0) {
        answer.push_back(answer1);
        return;
    }
    for (int i = st; i < nums.size(); i++) {
        answer1.push_back(nums[i]);
        subsets1(answer, answer1, nums, k - 1, i + 1);
        answer1.pop_back();//删除数组元素
    }
}



#include "../leetcode.h"
//154. 寻找旋转排序数组中的最小值 II
/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
请找出其中最小的元素。
注意数组中可能存在重复的元素。

示例 1：
输入: [1,3,5]
输出: 1
示例 2：
输入: [2,2,2,0,1]
输出: 0
说明：
    这道题是 寻找旋转排序数组中的最小值 的延伸题目。
    允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
 */
int Leetcode::findMin(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int min=nums[0];
    for(auto aa:nums){
        if(aa<min)
            return aa;
    }
    return min;
}
//167. 两数之和 II - 输入有序数组
/*
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
说明:
    返回的下标值（index1 和 index2）不是从零开始的。
    你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:
输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 */
vector<int> Leetcode::twoSum1(vector<int>& numbers, int target) {//超时
    vector<int> answer;
    int size = numbers.size();
    for (int i = 0; i < size - 1; ++i) {
        int left = numbers[i];
        if (left > target)
            return answer;
        else if (left == target && left > 0)
            return answer;
        for (int j = i + 1; j < size; ++j) {
            int right = numbers[j];
            if (left + right == target) {
                answer = {i + 1, j + 1};
                return answer;
            } else if (left + right > target)
                break;
        }
    }
    return answer;
}
vector<int> Leetcode::twoSum2(vector<int>& numbers, int target) {//超时
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum > target) {
            right--;
        } else if (sum < target) {
            left++;
        } else
            return {left + 1, right + 1};
    }
    return {};
}

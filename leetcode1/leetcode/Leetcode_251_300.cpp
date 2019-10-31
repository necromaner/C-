#include "Leetcode.h"
//283. 移动零
/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
 */
//执行用时 :16 ms, 在所有 cpp 提交中击败了92.98% 的用户
//内存消耗 :9.5 MB, 在所有 cpp 提交中击败了49.31%的用户
void Solution::moveZeroes(vector<int>& nums) {
    int bb = 0;
    int cc;
    for (int i = 0; i < nums.size(); i++) {
        if(nums[i]==0){
            ++bb;
        } else {
            nums[i - bb] = nums[i];
        }
    }
    for(int j=bb;j>0;j--){
        nums[nums.size()-j]=0;
    }
}
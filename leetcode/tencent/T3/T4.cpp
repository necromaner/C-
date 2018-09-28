#include "../Output.h"
/*
求众数
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3

示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2



class Solution {
public:
    /*
     * 1.排序（
     * 1>长度奇数：中间的就是最多的
     * 2>长度偶数：1)中间前后一样，中间前为最多的
     *            2)中间前后不一样,第一个跟中间前一样为中间前为最多的
     *                           最后一个跟中间后一样为中间后为最多的
     */
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ns=nums.size();
        if (nums[ns / 2] != 0 || nums[ns / 2] == nums[ns / 2 + 1] ||
            nums[0] == nums[ns / 2])
            return nums[ns / 2];
        else
            return nums[ns / 2 + 1];
    }
    int majorityElement1(vector<int>& nums) {
        
        int max=0;
        int maxNum=nums[0];
        int ns=nums.size();
        for (int i = 0; i < ns-1; ++i) {
            int max1=0;
            for (int j = 0; j < ns; ++j) {
                if(nums[i]==nums[j]){
                    max1++;
                }
            }
            if(max1>max){
                max=max1;
                maxNum=nums[i];
            }
        }
        return maxNum;
    }
};
int main() {
    problem(__FILE__,"求众数\n"
            "给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。\n"
            "你可以假设数组是非空的，并且给定的数组总是存在众数。");
    Solution solution;
    vector<int> nums={1,1,1,2,3,4,1,2,2,2,2,2};
    outPut(0,nums);
    
    outPut(1,solution.majorityElement(nums));
    outPut(1,nums);
    return 0;
}
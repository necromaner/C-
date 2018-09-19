#include "../Output.h"
/*
除自身以外数组的乘积
给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]

说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

 */
class Solution {
public:
    vector<int> productExceptSelf1(vector<int>& nums) {//超时
        int ns=nums.size();
        vector<int> answer(ns,1);
        for (int i = 0; i < ns; ++i) {
            for (int j = 0; j < ns; ++j) {
                if(i!=j){
                    answer[i]*=nums[j];
                }
            }
        }
        return answer;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int ns = nums.size();
        if (ns < 1)
            return {0};
        int max = 1;
        int zero = 0;
        for (int i = 0; i < ns; ++i) {
            if (nums[i] != 0)
                max *= nums[i];
            else
                zero++;
        }
        if(zero==ns)
            return vector<int>(ns,0);
        for (int j = 0; j < ns; ++j) {
            if (nums[j] != 0) {
                if (!zero)
                    nums[j] = max / nums[j];
                else
                    nums[j] = 0;
            } else {
                if(zero==1)
                    nums[j] = max;
                else
                    nums[j]=0;
            }
        }
        return nums;
    }

};
int main() {
    problem(__FILE__,"除自身以外数组的乘积\n"
            "给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。");
    Solution solution;
    vector<int> nums={1,2,3,4,0,0};
    outPut(0,nums);
    
    outPut(1,solution.productExceptSelf(nums));
    return 0;
}
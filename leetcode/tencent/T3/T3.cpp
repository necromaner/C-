#include "../Output.h"
/*
只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1

示例 2:

输入: [4,1,2,1,2]
输出: 4


 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[0] ^= nums[i];//nums[0]=nums[0]^nums[i],把nums[0]和nums[i]进行异或运算，因为每个元素均出现两次，所有元素都进行异位运算，那么相同的两个异位运算为0，最终只剩于一个。
        }
        return nums[0];
    }
    int singleNumber1(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        int end=nums.size();
        for (int i = 0; i < end; ++i) {
            bool same=false;
            for (int j = i+1; j < end; ++j) {
                if(nums[i]==nums[j]){
                    nums[j]=nums[end-1];
                    end--;
                    same=true;
                    break;
                }
            }
            if(!same)
                return nums[i];
        }
        return NULL;
    }
};
int main() {
    problem(__FILE__,"只出现一次的数字\n"
            "给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。");
    Solution solution;
    vector<int> nums={-1,-1,-2};
    outPut(0,nums);
    
    outPut(1,solution.singleNumber(nums));
    outPut(1,nums);
    return 0;
}
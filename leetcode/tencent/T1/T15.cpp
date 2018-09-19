#include "../Output.h"
/*
存在重复元素
给定一个整数数组，判断是否存在重复元素。
如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true

示例 2:

输入: [1,2,3,4]
输出: false

示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true


 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int ns=nums.size();
        sort(nums.begin(),nums.end());
        nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
        if(nums.size()!=ns)
            return true;
        return false;
    }
};
int main() {
    problem(__FILE__,"存在重复元素\n"
            "给定一个整数数组，判断是否存在重复元素。\n"
            "如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。");
    Solution solution;
    vector<int> nums={5,2,3,4,5};
    outPut(0,nums);
    
    outPut(1,solution.containsDuplicate(nums));
    outPut("nums",nums);
    return 0;
}
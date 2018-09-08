#include "../Output.h"
/*
两数之和

给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]


 */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {//完成60 ms
        vector<int> answer(2,0);
        int N = nums.size();
        for (int i = 0; i < N-1; ++i) {
            int temp = target -nums[i];
            for (int j = i+1; j < N; ++j) {
                if(temp==nums[j]) {
                    answer[0]=i;
                    answer[1]=j;
                    return answer;
                }
            }
        }
        return answer;
    }
};
int main() {
    printf("T1.两数之和\n"
                   "给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。\n"
                   "你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。");
    printf("\n\n");
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    
    printf("nums=");
    outPut(nums);
    printf("target=");
    outPut(target);
    
    printf("输出：");
    outPut(solution.twoSum(nums, target));
    return 0;
}

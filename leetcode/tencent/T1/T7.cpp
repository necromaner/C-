#include "../Output.h"
/*
最接近的三数之和
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).




 */


// 1。排序
// 2。找到第一个比target大或者相等的位置（前三个为比taeget小的，当前位置到后二为比taeget大的）例：1，2，2，2，3---2--->1
//1 2 2 3---2
//    2 3---1
// 3。找位置前三后三做对比，找差值最小的。
class Solution {
public:
    int threeSumClosest(vector<int> nums, int target) {
        sort(nums.begin(),nums.end());
        int res = 0;
        bool first = true;
        for (int i = 0; i<nums.size(); i++){
            int pa = i + 1;
            int pb = nums.size() - 1;
            while (pa<pb){
                int sum = nums[i] + nums[pa] + nums[pb];
                if (first){
                    res = sum;
                    first = false;
                }
                else if (abs(target - sum)<abs(target - res)){
                    res = sum;
                }
                if (res == target){
                    return res;
                }
                if (sum <= target){
                    pa++;
                }
                else{
                    pb--;
                }
            }
        }
        return res;
    }
};

int main() {
    printf("最接近的三数之和\n"
                   "给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。");
    printf("\n\n");
    Solution solution;
    vector<int> strs={0,2,1,-3};
    int target=1;
    
    printf("输入:");
    outPut(strs);
    printf("输入:");
    outPut(target);
    
    printf("排序:");
    sort(strs.begin(), strs.end());//排序
    outPut(strs);
    
    printf("输出:");
    outPut(solution.threeSumClosest(strs,target));
    return 0;
}












#include "../Output.h"
/*
合并两个有序数组
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

    初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
    你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
输出: [1,2,2,3,5,6]
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] < nums2[j]) {
                nums1[k] = nums2[j];
                --j;
            } else {
                nums1[k] = nums1[i];
                --i;
            }
            --k;
        }
        if (j >= 0) {
            while (k >= 0)
                nums1[k--] = nums2[j--];
        }
    }
};
int main() {
    problem(__FILE__,"合并两个有序数组\n"
            "给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。");
    Solution solution;
    vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums2={};
    int m=3;
    int n=3;
    outPut("nums1",nums1);
    outPut("nums2",nums2);
    outPut("m",m);
    outPut("n",n);
    solution.merge(nums1,m,nums2,n);
    outPut(1,nums1);
    return 0;
}
#include "../Output.h"
/*
两个排序数组的中位数
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
你可以假设 nums1 和 nums2 不同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

中位数是 2.0

示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5

 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double answer=0.0;
        vector<int> x(nums1.size()+nums2.size());
        int x_size= x.size();
        int nums1_size= nums1.size();
        int nums2_size= nums2.size();
        for (int i = 0; i < x_size; ++i) {
            if (i<nums1_size) {
                x[i]=nums1[i];
            } else {
                x[i]=nums2[i-nums1_size];
            }
        }
        for (int j = 0; j < x_size-1; ++j) {
            for (int i = j+1; i < x_size; ++i) {
                if(x[j]>x[i]){
                    int max=x[j];
                    x[j]=x[i];
                    x[i]=max;
                }
            }
        }
        if(x_size%2!=0)
            return x[x_size/2];
        else
            return ((double)(x[x_size/2-1]+x[x_size/2]))/2;
    }
};
int main() {
    printf("两个排序数组的中位数\n"
                   "给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。\n"
                   "请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。\n"
                   "你可以假设 nums1 和 nums2 不同时为空。");
    printf("\n\n");
    Solution solution;
    vector<int> nums1={1,2};
    vector<int> nums2={4,3};
    for (int i = 0; i < nums1.size(); ++i) {
        if(i==0)
            printf("nums=[");
        printf("%d",nums1[i]);
        if(i<nums1.size()-1)
            printf(",");
        if(i==nums1.size()-1)
            printf("]\n");
    }
    for (int i = 0; i < nums2.size(); ++i) {
        if(i==0)
            printf("nums=[");
        printf("%d",nums2[i]);
        if(i<nums2.size()-1)
            printf(",");
        if(i==nums2.size()-1)
            printf("]\n");
    }
    printf("中位数是:%f\n",solution.findMedianSortedArrays(nums1,nums2));
    
    return 0;
}

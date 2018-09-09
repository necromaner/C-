#include "../Output.h"
/*
盛最多水的容器
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。



示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49


 */
class Solution {
public:
    int maxArea1(vector<int>& height) {
        if (height.size() == 2)
            return min(height[0], height[1]);
        if(height.size() <2)
            return 0;
        int max=0;
        int height_size=height.size();
        for (int i = 0; i < height_size-1.; ++i) {
            for (int j = i+1; j < height_size; ++j) {
                int minInt=height[i]>height[j]?height[j]:height[i];
                int now=minInt*(j-i);
                if(max<now)
                    max=now;
            }
        }
        return max;
    }
    int maxArea(vector<int>& height) {
        int max=0;
        int height_size=height.size();
        int water = 0;
        int left = 0;
        int right = height.size()-1;
        while (left<right) {
            int now = min(height[left], height[right]) * (right - left);
            if (max < now)
                max = now;
            if(height[left]>height[right])
                right--;
            else
                left++;
        }
        return max;
    }
};
int main() {
    printf("T10.盛最多水的容器\n"
                   "给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。");
    printf("\n\n");
    Solution solution;
    vector<int> height={1,8,6,2,5,4,8,3,7};
    outPut(0,height);
    outPut(1,solution.maxArea(height));
    return 0;
}












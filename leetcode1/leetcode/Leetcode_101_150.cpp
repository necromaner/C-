#include "Leetcode.h"
//120. 三角形最小路径和
/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：
如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 */
//执行用时 :24 ms, 在所有 cpp 提交中击败了5.05% 的用户
//内存消耗 :33.2 MB, 在所有 cpp 提交中击败了5.13%的用户
int Solution::minimumTotal(vector<vector<int>> &triangle) {
    vector<vector<int>> xx=triangle;//最短路径三角形
    int aa;
    if (triangle.size() < 2) {
        return xx[0][0];
    }
    xx[1][1] = triangle[0][0] + triangle[1][1];
    for (int i = 1; i < triangle.size(); i++) {
        xx[i][0] = xx[i - 1][0] + triangle[i][0];
        xx[i][1] = xx[i - 1][0] + triangle[i][1];
        if (triangle.size() > 2)
            minimumTotal1(triangle,xx, aa, i, 1);
    }
    return *min_element(xx[xx.size()-1].begin(), xx[xx.size()-1].end());
}
void Solution::minimumTotal1(vector<vector<int>> triangle,vector<vector<int>> &xx, int &aa, int i, int j) {
    for (int k = 1; k < triangle[i].size() - 1; k++) {
        aa = xx[i - 1][k] + triangle[i][k];  //  前一个数
        if (aa <= xx[i][k]) {
            xx[i][k] = aa;
        }
        xx[i][k + 1] = xx[i - 1][k] + triangle[i][k + 1];//后一个数
    }
}




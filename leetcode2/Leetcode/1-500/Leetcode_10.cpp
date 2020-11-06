#include "../leetcode.h"
//463. 岛屿的周长
/*
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

示例 :
输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
输出: 16
解释: 它的周长是下面图片中的 16 个黄色的边：
 */
int Leetcode::islandPerimeter(vector<vector<int>>& grid) {//2020-10-30
////    执行用时：208 ms, 在所有 C++ 提交中击败了41.73% 的用户
////    内存消耗：94.2 MB, 在所有 C++ 提交中击败了9.41% 的用户
//    if (grid.empty() || grid[0].empty())
//        return 0;
//    int high = grid.size(), wight = grid[0].size(), sum = 0;
//    for (int i = 0; i < high; ++i) {
//        for (int j = 0; j < wight; ++j) {
//            if (grid[i][j]) {
//                int num = 4;
//                if (i != 0 && grid[i - 1][j])
//                    num--;
//                if (i != high - 1 && grid[i + 1][j])
//                    num--;
//                if (j != 0 && grid[i][j - 1])
//                    num--;
//                if (j != wight - 1 && grid[i][j + 1])
//                    num--;
//                sum += num;
//            }
//        }
//    }
//    return sum;

//    执行用时：204 ms, 在所有 C++ 提交中击败了45.15% 的用户
//    内存消耗：94 MB, 在所有 C++ 提交中击败了22.54% 的用户
    if (grid.empty() || grid[0].empty())
        return 0;
    int high = grid.size(), wight = grid[0].size(), sum = 0;
    for (int i = 0; i < high; ++i) {
        for (int j = 0; j < wight; ++j) {
            if (grid[i][j] % 10) {
                if (grid[i][j] == 1)
                    sum += 4;
                else if (grid[i][j] == 11)
                    sum += 2;
                if (i != high - 1)
                    grid[i + 1][j] += 10;
                if (j != wight - 1)
                    grid[i][j + 1] += 10;
            }
        }
    }
    return sum;
}
int islandPerimeter_1(vector<vector<int>>& grid) {//抄
//    执行用时：196 ms, 在所有 C++ 提交中击败了50.35% 的用户
//    内存消耗：94.2 MB, 在所有 C++ 提交中击败了8.84% 的用户
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                if (i == 0 || grid[i-1][j] == 0) ans++;
                if (j == 0 || grid[i][j-1] == 0) ans++;
            }
        }
    }
    return ans*2;
}
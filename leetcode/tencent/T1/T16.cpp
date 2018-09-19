#include "../Output.h"
/*
螺旋矩阵
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]

示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]


 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return vector<int>{};
        vector<int> answer;
        int x1 = 0, y1 = 0;
        int x2 = matrix.size() - 1;
        int y2 = matrix[0].size() - 1;
        int direction=0;
        while (x1 <= x2 && y1 <= y2)
        {
            switch(direction){
                case 0:
                    for (int y = y1; y <= y2; y++)//上
                        answer.push_back(matrix[x1][y]);
                    direction++;
                    x1++;
                    break;
                case 1:
                    for (int x = x1; x <= x2; x++)//右
                        answer.push_back(matrix[x][y2]);
                    direction++;
                    y2--;
                    break;
                case 2:
                    for (int y = y2; y >= y1; --y)//下
                        answer.push_back(matrix[x2][y]);
                    direction++;
                    x2--;
                    break;
                case 3:
                    for (int x = x2; x >= x1; x--)//左
                        answer.push_back(matrix[x][y1]);
                    direction=0;
                    y1++;
                    break;
            }
        }
        return answer;
    }
};
int main() {
    problem(__FILE__,"螺旋矩阵\n"
            "给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。");
    Solution solution;
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    outPut(0,matrix);
    
    outPut(1,solution.spiralOrder(matrix));
    return 0;
}
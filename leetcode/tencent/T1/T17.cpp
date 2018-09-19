#include "../Output.h"
/*
螺旋矩阵 II
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]


 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==1)
            return {{n}};
        else if(n==0)
            return {};
        vector<vector<int>> answer(n,vector<int>(n,0));
        int x1=0,x2=n-1;
        int y1=0,y2=n-1;
        int num=1;
        int direction=0;
        while(x1<=x2&&y1<=y2){
            switch(direction){
                case 0:
                    for (int i = y1; i <= y2; ++i) {
                        answer[x1][i]=num;
                        num++;
                    }
                    direction++;
                    x1++;
                    break;
                case 1:
                    for (int i = x1; i <= x2; ++i) {
                        answer[i][y2]=num;
                        num++;
                    }
                    direction++;
                    y2--;
                    break;
                case 2:
                    for (int i = y2; i >= y1; --i) {
                        answer[x2][i]=num;
                        num++;
                    }
                    direction++;
                    x2--;
                    break;
                case 3:
                    for (int i = x2; i >= x1; --i) {
                        answer[i][y1]=num;
                        num++;
                    }
                    direction=0;
                    y1++;
                    break;
            }
        }
        return answer;
    }
};
int main() {
    problem(__FILE__,"螺旋矩阵 II\n"
            "给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。");
    Solution solution;
    int n=6;
    outPut(0,n);
    
    outPut(1,solution.generateMatrix(n));
    return 0;
}
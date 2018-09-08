/*Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
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
    void minimumTotal1(vector<vector<int>> triangle,vector<vector<int>> &xx, int &aa, int i, int j) {
        for (int k = 1; k < triangle[i].size() - 1; k++) {
            aa = xx[i - 1][k] + triangle[i][k];  //  前一个数
            if (aa <= xx[i][k]) {
                xx[i][k] = aa;
            }
            xx[i][k + 1] = xx[i - 1][k] + triangle[i][k + 1];//后一个数
        }
    }
};
int main() {
    Solution solution;
    vector<vector<int>> S1 = {{2},{3,4},{6,5,7},{4,1,8,3}};//11
    /* 2
     * 3 4
     * 6 5 7
     * 4 1 8 3
     *  2
     *  5  6
     * 11 10 13
     * 15 11 18 16
     */
    vector<vector<int>> S2 = {{-1},{2,3},{1,-1,3}};//-1

    for (auto i:S1) {
        for (auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout<<"The minimum path sum from top to bottom is "<<solution.minimumTotal(S1);
    return 0;
}
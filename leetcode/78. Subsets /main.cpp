/* Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

 1,2,3

 1
 2
 3
 1 2
 1 3
 2 3
 1 2 3

 1,2,3,4

 1
 2
 3
 4
 1 2
 1 3
 1 4
 2 3
 2 4
 3 4
 1 2 3
 1 2 4
 1 3 4
 2 3 4
 1 2 3 4
*/

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {//nums.begin()+k
        vector<vector<int>> answer;
        vector<int> answer1;
        for (int k = 0; k <= nums.size(); k++) {            //控制输出个数
            subsets1(answer, answer1, nums, k, 0);
        }
        return answer;
    }

    void subsets1(vector<vector<int>> &answer, vector<int> &answer1, vector<int> &nums, int k, int st) {
        if (k == 0) {
            answer.push_back(answer1);
            return;
        }
        for (int i = st; i < nums.size(); i++) {
            answer1.push_back(nums[i]);
            subsets1(answer, answer1, nums, k - 1, i + 1);
            answer1.pop_back();//删除数组元素
        }

    }
};
int main() {
    Solution solution;
    vector<int> S = {1,2,3,4};
    for (auto i:solution.subsets(S)) {
        for (auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */


#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string answer1 = "";
        if (n == 0)
            return answer;
        dfs(answer, answer1, n, 0, 0);
        return answer;
    }

    void dfs(vector<string> &answer, string &answer1, int n, int digit, int leftparenthesis) {
        if (digit == n * 2) {
            answer.push_back(answer1);
            return;
        }
        if (leftparenthesis < n) {
            answer1.push_back('(');
            dfs(answer, answer1, n, digit + 1, leftparenthesis + 1);
            answer1.pop_back();
        }
        if (leftparenthesis * 2 > digit) {
            answer1.push_back(')');
            dfs(answer, answer1, n, digit + 1, leftparenthesis);
            answer1.pop_back();
        }
    }
};

int main() {
    int n = 0;
    cout << "Enter :";
    cin >> n;
    Solution solution;
    for (auto i:solution.generateParenthesis(n)) {
        cout << i << endl;
    }
    return 0;
}
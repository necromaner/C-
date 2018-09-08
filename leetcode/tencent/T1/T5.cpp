#include "../Output.h"
/*
最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"

示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

说明:

所有输入只包含小写字母 a-z 。

 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer;
        if (strs.size() == 0) return answer;
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[0][i] != strs[j][i])
                    return answer;
            }
            answer.push_back(strs[0][i]);
        }
        return answer;
    }
};
int main() {
    printf("T5.最长公共前缀\n"
                   "编写一个函数来查找字符串数组中的最长公共前缀。\n"
                   "如果不存在公共前缀，返回空字符串 \"\"。");
    printf("\n\n");
    Solution solution;
    vector<string> strs={"flower","flow","flight"};
    printf("输入:");
    outPut(strs);
    
    printf("输出：%s\n",solution.longestCommonPrefix(strs).c_str());
    return 0;
}
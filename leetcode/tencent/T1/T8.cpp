#include "../Output.h"
/*
有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
 */

class Solution {
public:
    bool isValid(string s) {
        return true;
    }
};


int main() {
    printf("T8.有效的括号\n"
                   "给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。\n");
    printf("\n\n");
    Solution solution;
    vector<int> strs={0,2,1,-3};
    int target=1;
    string s="{}";

    printf("输入:");
    outPut(s);
    printf("输入:");
    outPut(target);

    printf("排序:");
    sort(strs.begin(), strs.end());//排序
    outPut(strs);

    printf("输出:");
    outPut(solution.isValid(s));
    return 0;
}




#include<vector>
#include<string>
#include <iostream>
#include "T9.cpp"
using namespace std;
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
    
    }
};


int main() {
    Solution solution;
    vector<int> strs={0,2,1,-3};
    int target=1;
    string s="{}";
    
    printf("输入:");
    outPut_vector_int(strs);
    printf("输入:");
    outPut_int(target);
    
    printf("排序:");
    sort(strs.begin(), strs.end());//排序
    outPut_vector_int(strs);
    
    printf("输出:");
    outPut_bool(solution.isValid(s));
    return 0;
}




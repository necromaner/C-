#include "../Output.h"
/*
有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
 */
/*
c++栈的方法的基本用法：

    push(): 向栈内压入一个成员；
    pop(): 从栈顶弹出一个成员；
    empty(): 如果栈为空返回true，否则返回false；
    top(): 返回栈顶，但不删除成员；
    size(): 返回栈内元素的大小；
 */
/*
栈空则返回ture
 */
class Solution {
public:
    bool isValid(string s) {
    
        if(s.length()%2==1)
            return false;
        stack <int>stk;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                stk.push(s[i]);
            } else if((stk.size()>0&&stk.top()=='('&&s[i]==')')||(stk.size()>0&&stk.top()=='['&&s[i]==']')||(stk.size()>0&&stk.top()=='{'&&s[i]=='}')){
                stk.pop();
            } else
                return false;
        }
        return stk.empty();
    }
};


int main() {
    printf("T8.有效的括号\n"
                   "给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。\n");
    printf("\n\n");
    Solution solution;
    string s=")";

    printf("输入:");
    outPut(s);

    printf("输出:");
    outPut(solution.isValid(s));
    return 0;
}




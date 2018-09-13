#include "../Output.h"
/*
反转字符串
编写一个函数，其作用是将输入的字符串反转过来。

示例 1:

输入: "hello"
输出: "olleh"

示例 2:

输入: "A man, a plan, a canal: Panama"
输出: "amanaP :lanac a ,nalp a ,nam A"


 */
class Solution {
public:
    string reverseString(string s) {
        if(s.size()==0)
            return "";
        int ss=s.size();
        for (int i = 0; i < s.size()/2; ++i) {
            char x=s[i];
            s[i]=s[ss-1-i];
            s[ss-1-i]=x;
        }
        return s;
    }
    bool x= false;
};
int main() {
    problem(__FILE__,"反转字符串\n"
            "编写一个函数，其作用是将输入的字符串反转过来。");
    Solution solution;
    string s="amanaP :lanac a ,nalp a ,nam A";
    outPut(0,s);
    outPut(1,solution.reverseString(s));
    
    
    
//    string x=";";
//    int num=1;
//    bool yes=true;
////    testCase(,,num,yes);
//    if(yes)
//        printf("------通过------\n");
    return 0;
}












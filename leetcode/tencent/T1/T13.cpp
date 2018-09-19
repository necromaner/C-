#include "../Output.h"
/*
反转字符串中的单词 III
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc"

注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

 */
class Solution {
public:
    string reverseWords(string s) {
        int min=0;
        int ss=s.size();
        for (int i = 0; i < ss;) {
            if(s[i+1]==' '||i+1==ss){
                for (int j = 0; j < (i-min+1)/2; ++j) {
                    char x=s[min+j];
                    s[min+j]=s[i-j];
                    s[i-j]=x;
                }
                i+=2;
                min=i;
            } else
                i++;
        }
        return s;
    }
};
int main() {
    problem(__FILE__,"反转字符串中的单词 III\n"
            "给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。");
    Solution solution;
    string s="a b cd";
    outPut(0,s);
    
    outPut(1,solution.reverseWords(s));
    return 0;
}
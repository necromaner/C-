#include "../Output.h"
/*
最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。

示例 2：

输入: "cbbd"
输出: "bb"

ccdasacdccs
 
 cs
 cc-cc-dd-ac
 cc-cd
 cd
 cc-ca
 ca
 cs
 ca
 cd
 cc
 
 
 */



class Solution {
public:
    string longestPalindrome(string s) {
        string answer=s;
        int min=0;
        int max=0;
        int s_size=s.size();
        for (int i = 0; i < s_size; ++i) {
            for (int j = s_size-1; j >i ; --j) {
                if(s[i]==s[j]){
                    int k;
                    bool yes=1;
                    for (k = 1; k <= (j-i)/2; ++k) {
                        if(s[i+k]!=s[j-k]){
                            yes=0;
                            break;
                        }
                        
                    }
                    if(yes&&(j-i)>(max-min)){
                        min=i;
                        max=j;
                    }
                }
            }
        }
        return s.substr(min,max-min+1);
    }
};
int main() {
    printf("T3.最长回文子串\n"
                   "给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。");
    printf("\n\n");
    Solution solution;
    string s="cbbdbbbc";
    outPut(0,s);
    outPut(1,solution.longestPalindrome(s));
    return 0;
}
#include "../Output.h"
/*
字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"

说明：

    num1 和 num2 的长度小于110。
    num1 和 num2 只包含数字 0-9。
    num1 和 num2 均不以零开头，除非是数字 0 本身。
    不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。


 */
/*
1.实现乘法
2.去除前面'0'

*/
class Solution {
public:
    string multiply(string num1, string num2) 	{
        int m = num1.size(), n = num2.size();
        if(m == 0 || n == 0) return 0;
        string res(m + n, '0');
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for(int i = 0; i < m; ++i)
        {
            int r = 0;
            for(int j = 0; j < n; ++j)
            {
                int tmp = (res[i + j] - '0') + (num1[i] - '0') * (num2[j] - '0') + r;
                res[i + j] = tmp % 10 + '0';
                r = tmp / 10;
            }
            res[i + n] += r;
        }
        
        reverse(res.begin(), res.end());
        
        size_t pos = res.find_first_not_of("0");
        if(pos != string::npos)
        {
            return res.substr(pos);
        }
        
        return "0";
    }
};
int main() {
    problem(__FILE__,"字符串相乘\n"
            "给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。");
    Solution solution;
    string num1="123";
    string num2="1234";
    outPut(0,num1);
    outPut(0,num2);
    outPut(1,solution.multiply(num1,num2));
    
//    int num=1;
//    bool yes=true;
//    testCase(solution.multiply("1","12"),"12",num,yes);
//    testCase(solution.multiply("12","1"),"12",num,yes);
//    testCase(solution.multiply("10000","10000"),"100000000",num,yes);
//    testCase(solution.multiply("0",""),"0",num,yes);
//    testCase(solution.multiply("100000000","100000000"),"10000000000000000",num,yes);
//    testCase(solution.multiply("9999999999","9999999999"),"99999999980000000001",num,yes);
//    testCase(solution.multiply("1","1"),"1",num,yes);
//    if(yes)
//        printf("通过");
    return 0;
}












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
class Solution {
public:
    string multiply(string num1, string num2) {
        return "1";
    }
};
int main() {
    printf("T11.字符串相乘\n"
                   "给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。");
    printf("\n\n");
    Solution solution;
    string num1="1000";
    string num2="1000";
    outPut(0,num1);
    outPut(0,num2);
    
    outPut(1,solution.multiply(num1,num2));
    return 0;
}












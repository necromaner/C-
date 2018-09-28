#include "../Output.h"
/*
反转整数
给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:

输入: 123
输出: 321

 示例 2:

输入: -123
输出: -321

示例 3:

输入: 120
输出: 21

注意:

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。

 */
class Solution {
public:
    int reverse(int x) {
        int sum = 0;
        while (x != 0) {
            int num = sum * 10;
            if (num / 10 != sum) return 0;
            sum = num + x % 10;
            x /= 10;
        }
        return sum;
    }
    int reverse1(int x) {
        long long x1 = 0;
        while (x != 0) {
            int x2 = x % 10;
            x1 = x1 * 10 + x2;
            x /= 10;
        }
        if (x1 > INT_MAX||x1<INT_MIN)
            return 0;
        return x1;
    }
};
int main() {
    problem(__FILE__,"反转整数\n"
            "给定一个 32 位有符号整数，将整数中的数字进行反转。");
    Solution solution;
    int x=-1234599;
    outPut(0,x);
    
    outPut(1,solution.reverse(x));
    return 0;
}
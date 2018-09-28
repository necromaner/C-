#include "../Output.h"
/*
2的幂
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1

示例 2:

输入: 16
输出: true
解释: 24 = 16

示例 3:

输入: 218
输出: false


 */
class Solution {
public:
    /*
     *&按位与
     *&&且
     * 2的幂在2进制第一个为1，后面全为0，2的幂减1为相比2的幂，前面1变为0，后面0变为1
     * 16=10000 15=01111 16&15=10000&01111=00000=0
     * 15=01111 14=01110 15&14=01111&01110=01110=14
     *
     *
     */
    bool isPowerOfTwo(int n) {
        return n>0&&!(n & (n - 1));
    }
    /*
     * n每次除以2，每次没有余数且最后得1返回true，否则返回false
     */
    bool isPowerOfTwo1(int n) {
        while (n>0){
            if(n%2==0){
                n/=2;
            } else if(n==1){
                return true;
            } else
                return false;
        }
        return false;
    }
};
int main() {
    problem(__FILE__,"2的幂\n"
            "给定一个整数，编写一个函数来判断它是否是 2 的幂次方。");
    Solution solution;
    int n=15;
    outPut(0,n);
    
    outPut(1,solution.isPowerOfTwo(n));
    return 0;
}
/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.
Have you thought about this?

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Note:
        The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

Subscribe to see which companies asked this question.
*/

//翻译就是把一个数字反过来输出。


#include <iostream>
#include <cstdlib>          //abs( )求绝对值
using namespace std;


class Solution {
public:
    int reverse(int x) {
        int answer = 0;
        long long answerl = 0;
        if (x > 2147483647 || x < -2147483647) {            //判断输入是否超出int范围
            // if (abs(x)>2147483647){
            return 0;
        } else if (abs(x) >= 10) {                          //判断是否初始绝对值小于10
            for (int bb = abs(x); bb > 0; bb /= 10) {
                answerl = answerl * 10 + bb % 10;
            }
        } else {
            return x;
        }
        if (answerl > 2147483647 || answerl < -2147483647)  //判断输出是否超出int范围
            // if (abs(answerl)>2147483647){
            return 0;
        else if (x > 0)
            return answer = answerl;
        else
            return answer = -answerl;
    }
};

int main() {
    Solution solution;
    int aa;
    cout<<"Enter :";
    cin>>aa;
    cout<<"former    :"<<aa<<endl;
    cout<<"inversion :"<<solution.reverse(aa)<<endl;
    return 0;
}
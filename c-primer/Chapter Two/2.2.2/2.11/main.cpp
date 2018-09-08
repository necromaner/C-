/*2.11：指出下面的语句是声明还是定义：

(a)extern int ix =1024;

(b)int iy;

(c)extern int iz;
 */

#include <iostream>

int main() {
    //(a)
    extern int ix =1024;//定义
    //(b)
    int iy;//声明并定义
    //(c)
    extern int iz;//声明is，而非定义
    return 0;
}
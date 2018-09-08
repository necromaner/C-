/*4.38：说明下面这条表达式的含义。

    double slope = static_cast<double>(j/i); 
    */

#include <iostream>

int main() {
    int i,j;
    double slope = static_cast<double>(j/i);//先算j/i值，再转化为double类型
    return 0;
}
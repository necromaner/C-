/*2.15 下面的哪个定义是不合法的？为什么？

(a)int ival = 1.01;

(b)int &rvall = 1.01;

(c)int &rval2 = ival;

(d)int &rval3;
 */

#include <iostream>

int main() {
    //(a)
    int ival = 1.01;
    //(b)
    int &rvall = 1.01;//不合法,引用初始化必须是一个对象。
    //(c)
    int &rval2 = ival;
    //(d)
    int &rval3;//不合法,引用变量必须初始化。
    return 0;
}
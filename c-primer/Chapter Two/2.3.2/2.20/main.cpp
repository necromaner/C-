/*2.20 请叙述下面这段代码的作用。

int i =42;

int *pi = &i;

*pi=*pi* *pi;
 */

#include <iostream>

int main() {
    int i =42; //定义一个int类型，i初始值为42
    int *pi = &i;//pi指向i地址
    *pi=*pi* *pi;//i=i*i
    return 0;
}
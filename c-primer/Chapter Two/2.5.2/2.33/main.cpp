/*2.33 利用本节定义的变量，判断下列语句的运行结果
a=42;
b=42;
c=42;
d=42;
e=42;
g=42;
 */

#include <iostream>

int main() {
    int i=0,&r=i;
    auto a=r;//a是整数
    const int ci=i;&cr=ci;
    auto b=ci;//b是整数
    auto c=cr;//c是整数
    auto d=&i;//d是整形指针
    auto e=&ci;//e是指向整形常量的指针
    const auto f=ci;
    auto &g=ci;//
    a=42;
    b=42;
    c=42;
    d=42;//错误
    e=42;//错误
    g=42;//错误



    return 0;
}
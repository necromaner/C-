/*2.21 请解释下述定义。在这些定义中有非法的吗？如果有，为什么？

int i=0;

(a)double *dp =&i;

(b)int *ip = i;

(c)int*p =&i;
 */

#include <iostream>

int main() {
    int i=0;
    //(a)
    double *dp =&i;//非法，指针p类型与i类型不匹配
    //(b)
    int *ip = i;//的，没有指向地址
    //(c)
    int*p =&i;//dp指向i的地址
    return 0;
}
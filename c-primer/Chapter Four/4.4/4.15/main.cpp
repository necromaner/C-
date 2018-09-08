/*4.15：下面的赋值是非法的，为什么？应该如何修改？
double dval; int ival; int *pi;
dval = ival = pi = 0;
 */

//pi为指针
#include <iostream>

int main() {
    double dval; int ival; int *pi;
    dval = ival = 0;
    *pi=&ival;
    return 0;
}
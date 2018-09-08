/*4.32 解释下面这个循环的含义。
constexpr int size=5;
int ia[size]={1,2,3,4,5};
for(int *ptr=ia,ix=0;
ix!=size&&ptr!=ia+size;
++ix,++ptr) { /* ... / }
*/



#include <iostream>

int main() {
    constexpr int size=5;
    int ia[size]={1,2,3,4,5};
    for(int *ptr=ia,ix=0;ix!=size&&ptr!=ia+size;++ix,++ptr)
    { /* ... */ }
    return 0;
}
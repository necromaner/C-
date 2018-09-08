/*2.22：假设p是一个int型指针，请说明下述代码的含义。

if(p)//...

if(*p)//...
 */

#include <iostream>

int main() {
    int *p;
    if(p)//如果p是非空指针nullptr,为真
    if(*p)//如果指针p指向的内容是真
    return 0;
}
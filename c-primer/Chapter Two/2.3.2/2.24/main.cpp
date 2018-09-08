/*练习 2.24 在下面这段代码中为什么p合法而lp非法
int i=42;
 void *p=&i;
 long *p=&i;
 */

#include <iostream>

int main() {
    int i=42;
    void *p=&i; //void能指向任意指针，包括int
    long *p=&i; //long只能指向long
    return 0;
}
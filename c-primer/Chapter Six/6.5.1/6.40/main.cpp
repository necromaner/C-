/*.40：下面的哪个声明是错误的？为什么？

（a） int ff(int a, int b = 0, int c = 0);
（b） char *init(int ht = 24, int wd, char bckgrnd);
 */

#include <iostream>

int main() {
    int ff(int a, int b = 0, int c = 0);//正确

    char *init(int ht = 24, int wd, char bckgrnd);//错误，前面的有默认值，后面的必须也有。
    //一但某个行参被赋予了默认值，它后面的所有行参都必须有默认值。
    return 0;
}
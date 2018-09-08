/*6.41：下面的哪个调用是非法的？为什么？哪个调用虽然合法但显然与程序员的初衷不符？为什么？

    char *init(int ht, int wd = 80, char bckgrnd = ' ');
    init();
    init(24,10);
    init(14,'*');
 */

#include <iostream>

int main() {
    char *init(int ht, int wd = 80, char bckgrnd = ' ');

    init();//非法，ht没有默认值

    init(24,10);//init(24,10)==init(24,10,' ')

    init(14,'*');//init(14,'*')==init(14,'*',' ')  '*'转化为十进制数，调用虽然合法但显然与程序员的初衷不符

    return 0;
}
/*3.27：假设txt_size是一个无参数的函数，它的返回值是int。请回答下列哪个定义是非法的？为什么？

unsigned buf_size = 1024;

(a) int ia[buf_size];   (b) int ia[4 * 7 - 14];

(c) int ia[txt_size()];   (d) char st[11] = "fundamental";
*/

#include <iostream>

int main() {
    unsigned buf_size = 1024;

    int ia[buf_size];
    int ia2[4 * 7 - 14];
    int ia3[txt_size()];//当txt_size是constexpr时正确
    char st[11] = "fundamental";//fundamental有11个字符，但后面还有个空字符，初始值太多
    return 0;
}
// 1.7 编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息。

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    /*123/*123*/123*/
    // /*123/*123*/123*/
    return 0;
}
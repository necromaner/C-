//6.31:什么情况下返回的引用无效？什么情况下返回常量的引用无效?

//答：返回的引用无效:函数终止释放了的局部变量
//返回常量的引用无效:在函数内部对常量引用做类似赋值拷贝等动作

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
//7.18 封装是何含义？它有什么用处？

//定义在public说明符之后的成员在整个程序内可被访问，public成员定义类的接口
//定义在private说明符之后的成员可以被类的成员函数访问，但是不能被使用该类的代码访问，private部分封装（隐藏）类的实现细节。
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
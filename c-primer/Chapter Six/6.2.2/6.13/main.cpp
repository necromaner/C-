//6.13：假设类型T是某种类型的名字，说明以下两个函数声明的区别：一个是void f(T),另一个是void f(&T)

//void f(&T) 引用的形参绑定了实参，一旦引用的形参发生变化，实参也会跟着变化
//void f(T)，实参传过来，作用范围仅在函数内部，本身实参没有变化。
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
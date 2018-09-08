//7.16 在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在public说明符之后？什么样的成员应该定义在private说明符之后？

//没有限制
//作为接口的一部分，构造函数和部分成员函数在public说明符后，数据成员和作为实现部分的函数则跟在private说明符后
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
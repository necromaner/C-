//6.29：在范围for循环使用initalizer_list对象时，应该将循环控制变量声明成引用类型吗，为什么？


//答：应该将循环控制变量声明成引用类型，因为initalizer_list对象中的元素永远是常量值，无法改变
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
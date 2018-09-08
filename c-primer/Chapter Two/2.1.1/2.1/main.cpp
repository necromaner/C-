// 2.1 类型int、long、long long和short的区别是什么？无符号类型和带符号类型的区别是什么？float和double的区别是什么？

//类型int、long、long long和short尺寸大小不同，一个int至少和一个short一样大，一个long至少和一个int一样大，一个long long至少和一个long一样大。
//无符号类型和带符号类型的区别是带符号类型可以表达正数、负数或0，无符号类型则仅能表示大于等于0的值。
//float和double的区别是foloat以1个字（32比特）来表示，double以2个字（64比特）来表示。
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
//4.26 在本节关于测验成绩的例子中，如果使用unsigned int作为quiz1的类型会发生什么情况？

//测试成绩例子中，有27为学生，就至少要27位，unsigned long 有32位，unsigned int 不一定大于27位,会造成结果错误

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
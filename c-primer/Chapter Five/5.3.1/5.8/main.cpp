//5.8：什么是悬垂else?C++语言是如何处理else子句的？

//if里有多个else，哪个else对应哪个if，就是悬垂。选择最近的if

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
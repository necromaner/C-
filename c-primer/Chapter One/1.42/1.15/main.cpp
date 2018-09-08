//1.15  编写程序，包括第14页“再探编译”中讨论的常见错误。熟悉编译器生成的错误信息。

#include <iostream>

//错误：main的参数列表漏掉了
int main({
    //错误：endl后使用了冒号而非分号
    std::cout << "Read each file." << std::endl:
    // 错误：字符串字面常量的两侧漏掉了引号
    std::cout << Update master. << std::endl;
    // 错误： 漏掉了第二个输出运算符
    std::cout << "Write new master." std::endl;
    // 错误： return 语句漏掉了分号
    return 0
}
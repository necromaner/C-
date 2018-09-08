//6.37：为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型、最后一个使用decltype关键字。你觉得哪种形式最好，为什么?
//6.36：编写一个函数的声明，使其返回函数的引用并且该函数包含10个string对象。不要使用尾置返回类型、decltype或者类型别名。

#include <iostream>
#include<string>
using namespace std;
int main() {
    typedef string str1[10];
    str1 &func(string& s1);

    auto func(string& s2) ->string(&)[10];

    string str3[10];
    decltype(str3) &func(string& s3);
    return 0;
}
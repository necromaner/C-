//6.36：编写一个函数的声明，使其返回函数的引用并且该函数包含10个string对象。不要使用尾置返回类型、decltype或者类型别名。

#include <iostream>
#include<string>
using namespace std;
int main() {
    typedef string str[10];
    str &func(string s);
    return 0;
}
//7.17 使用class和struct时有区别吗？如果有，是什么？


//有区别，唯一区别是默认的访问权限
//struct定义在第一个访问说明符之前的成员是public,定义的类的所有成员是public
//class定义在第一个访问说明符之前的成员是private,定义的类的所有成员是private

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
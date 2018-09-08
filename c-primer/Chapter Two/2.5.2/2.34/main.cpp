//练习2.34 基于上一个练习中的变量和语句编写一段程序，输出赋值前后变量的内容，你刚才的推断正确吗、如果不对反复研读本节实例知道明白错在哪里。

#include <iostream>

int main()
{
    int i = 0, &r = i;
    auto a = r;

    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    const auto f = ci;
    auto &g = ci;

    a = 42;//a是整数
    b = 42;//b是整数
    c = 42;//c是整数
    *d = 42;//d是整形指针
    e = &c;//e是指向整形常量的指针

    std::cout<<"a = "<<a<<std::endl;
    std::cout<<"b = "<<b<<std::endl;
    std::cout<<"c = "<<c<<std::endl;
    std::cout<<"d = "<<d<<std::endl;
    std::cout<<"e = "<<e<<std::endl;
    std::cout<<"g = "<<g<<std::endl;

    return 0;
}

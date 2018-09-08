//2.18 编写代码分别更改指针的值以及指针所指对象的值。

#include <iostream>

int main() {
    std::cout<<"(1)"<<std::endl;//更改指针的值。
    int aa=10,bb=20;
    int *q=&aa;
    std::cout<<"*q = "<<*q<<std::endl;
    q=&bb;
    std::cout<<"*q = "<<*q<<std::endl;

    std::cout<<"(2)"<<std::endl;//更改指针所指对象的值。
    int ival=42;
    int *p=&ival;
    std::cout<<"*p = "<<*p<<std::endl;
    std::cout<<"ival = "<<ival<<std::endl;
    *p=1;
    std::cout<<"*p = "<<*p<<std::endl;
    std::cout<<"ival = "<<ival<<std::endl;
    return 0;
}
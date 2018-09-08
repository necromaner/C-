/*2.5：指出下述字面值的数据类型并说明每一组内几种字面值的区别：

(a)’a’,L’a’,”a”,L”a”

(b)10,10u,10L,10uL,012,0xC

(c)3.14,3.14f,3.14L

(d)10,10u,10.,10e-2
 */

#include <iostream>

int main() {
    std::cout<<"(a)"<<std::endl;
    std::cout<<'a'<<std::endl;//char类型
    std::cout<<L'a'<<std::endl;//wchar_t类型
    std::cout<<"a"<<std::endl;//char[]类型
    std::cout<<L"a"<<std::endl;//wchar_t[]类型
    std::cout<<"(b)"<<std::endl;
    std::cout<<10<<std::endl;//it类型
    std::cout<<10u<<std::endl;//unsigned int类型
    std::cout<<10uL<<std::endl;//unsigned long类型
    std::cout<<012<<std::endl;//8进制(octal)类型
    std::cout<<0xc<<std::endl;//16进制(hexadecimal)类型
    std::cout<<"(c)"<<std::endl;
    std::cout<<3.14<<std::endl;//double类型
    std::cout<<3.14f<<std::endl;//float类型
    std::cout<<3.14L<<std::endl;//long double类型
    std::cout<<"(d)"<<std::endl;
    std::cout<<10<<std::endl;//int类型
    std::cout<<10u<<std::endl;//unsigned int类型
    std::cout<<10.<<std::endl;//double类型
    std::cout<<10e-2<<std::endl;//double类型
    return 0;
}
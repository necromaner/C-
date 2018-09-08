/*2.13 下面程序中j的值是多少？

int i=42;
int main()
{
    int i=100;
    int j =i;
}


 */


#include <iostream>

int i=42;
int main()
{
    int i=100;
    int j =i;
    std::cout<<"j = "<<j<<std::endl;//j=100；局部对象与全局对象命名相同时会隐藏全局对象而采用局部对象。
}
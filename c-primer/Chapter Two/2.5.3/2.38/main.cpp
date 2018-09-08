//2.38 说明由decltype指定类型和由auto指定类型有何区别，请举出一个列子，decltype指定的类型与auto指定的类型一样，在举一个列子，decltype指定的类型与auto指定的类型不一样。

//decltype从表达式的类型得出类型，auto从变量的类型得出类型
#include <iostream>

int main()
{
    int i=0;
    auto a=i;
    decltype(i) b=i;
    return 0;
}
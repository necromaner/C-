/*练习2.35判断下列推断出的类型是什么，然后编写程序验证
    const int i = 42;
    auto j = i;const auto &k = i; auto *p = &i;
    const auto j2 = i, &k2 = i;
 */

#include <iostream>

int main()
{
    const int i = 42;
    auto j = i; //int j
    const auto &k = i; //const int &k
    auto *p = &i;//const int %p
    const auto j2 = i, &k2 = i;//int j2,const int &k2
    return 0;
}
//1.24   输入表示多个ISBN的多条销售记录来测试上一个程序，每个ISBN的记录应该聚在一起。

#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item1,item2;
    int i=1;
    std::cin>>item1;
    while (std::cin >> item2)
        if (item1.isbn()==item2.isbn())
        {
            ++i;
            item1=item2;
        }
        else
        {
            std::cout<<item1.isbn()<<" has sold note "<<i<<std::endl;
            i=1;
            item1=item2;
        }
    std::cout<<item1.isbn()<<"has sold note "<<i<<std::endl;
    return 0;
}
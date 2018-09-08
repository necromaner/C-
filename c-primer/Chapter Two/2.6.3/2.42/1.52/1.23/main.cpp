//1.23 编写程序，读取多条销售记录，并统计每个isbn有几条销售记录。

#include <iostream>
#include <string>
#include "Sales_data.h"
int main()
{
    Sales_data item1,item2;
    int i=1;
    std::cout<<"Enter the ISBN:";
    std::cin>>item1.bookNo;
    std::cout<<"Enter the ISBN:";
    while (std::cin >> item2.bookNo)
        if (item1.bookNo==item2.bookNo)
        {
            ++i;
            item1.bookNo=item2.bookNo;
        }
        else
        {
            std::cout<<item1.bookNo<<" has sold note "<<i<<std::endl;
            i=1;
            item1.bookNo=item2.bookNo;
        }
    std::cout<<item1.bookNo<<"has sold note "<<i<<std::endl;
    return 0;
}
//1.24   输入表示多个ISBN的多条销售记录来测试上一个程序，每个ISBN的记录应该聚在一起。

#include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNo;//编号
    std::string bookName;//书名
    unsigned units_sold = 0;//卖出册书 unsigned无符号
    unsigned inventory = 0;//库存
    double revenue = 0.0;//销售收入
    double price = 0;
};

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
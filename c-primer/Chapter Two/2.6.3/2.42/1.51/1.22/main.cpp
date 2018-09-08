//1.22 编写程序，读取具有多个相同isbn的销售记录，输出所有记录之和

#include <iostream>
#include <string>
#include "Sales_data.h"
int main()
{
    Sales_data Sum,item;
    int i=2;
    std::cout<<"Enter the 1 ISBN:";
    std::cin>>Sum.bookNo;
    std::cout<<"Enter the 1 units:";
    std::cin>>Sum.units_sold;
    std::cout<<"Enter the 1 price:";
    Sum.revenue=Sum.units_sold*Sum.price;
    std::cin>>Sum.price;

    std::cout<<"Enter the 2 ISBN:";
    while(std::cin>>item.bookNo){
        std::cout<<"Enter the "<<i<<" item units:";
        std::cin>>item.units_sold;
        std::cout<<"Enter the "<<i<<" item price:";
        std::cin>>item.price;
        item.revenue=item.units_sold*item.price;
        std::cout<<"Enter the "<<i+1<<" item ISBN:";
        Sum.units_sold+=item.units_sold;
        Sum.revenue+=item.revenue;
        Sum.price=(Sum.price+item.price)/2;
        ++i;
    }
    std::cout<<"ISBN:"<<Sum.bookNo<<std::endl;
    std::cout<<"sell books:"<<Sum.units_sold<<std::endl;
    std::cout<<"total price:"<<Sum.revenue<<std::endl;
    std::cout<<"average price:"<<Sum.price<<std::endl;
    return 0;
}
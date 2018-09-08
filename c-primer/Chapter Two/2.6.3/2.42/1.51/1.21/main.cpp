//2.21 编写程序，读取两个ISBN相同的Sales_item对象，输出它们的和。

#include <iostream>
#include <string>
#include "Sales_data.h"
int main() {
    Sales_data item1,item2,all;
    std::cout<<"Enter item1 ISBN:";
    std::cin>>item1.bookNo;
    std::cout<<"Enter item1 units:";
    std::cin>>item1.units_sold;
    std::cout<<"Enter item1 price:";
    std::cin>>item1.price;
    item1.revenue=item1.units_sold*item1.price;

    std::cout<<"Enter item2 ISBN:";
    std::cin>>item2.bookNo;
    std::cout<<"Enter item2 units:";
    std::cin>>item2.units_sold;
    std::cout<<"Enter item2 price:";
    std::cin>>item2.price;
    item2.revenue=item2.units_sold*item2.price;

    if(item1.bookNo==item2.bookNo){
        all.bookNo=item1.bookNo;//编号
        all.units_sold=item1.units_sold+item2.units_sold;//总数量
        all.revenue=item1.revenue+item2.revenue;//总销售价格
        all.price=(item1.price+item2.price)/2;
        std::cout<<"ISBN:"<<all.bookNo<<std::endl;
        std::cout<<"sell books:"<<all.units_sold<<std::endl;
        std::cout<<"total price:"<<all.revenue<<std::endl;
        std::cout<<"average price:"<<all.price<<std::endl;
    }
    else{
        std::cout<<"ISBN is unlike";
    }
    return 0;
}

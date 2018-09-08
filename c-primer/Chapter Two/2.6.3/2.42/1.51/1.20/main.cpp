//1/20 在网站http://www.informit.com/title/0321714113上,第1章的代码目录中包含了头文件Sales_item.h。将它拷贝到你自己的工作目录中，用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。

#include <iostream>
#include <string>
#include "Sales_data.h"
int main() {
    Sales_data book;
    std::cout<<"Enter ISBN:";
    std::cin>>book.bookNo;
    std::cout<<"Enter units:";
    std::cin>>book.units_sold;
    std::cout<<"Enter price:";
    std::cin>>book.price;
    std::cout<<"bookNo:"<<book.bookNo<<std::endl;
    std::cout<<"units:"<<book.units_sold<<std::endl;
    std::cout<<"price:"<<book.price<<std::endl;
    book.revenue=book.units_sold*book.price;
    std::cout<<"revenue:"<<book.revenue<<std::endl;
    return 0;
}
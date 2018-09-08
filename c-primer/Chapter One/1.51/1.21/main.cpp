//2.21 编写程序，读取两个ISBN相同的Sales_item对象，输出它们的和。

#include <iostream>
#include <Sales_item.h>

int main() {
    Sales_item item1,item2;
    std::cout<<"Enter a book ISBN,sell books,price:";
    std::cin>>item1;
    std::cout<<"Enter another book ISBN,sell books,price:";
    std::cin>>item2;
    std::cout<<"|ISBN|sell books|average price|price|";
    std::cout<<item1+item2<<std::endl;
    return 0;
}
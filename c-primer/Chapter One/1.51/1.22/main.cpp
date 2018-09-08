//1.22 编写程序，读取具有多个相同isbn的销售记录，输出所有记录之和

#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item Sum,item;
    int i=3;
    std::cout<<"Enter the 1 :";
    std::cin>>Sum;
    std::cout<<"Enter the 2 :";
    while(std::cin>>item){
        std::cout<<"Enter the "<<i<<" :";
        Sum+=item;
        ++i;
    }
    std::cout<<Sum<<std::endl;
    return 0;
}
// 1.25  借助网站上的Sales_item.h头文件，编译并运行本节给出的书店程序。

#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item total;
    if(std::cin>>total){
        Sales_item trans;
        while(std::cin>>trans){
            if(total.isbn()==trans.isbn())
                total+=trans;
            else{
                std::cout<<total<<std::endl;
                total=trans;
            }
        }
        std::cout<<total<<std::endl;
    }else{
        std::cerr<<"No data?!"<<std::endl;
        return -1;
    }
    return 0;
}
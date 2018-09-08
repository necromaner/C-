// 1.25  借助网站上的Sales_item.h头文件，编译并运行本节给出的书店程序。

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

int main() {
    Sales_data total;
    std::cout<<"Enter ISBN:";
    if(std::cin>>total.bookNo){
        std::cout<<"Enter units:";
        std::cin>>total.units_sold;
        std::cout<<"Enter price:";
        std::cin>>total.price;
        total.revenue=total.units_sold*total.price;
        Sales_data trans;
        std::cout<<"Enter ISBN:";
        while(std::cin>>trans.bookNo){
            std::cout<<"Enter units:";
            std::cin>>trans.units_sold;
            std::cout<<"Enter price:";
            std::cin>>trans.price;
            trans.revenue=trans.units_sold*trans.price;
            if(total.bookNo==trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
                total.price = (trans.price + total.price) / 2;
            }
            else{
                std::cout<<"ISBN:"<<total.bookNo<<std::endl;
                std::cout<<"sell books:"<<total.units_sold<<std::endl;
                std::cout<<"total price:"<<total.revenue<<std::endl;
                std::cout<<"average price:"<<total.price<<std::endl;
                total.bookNo=trans.bookNo;
                total.units_sold=trans.units_sold;
                total.revenue=trans.revenue;
                total.price=trans.price;
            }
        }
        std::cout<<"ISBN:"<<total.bookNo<<std::endl;
        std::cout<<"sell books:"<<total.units_sold<<std::endl;
        std::cout<<"total price:"<<total.revenue<<std::endl;
        std::cout<<"average price:"<<total.price<<std::endl;
    }else{
        std::cerr<<"No data?!"<<std::endl;
        return -1;
    }
    return 0;
}
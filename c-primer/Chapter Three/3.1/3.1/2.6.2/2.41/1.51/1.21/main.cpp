//2.21 编写程序，读取两个ISBN相同的Sales_item对象，输出它们的和。

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
struct Sales_data
{
    string bookNo;//编号
    string bookName;//书名
    unsigned units_sold = 0;//卖出册书 unsigned无符号
    unsigned inventory = 0;//库存
    double revenue = 0.0;//销售收入
    double price = 0;
};

int main() {
    Sales_data item1,item2,all;
    cout<<"Enter item1 ISBN:";
    cin>>item1.bookNo;
    cout<<"Enter item1 units:";
    cin>>item1.units_sold;
    cout<<"Enter item1 price:";
    cin>>item1.price;
    item1.revenue=item1.units_sold*item1.price;

    cout<<"Enter item2 ISBN:";
    cin>>item2.bookNo;
    cout<<"Enter item2 units:";
    cin>>item2.units_sold;
    cout<<"Enter item2 price:";
    cin>>item2.price;
    item2.revenue=item2.units_sold*item2.price;

    if(item1.bookNo==item2.bookNo){
        all.bookNo=item1.bookNo;//编号
        all.units_sold=item1.units_sold+item2.units_sold;//总数量
        all.revenue=item1.revenue+item2.revenue;//总销售价格
        all.price=(item1.price+item2.price)/2;
        cout<<"ISBN:"<<all.bookNo<<endl;
        cout<<"sell books:"<<all.units_sold<<endl;
        cout<<"total price:"<<all.revenue<<endl;
        cout<<"average price:"<<all.price<<endl;
    }
    else{
        cout<<"ISBN is unlike";
    }
    return 0;
}
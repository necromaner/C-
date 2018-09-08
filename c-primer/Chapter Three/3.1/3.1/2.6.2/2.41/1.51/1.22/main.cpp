//1.22 编写程序，读取具有多个相同isbn的销售记录，输出所有记录之和

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
int main()
{
    Sales_data Sum,item;
    int i=2;
    cout<<"Enter the 1 ISBN:";
    cin>>Sum.bookNo;
    cout<<"Enter the 1 units:";
    cin>>Sum.units_sold;
    cout<<"Enter the 1 price:";
    Sum.revenue=Sum.units_sold*Sum.price;
    cin>>Sum.price;

    cout<<"Enter the 2 ISBN:";
    while(cin>>item.bookNo){
        cout<<"Enter the "<<i<<" item units:";
        cin>>item.units_sold;
        cout<<"Enter the "<<i<<" item price:";
        cin>>item.price;
        item.revenue=item.units_sold*item.price;
        cout<<"Enter the "<<i+1<<" item ISBN:";
        Sum.units_sold+=item.units_sold;
        Sum.revenue+=item.revenue;
        Sum.price=(Sum.price+item.price)/2;
        ++i;
    }
    cout<<"ISBN:"<<Sum.bookNo<<endl;
    cout<<"sell books:"<<Sum.units_sold<<endl;
    cout<<"total price:"<<Sum.revenue<<endl;
    cout<<"average price:"<<Sum.price<<endl;
    return 0;
}
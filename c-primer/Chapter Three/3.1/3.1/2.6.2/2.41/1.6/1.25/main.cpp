// 1.25  借助网站上的Sales_item.h头文件，编译并运行本节给出的书店程序。

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
    Sales_data total;
    cout<<"Enter ISBN:";
    if(cin>>total.bookNo){
        cout<<"Enter units:";
        cin>>total.units_sold;
        cout<<"Enter price:";
        cin>>total.price;
        total.revenue=total.units_sold*total.price;
        Sales_data trans;
        cout<<"Enter ISBN:";
        while(cin>>trans.bookNo){
            cout<<"Enter units:";
            cin>>trans.units_sold;
            cout<<"Enter price:";
            cin>>trans.price;
            trans.revenue=trans.units_sold*trans.price;
            if(total.bookNo==trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
                total.price = (trans.price + total.price) / 2;
            }
            else{
                cout<<"ISBN:"<<total.bookNo<<endl;
                cout<<"sell books:"<<total.units_sold<<endl;
                cout<<"total price:"<<total.revenue<<endl;
                cout<<"average price:"<<total.price<<endl;
                total.bookNo=trans.bookNo;
                total.units_sold=trans.units_sold;
                total.revenue=trans.revenue;
                total.price=trans.price;
            }
        }
        cout<<"ISBN:"<<total.bookNo<<endl;
        cout<<"sell books:"<<total.units_sold<<endl;
        cout<<"total price:"<<total.revenue<<endl;
        cout<<"average price:"<<total.price<<endl;
    }else{
        cerr<<"No data?!"<<endl;
        return -1;
    }
    return 0;
}
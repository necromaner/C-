//7.8：为什么read函数将其Sales_data参数定义为普通的引用，而print将其参数定义成常量引用？

//答：read要进行赋值，而print只打印不改变值。


#include <iostream>
#include <string>

using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

};

double Sales_data::avg_price() const//平均价格
{
    if(units_sold)
        return revenue/units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read(istream &is,Sales_data &item){
    double price=0;
    cout<<"bookNo ：";
    is>>item.bookNo;
    cout<<"units_sold ：";
    is>>item.units_sold;
    cout<<"price ：";
    is>>price;
    item.revenue=price*item.units_sold;
    return is;
}
ostream &print(ostream &os,const Sales_data &item){
    os<<"bookNo : "<<item.isbn()<<endl;
    os<<"units_sold : "<<item.units_sold<<endl;
    os<<"revenue : "<<item.revenue<<endl;
    os<<"avg_price : "<<item.avg_price();
    return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum=lhs;
    sum.combine(rhs);
    return sum;
}

using namespace std;

int main()
{
    Sales_data total;
    if(read(cin,total))
    {
        Sales_data trans;
        while(read(cin, trans)){
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else{
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }else{
        cerr << "No data?!" << endl;
    }
    return 0;
}

//7.11：在你的Sales_data类中添加构造函数，然后编写一段程序令其用到每个构造函数。

#include <iostream>
#include <string>

using namespace std;

struct Sales_data
{
    Sales_data()= default;
    Sales_data(const string &s):bookNo(s){}//第一种
    Sales_data(const string &s, unsigned n, double p):bookNo(s),units_sold(n),revenue(p*n){}//第二种
    Sales_data(istream &);//第三种

    string isbn() const{ return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
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
Sales_data::Sales_data(std::istream &is)
{
    read(is,*this);
}
int main()
{
    cout<<"1."<<endl;
    Sales_data s1("book");//调用第一种构造函数
    print(cout, s1);
    cout << endl;

    cout<<"2."<<endl;
    Sales_data s2("book",10,20);//调用第二种构造函数
    print(cout,s2);
    cout << endl;

    cout<<"3."<<endl;
    Sales_data s3(cin);//调用第三种构造函数
    print(cout,s3);
    cout << endl;
    return 0;
}
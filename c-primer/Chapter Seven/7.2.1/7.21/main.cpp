//7.21：修改你的Sales_data类使其隐藏实现的细节。你之前编写的关于Sales_data操作的程序应该继续使用，借助类的新定义重新编译该程序，确保其工作正常。


#include <iostream>
#include <string>

using namespace std;

struct Sales_data
{
public:
    friend istream &read(istream &is,Sales_data &item);
    friend ostream &print(ostream &os,const Sales_data &item);
    Sales_data()= default;
    Sales_data(const string &s):bookNo(s){}//第一种
    Sales_data(const string &s, unsigned n, double p):bookNo(s),units_sold(n),revenue(p*n){}//第二种
    Sales_data(istream &is)
    {
        double price = 0;
        cout<<"bookNo ：";
        is>>bookNo;
        cout<<"units_sold ：";
        is>>units_sold;
        cout<<"price ：";
        is>>price;
        revenue=price*units_sold;
    }

    string isbn() const{ return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

private:
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

int main()
{
    Sales_data total;
    if (read(cin,total))
    {
        Sales_data trans;
        while(read(cin,trans))
        {
            if(total.isbn()==trans.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
                total =  trans;
            }
        }
        print(cout, total) << endl;
    }else{
        cerr << "No data？!" << endl;
    }
    return 0;
}

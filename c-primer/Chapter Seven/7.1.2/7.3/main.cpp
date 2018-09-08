//7.3：修改7.1.1节（第229页）的交易处理程序，令其使用这些成员。

#include <iostream>
#include <string>

using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sole = 0;
    double revenue = 0.0;

    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
};

double Sales_data::avg_price() const
{
    if(units_sole)
        return revenue/units_sole;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sole += rhs.units_sole;
    revenue += rhs.revenue;
    return *this;
}

int main() {
    Sales_data total;
    cout << "bookNo:";
    cin >> total.bookNo;
    cout << "units_sole:";
    cin >> total.units_sole;
    cout << "revenue:";
    cin >> total.revenue;
    if (total.bookNo != "end") {
        Sales_data trans;
        cout << "bookNo:";
        while (cin >> trans.bookNo && trans.bookNo != "end") {
            cout << "units_sole:";
            cin >> trans.units_sole;
            cout << "revenue:";
            cin >> trans.revenue;
            if (total.bookNo == trans.bookNo) {
                total.combine(trans);
                cout << "bookNo:";
            } else {
                cout << total.bookNo << " sale ：" << total.revenue << endl;
                total.bookNo = trans.bookNo;
                total.units_sole = trans.units_sole;
                total.revenue = trans.revenue;
                cout << "bookNo:";
            }

        }
        cout << total.bookNo << " sale ：" << total.revenue << endl;
    } else {
        cerr << "no data?!" << endl;
    }
    return 0;
}
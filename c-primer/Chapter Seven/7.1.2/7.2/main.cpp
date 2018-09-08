// 7.2：曾在2.6.2节练习（第67页）中编写了一个Sales_data类，请向这个类添加combine和isbn成员。

#include <iostream>
#include <string>
using namespace std;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    string isbn() const {
        return bookNo;
    }

    Sales_data &combine(const Sales_data &);

    double avg_price() const;
};
double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}
Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    return *this;
}

int main() {
    return 0;
}
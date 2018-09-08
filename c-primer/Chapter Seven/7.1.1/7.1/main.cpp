//7.1：使用2.6.1节练习定义的Sales_data类为1.6节（第21页）的交易处理程序编写一个新版本。


#include <iostream>
using namespace std;

struct Sales_data {
    string bookNo;//ISBN
    unsigned units_sole = 0;//销量
    double revenue = 0.0;//总销售收入
};
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
                total.units_sole += trans.units_sole;
                total.revenue += trans.revenue;
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
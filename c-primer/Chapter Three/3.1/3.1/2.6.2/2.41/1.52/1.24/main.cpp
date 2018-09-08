//1.24   输入表示多个ISBN的多条销售记录来测试上一个程序，每个ISBN的记录应该聚在一起。

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
    Sales_data item1,item2;
    int i=1;
    cout<<"Enter the ISBN:";
    cin>>item1.bookNo;
    cout<<"Enter the ISBN:";
    while (cin >> item2.bookNo)
        if (item1.bookNo==item2.bookNo)
        {
            ++i;
            item1.bookNo=item2.bookNo;
        }
        else
        {
            cout<<item1.bookNo<<" has sold note "<<i<<endl;
            i=1;
            item1.bookNo=item2.bookNo;
        }
    cout<<item1.bookNo<<"has sold note "<<i<<endl;
    return 0;
}
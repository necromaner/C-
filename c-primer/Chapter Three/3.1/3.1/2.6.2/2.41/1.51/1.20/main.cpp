//1/20 在网站http://www.informit.com/title/0321714113上,第1章的代码目录中包含了头文件Sales_item.h。将它拷贝到你自己的工作目录中，用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。
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
    unsigned units_sold=0;//卖出册书 unsigned无符号
    unsigned inventory=0;//库存
    double price=0;//售卖价格
    double revenue=0.0;//销售收入
};


int main() {
    Sales_data book;
    cout<<"Enter ISBN:";
    cin>>book.bookNo;
    cout<<"Enter units:";
    cin>>book.units_sold;
    cout<<"Enter price:";
   cin>>book.price;
    cout<<"bookNo:"<<book.bookNo<<endl;
    cout<<"units:"<<book.units_sold<<endl;
    cout<<"price:"<<book.price<<endl;
    book.revenue=book.units_sold*book.price;
    cout<<"revenue:"<<book.revenue<<endl;
    return 0;
}
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data
{
    std::string bookNo;//编号
    std::string bookName;//书名
    unsigned units_sold=0;//卖出册书 unsigned无符号
    unsigned inventory=0;//库存
    double price=0;//售卖价格
    double revenue=0.0;//销售收入
};
#endif

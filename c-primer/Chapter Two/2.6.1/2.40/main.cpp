//2.40 根据自己的理解写出Sales_data类 最好与书中的例子有所区别.

struct Sales_data
{
    std::string bookNo;//编号
    std::string bookName;//书名
    unsigned units_sold=0;//卖出册书 unsigned无符号
    unsigned inventory=0;//库存
    double Price=0;//售卖价格
    double revenue=0.0;//销售收入
};
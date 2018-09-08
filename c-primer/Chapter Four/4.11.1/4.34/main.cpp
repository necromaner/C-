 /*根据本节给出的变量定义，说明在下面的表达式中将发生什么样的类型转换：

(a) if (fval)
(b) dval = fval + ival;
(c) dval + ival * cval;
  */

#include <iostream>
using std::cout;
using std::endl;
int main() {
    int ival;//整型
    cout<<"ival = "<<ival<<endl;
    float fval;//单精度浮点
    cout<<"fval = "<<fval<<endl;
    double dval;//双精度浮点
    cout<<"dval = "<<dval<<endl;
    if (fval){}//转化为布尔类型，看是否为0
    dval = fval + ival;//ival转化为float，其他不变
    // dval + ival * cval;//cval转化为int



    return 0;
}
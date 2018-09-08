/*
练习4.35：假设有如下的定义，

char cval;      int ival;       unsigned int ui;
float fval;    double dval;

请回答在下面的表达式中发生了隐式类型转换吗？如果有，指出来。

(a) cval = 'a' + 3;   (b) fval = ui - ival * 1.0;

(c) dval = ui * fval;  (d) cval = ival + fval + dval;
*/
#include <iostream>
using std::cout;
using std::endl;

int main(){
        char cval;//字符
        int ival;//整型
        unsigned int ui;//无符号整型
        float fval;//单精度浮点
        double dval;//双精度浮点

        cval = 'a' + 3;//无变化
        cout<<"cval = "<<cval<<endl;
        fval = ui - ival * 1.0;//无变化
        cout<<"fval = "<<fval<<endl;
        dval = ui * fval;//无变化
        cout<<"dval = "<<dval<<endl;
        cval = ival + fval + dval;//无变化
        cout<<"cval = "<<cval<<endl;
}
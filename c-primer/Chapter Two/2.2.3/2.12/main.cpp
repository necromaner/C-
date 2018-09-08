/*2.12 请指出下面的名字中哪些是非法的？

(a)int double =3.14;

(b)int _;

(c)int catch-22;

(d)int 1_or_2 =1;

(e)double Double =3.14;
 */
/*
 * 1 标识符要能体现实际含义
 * 2 变量名一般用小写字母，如index，不能使用Index或INDEX
 * 3 用户自定义的类名一般以大写字母开头，如 Sales_item
 * 4 如果标识符由多个单词组词，则单词间应有明显区分，如student_loan或studentLoan,不要使用studentloan
 */
#include <iostream>

int main() {
    //(a)
    int double =3.14;//错误，使用了关键词double
    //(b)
    int _;
    //(c)
    int catch-22;//错误，不能使用-
    //(d)
    int 1_or_2 =1;//错误，使用了关键词or
    //(e)
    double Double =3.14;
    return 0;
}
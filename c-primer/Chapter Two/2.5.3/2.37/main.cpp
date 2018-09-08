/*2.37 赋值是会产生引用的一类型表达式，引用的类型就是左值的类型，也就是说，如果i是int，则表达式i=x的类型是int&。根据这一特点，请指出下面的代码每一个变量的类型和值
int a =3,b=4;
decltype(a) c =a; //int c c= 3;
decltype(a=b) d=a; // int &d d=3;
 */

#include <iostream>

int main() {
    int a =3,b=4;
    decltype(a) c =a; //int c;c=a=3;
    decltype(a=b) d=a; //int d;d=a=3;
    std::cout<<"a = "<<a<<std::endl;
    std::cout<<"d = "<<d<<std::endl;//d=3
    return 0;
}
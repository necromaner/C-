/*2.9：解释下列定义的含义。对于非法的定义，请说明错在何处并将其改正。

(a)std::cin>>int input_value; (b)int i ={3.14};

(c)double salary =wage =9999.99; (d)int i =3.14;
 */

#include <iostream>

int main() {
    //a
    int input_value;
    std::cin>>input_value;
    //b
    int i={3.14};
    std::cout<<"i= "<<i<<std::endl;
    //c
    double wage=9999.99;
    //double salary=wage=9999.99;//错误
    double salary=wage;
    int i2 =3.14; //丢失数据
    std::cout<<"i2= "<<i2<<std::endl;
    return 0;
}
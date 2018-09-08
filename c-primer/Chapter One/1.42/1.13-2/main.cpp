//1.13 使用for循环重做1.4.1节中的所有练习（第11页）。
//1.10 除了++运算符将运算对象的值增加1之外，还有一个递减运算符（-）实现将值减少1.编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数。

#include <iostream>

int main() {
    for(int val=10;val>=0;--val){
        std::cout<<val<<std::endl;
    }
    return 0;
}
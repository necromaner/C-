//6.6：说明形参,局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。

/*
从本质上说，三者均属于局部作用域中的变量，其中局部变量又可以分为普通（非静态）局部变量和静态局部变量。它们的差别：
作用域：  形参的作用域为整个函数体；而普通（非静态）局部变量和静态局部变量的作用域为：从定义处到包含该变量定义的块的结束处。
初始化：  形参由调用函数时所传递的实参初始化；而普通（非静态）局部变量和静态局部变量通常用初始化式进行初始化，且均在程序执行流程第一次经过该对象的定义语句时惊醒初始化。静态局部变量的初始化在整个程序执行过程中只进行一次。
生命周期：形参和普通（非静态）局部变量均属于自动变量，在每次调用函数时创建，并在函数结束时撤销；静态局部变量的生命期跨越了函数的多次调用，它在创建后直到程序结束时才撤销。
    */


#include <iostream>
using namespace std;

int fact(int bb) {                  //bb为形参
    end:
    static size_t cc = bb;                 //cc为静态局部变量
    if (bb > 0) {
        for (int i = bb; i > 1; --i) {
            cc *= i - 1;
        }
    } else if (bb == 0) {
        cc = 1;
    } else {
        cout << "Not less than zero" << endl;
        cout << "again?(Y or N):";
        char dd;
        cin >> dd;
        if (!cin || dd == 'Y' || dd == 'y') {
            cout << "Enter:";
            cin >> bb;
            goto end;
        } else
            return -1;
    }
    cout << bb << "! = " << cc;
}
int main() {
    int aa;                     //aa为普通局部变量
    cout << "Enter:";
    cin >> aa;
    fact(aa);
    return 0;
}
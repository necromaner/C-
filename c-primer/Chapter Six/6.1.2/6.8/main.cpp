//6.8：编写一个名为Chapter6.h的头文件，令其包含6.1节练习（第184页）中的函数声明。

#include "Chapter6.h"

int main() {
    begin:
    cout << "absolute_value(a) or factorial(f):";
    char xx;
    cin >> xx;
    switch (xx) {
        case 'a':
        case 'A':
            absolute_value();
            break;
        case 'f':
        case 'F':
            fact();
            break;
        default:
            cout << "error!!!" << endl;
            goto begin;
    }
    cout << "again?(Y or N):";
    char dd;
    cin >> dd;
    if (!cin || dd == 'Y' || dd == 'y') {
        goto begin;
    } else
        return 0;
}

int absolute_value() {  //求绝对值

    int bb;
    cout << "Enter:";
    cin >> bb;
    absolute_value:
    if (bb >= 0) {
        cout << bb << " absolute value is " << bb<<endl;
    } else
        cout << bb << " absolute value is " << -bb<<endl;
    cout << "again absolute_value?(Y or N):";
    char dd;
    cin >> dd;
    if (!cin || dd == 'Y' || dd == 'y') {
        cout << "Enter:";
        cin >> bb;
        goto absolute_value;
    } else
        return 0;
}

int fact() {            //求阶乘
    int aa;
    cout<<"Enter:";
    cin>>aa;
    end:
    int cc = aa;
    if (aa > 0) {
        for (int i = aa; i > 1; --i) {
            cc *= i - 1;
        }
    } else if (aa == 0) {
        cc = 1;
    } else {
        cout << "Not less than zero" << endl;
        cout << "again?(Y or N):";
        char dd;
        cin >> dd;
        if (!cin || dd == 'Y'|| dd == 'y') {
            cout << "Enter:";
            cin >> aa;
            goto end;
        } else
            return 0;
    }
    cout<<aa<<"! = "<<cc<<endl;
}
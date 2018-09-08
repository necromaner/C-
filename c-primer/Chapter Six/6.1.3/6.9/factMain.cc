//6.9：编写你自己的fact.cc和factMain.cc,这两个文件都应该包含上一小节的练习中编写的chapter6.h的头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。
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
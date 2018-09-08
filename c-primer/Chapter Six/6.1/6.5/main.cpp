//6.5：编写一个函数输出实参的绝对值。

#include <iostream>
using namespace std;

int absolute_value() {  //求绝对值

    int bb;
    cout << "Enter:";
    cin >> bb;
    absolute_value:
    if (bb >= 0) {
        cout << bb << " absolute value is " << bb<<endl;
    } else
        cout << bb << " absolute value is " << -bb<<endl;
    cout << "again?(Y or N):";
    char dd;
    cin >> dd;
    if (!cin || dd == 'Y' || dd == 'y') {
        cout << "Enter:";
        cin >> bb;
        goto absolute_value;
    } else
        return 0;
}

int main() {
    absolute_value();
    return 0;
}
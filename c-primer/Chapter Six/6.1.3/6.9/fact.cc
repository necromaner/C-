#include "Chapter6.h"
#include <iostream>

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
    factorial:
    int cc = aa;
    if (aa > 0) {
        for (int i = aa; i > 1; --i) {
            cc *= i - 1;
        }

        cout<<aa<<"! = "<<cc<<endl;
    } else if (aa == 0) {
        cc = 1;

        cout<<aa<<"! = "<<cc<<endl;
    } else {
        cout << "Not less than zero" << endl;
        cout << "again factorial?(Y or N):";
        char dd;
        cin >> dd;
        if (!cin || dd == 'Y'|| dd == 'y') {
            cout << "Enter:";
            cin >> aa;
            goto factorial;
        } else
            return 0;
    }
}

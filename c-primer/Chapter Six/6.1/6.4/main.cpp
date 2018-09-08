//6.4：编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。

#include <iostream>
using namespace std;

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
            return -1;
    }
    cout<<aa<<"! = "<<cc<<endl;
}
int main() {
    fact();
    return 0;
}
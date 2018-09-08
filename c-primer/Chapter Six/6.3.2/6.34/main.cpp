//6.34：如果factorial函数的停止条件如下所示，将发生什么情况？
//if(val != 0)

//当val小于0时无限循环
#include <iostream>
using namespace std;

int factoyial1(int val) {
    if (val > 1)
        return factoyial1(val - 1) * val;
    return 1;
}
int factoyial2(int val) {
    if (val != 0)
        return factoyial2(val - 1) * val;
    return 1;
}
int main() {
    int aa;
    cout<<"Enter : ";
    cin>>aa;
    cout << "if(val  > 1) : " << factoyial1(aa) << endl;
    cout << "if(val != 0) : " << factoyial2(aa) << endl;
    return 0;
}
//6.35：在调用factorial函数时，为什么我们传入的值是val – 1而非 val–-?


#include <iostream>
using namespace std;

int factoyial1(int val) {
    if (val > 1) {
        return factoyial1(val - 1) * val;//5*4*3*2
    }
    return 1;
}
int factoyial2(int val) {
    if (val > 1) {
        return factoyial2(val--) * val;//4*3*2
    }
    return 1;
}
int factoyial3(int val) {
    if (val > 1) {
        return factoyial3(--val) * val;
    }
    return 1;
}
int factoyial4(int val) {
    if (val > 1) {
        cout<<"{"<<val<<"} ";
        return factoyial4(val - 1);//5 4 3 2
    }
    return 1;
}
int factoyial5(int val) {
    if (val > 1) {
        cout<<"{"<<val<<"} ";
        return factoyial5(--val);
    }
    return 1;
}
int factoyial6(int val) {
    if (val > 1) {
        cout<<"{"<<val<<"} ";
        return factoyial6(val--);//4 3 2
    }
    return 1;
}
int main() {
    int aa;
    cout<<"Enter : ";
    cin>>aa;
    cout << "val–1: " << factoyial4(aa) << endl;
    cout << "--val: " << factoyial5(aa) << endl;
    cout << "val–-: " << factoyial6(aa) << endl;
    return 0;
}
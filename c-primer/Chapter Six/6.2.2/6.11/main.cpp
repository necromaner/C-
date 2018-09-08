//6.11:编写并验证你自己的reset函数，使其作用于引用类型的参数。
#include "Chapter6.h"

int main() {
    int aa;
    cout<<"Enter:";
    cin>>aa;
    cout<<"before : "<<aa<<endl;
    reset(aa);
    cout<<"after  : "<<aa<<endl;
    return 0;
}
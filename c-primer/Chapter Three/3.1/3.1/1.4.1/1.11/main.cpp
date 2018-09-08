// 1.11 编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。

#include <iostream>
using std::cout;
using std::endl;
int main() {
    int val=0,x2=0;
    cout<<"Enter two numbers:";
    cin>>val>>x2;
    while(val<=x2){
        cout<<val<<endl;
        ++val;
    }
    return 0;
}
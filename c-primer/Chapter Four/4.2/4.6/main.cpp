//4.6：写出一条表达式用于确定一个整数是奇数还是偶数。

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    cout<<"Enter:";
    int aa=0;
    cin>>aa;
    if(aa%2==0)
        cout<<aa<<" is even number";
    else
        cout<<aa<<" is Odd number";
    return 0;
}
//4.10 为while循环写一个条件，使其从标准输入中读取整数，遇到42时停止。

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
int main() {
    int aa=0;
    while(aa!=42){
        cout<<"Enter number :";
        cin>>aa;
    }
    cout<<"End"<<endl;
    return 0;
}
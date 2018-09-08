//6.22：编写一个函数，令其交换两个int指针。

#include <iostream>
using namespace std;

int exchange(int *&xx,int *&yy){//int *&一个整数型指针的别名
    int *i=xx;
    xx=yy;
    yy=i;
}
int main() {
    int aa,bb;
    cout<<"Enter :";
    cin>>aa;
    cout<<"Enter :";
    cin>>bb;
    int* aaa=&aa;
    int* bbb=&bb;
    cout<<"before "<<*aaa<<" "<<*bbb<<endl;
    exchange(aaa,bbb);
    cout<<"after "<<*aaa<<" "<<*bbb<<endl;
    return 0;
}
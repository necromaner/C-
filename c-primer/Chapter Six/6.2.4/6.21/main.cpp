//6.21：编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。函数比较int的值和指针所指的值，返回较大的那个。在该函数中指针的类型应该是什么？

//指针的类型应该是int*
#include <iostream>
using namespace std;

int bigger(const int xx, const int *yy){
    return (xx>*yy)?xx:*yy;
}
int main() {
    int aa,bb;
    cout<<"Enter :";
    cin>>aa;
    cout<<"Enter :";
    cin>>bb;
    cout<<"Enter "<<aa<<" and "<<bb<<endl;
    cout<<"bigger is "<<bigger(aa,&bb)<<endl;
    return 0;
}
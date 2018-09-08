/*4.29：推断下面代码的输出结果并说明理由。实际运行这段程序。结果和你想象的一样吗？如果不一样，为什么？

int x[10];
 int *p=x;
cout<<sizeof(x)/sizeof(*x)<<endl;
cout<<sizeof(p)/sizeof(*p)<<endl;
*/


#include <iostream>
using std::cout;
using std::endl;
int main() {
    int x[10];
    int *p=x;
    cout<<sizeof(x)<<endl;//40
    cout<<sizeof(*x)<<endl;//4 一个int大小
    cout<<sizeof(x)/sizeof(*x)<<endl;//10
    cout<<sizeof(p)<<endl;//8 指针所占空间大小
    cout<<sizeof(*p)<<endl;//4 p所指空间大小
    cout<<sizeof(p)/sizeof(*p)<<endl;//2
    return 0;
}
//3.31：编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标的值。


#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main() {
    int i[10];
    for(int k=0;k!=10;++k) {
        i[k] = k;
        cout<<"i["<<k<<"] = "<<i[k]<<endl;
    }
    cout<<endl;
    return 0;
}
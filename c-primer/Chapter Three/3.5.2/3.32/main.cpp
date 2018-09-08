//3.32 将上一题刚刚创建的数组拷贝给另外一个数组。利用vector重写程序，实现类似的功能。

#include <iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
using std::string;

int main() {
    int i[10];
    for(int k=0;k!=10;++k) {
        i[k] = k;
    }
    int j[10];
    for(int m=0;m!=10;++m){
        j[m]=i[m];
    }
    cout<<"j = ";
    for(auto c:j)
        cout<<c<<" ";
    cout<<endl;
    vector<int> bb;
    for(int dd=0;dd!=10;++dd)
    {
        bb.push_back(dd);
    }
    cout<<"bb = ";
    for(auto e:bb)
        cout<<e<<" ";
    cout<<endl;

    return 0;
}
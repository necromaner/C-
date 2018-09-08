/*6.23:参考本节介绍的几个print函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的i和j：
int i = 0, j[2] = {0,1}
 */

#include <iostream>
using namespace std;

void print(int* i)
{
    if (i) cout << *i << endl;
}

void print1(const int *beg, const int *end){
    while(beg!=end) {
        cout << *beg++;
        if(beg!=end)
            cout<<",";
    }
    cout<<"}"<<endl;
    return;
}
int main() {
    int i = 0, j[2] = {0,1};
    cout<<"i = ";
    print(&i);
    cout<<"j[2] = {";
    print1(begin(j),end(j));
    return 0;
}
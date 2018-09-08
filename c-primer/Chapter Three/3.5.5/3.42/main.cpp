//3.42 编写一段程序，将含有整数元素的vector对象拷贝给一个整形数组。

#include <iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
int main() {
    int aa[]={};
    vector<int> bb={1,2,3,4};
    int x=0;
    for (auto i = bb.begin(); i!=bb.end(); ++i)
    {
        aa[x]=*i;
        ++x;
    }
    cout<<"aa = ";
    for(auto c:aa)
        cout<<c<<" "<<endl;
    return 0;
}
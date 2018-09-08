//3.41 编写一段程序，用整形数组初始化一个vector对象。

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
    int aa[]={1,2,3,4};
    vector<int> bb;
    for(int *i=begin(aa);i!=end(aa);++i)
        bb.push_back(*i);
    cout<<"bb = ";
    for (auto i = bb.begin(); i!=bb.end(); ++i)
    {
        cout << *i << " ";
    }
    return 0;
}
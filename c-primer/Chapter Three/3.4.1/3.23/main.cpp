//3.23：编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来的两倍。输出vector对象的内容，检验程序是否正确。

#include <iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    vector<int> aa;
    int bb;
    for(int i=0;i!=10;++i)
        {
            cout<<"Enter "<<i+1<<" :";
            cin>>bb;
            aa.push_back(bb);
        }
    auto cc=aa.begin();
    for (auto cc=aa.begin();cc!=aa.end();++cc)
        *cc*=*cc;
    cout<<"Result : ";
    for(auto cc=aa.begin();cc!=aa.end();++cc)
        cout<<*cc<<" ";
    cout<<endl;
    return 0;
}
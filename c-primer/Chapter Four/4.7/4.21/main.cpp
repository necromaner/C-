//练习4.21 编写一段程序，使用条件运算符从vector 中找到哪些元素的值是奇数，然后将这些奇数值翻倍。

#include <iostream>
#include<vector>
#include <cstring>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    /*
    cout<<"Enter:";
    vector<int> aa;
    int bb;
    while(cin>>bb)
        aa.push_back(bb);
        cout<<"Enter:";
        */
    vector<int> aa{1,2,3,4,5,6,7,8,9,10,11,12,14,16,13,15,17};
    cout<<"input :";
    for(auto dd:aa)
        cout<<dd<<" ";
    cout<<endl;
    cout<<"output:";
    for (auto cc=aa.begin();cc!=aa.end();++cc)
    {
        cout<<(((*cc%2)!=0)?(2*(*cc)):*cc) << " ";
    }
    cout << endl;
    return 0;
}
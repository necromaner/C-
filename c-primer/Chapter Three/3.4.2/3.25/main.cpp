//3.25 3.3.3节（第104页）划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序并实现完全相同的功能。

#include <iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    vector<int> aa;
    vector<int> bb{1,2,3,4,5,6,7,8,9,1};//0 2 1 1 1 1 1 1 1 1 0
    /*cout<<"Enter :";
    while(cin>>aa){
        if(aa<=100)
        aa=aa/10
        bb.push_back(aa);
        cout<<"Enter :";
    }*/
    vector<unsigned > scores(11,0);
    auto i2=scores.begin();
    for (auto i = bb.begin(); i !=bb.end(); ++i) {
        auto n=*i;
        ++*(i2+n);
    }
    for (auto j = scores.begin(); j != scores.end()-1; ++j) {
        cout<<*j<<" "<<endl;
    }
    return 0;
}
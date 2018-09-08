//5.17：假设有两个包含整数的vector对象，编写一段程序，检验其中一个vector对象是否是另一个的前缀。为了实现这一目标，对于两个不等长的vector对象，只需挑出长度较短的那个，把它的所有元素和另一个vector对象比较即可。例如，如果两个vector对象的元素分别是0，1，1，2和0，1，1，2，3，5，8，则程序的返回结果为真。

#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    int ii, jj,xx;
    vector<int> aa;
    vector<int> bb;

    cout<<"Enter first(close 999):";//输入第一组数字
    while(cin>>ii&&ii!=999) {
        aa.push_back(ii);
    }

    cout<<"Enter second(close 999):：";//输入第二组数字
    while(cin>>jj&&jj!=999) {
        bb.push_back(jj);
    }

    if(aa.size()>bb.size())//得到最短长度
        xx=bb.size();
    else
        xx=aa.size();

    for(int i=0;i<=xx-1;++i){//对比
        if(aa[i]!=bb[i])
            cout<<"No prefix"<<endl;
        else if(i==xx-1)
            cout<<"Yes prefix"<<endl;
    }

    return 0;
}
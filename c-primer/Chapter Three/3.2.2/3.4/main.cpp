//3.4 编写一段程序 读入两个字符串，比较是否相等并输出结果，如果不相等，输出较大的那个，改写上述程序，比较两个字符串长度是否相等，如果不等，输出长度大的那个字符串.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string aa,bb;
    cout<<"Enter first:";
    cin>>aa;
    cout<<"Enter second:";
    cin>>bb;
    if(aa==bb)
        cout<<"The same,is "<<aa<<endl;
    else
        if(aa>bb)
            cout<<"No same ,larger is "<<aa<<endl;
        else
            cout<<"No same ,larger is "<<bb<<endl;
    if(aa.size()==bb.size())
        cout<<"isometric "<<endl;
    else
    if(aa.size()>bb.size())
        cout<<"No isometric ,longer is "<<aa<<endl;
    else
        cout<<"No isometric ,longer is "<<bb<<endl;
    return 0;
}
//3.36 编写一段程序，比较两个数组是否相等。再写一段程序，比较vector对象是否相等。

#include <iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    int aa[]={1,2,3,4};
    int bb[]={1,2,3,0};
    int cc[]={1,2,3,4};
    int m=0,n=0;
    for(int i=0;i!=4;++i)
    {
        if(aa[i]==bb[i])
            ++m;
    }
    for(int i=0;i!=4;++i)
    {
        if(aa[i]==cc[i])
            ++n;
    }
    if(m==4)
        cout<<"aa =bb"<<endl;
    else
        cout<<"aa!=bb"<<endl;
    if(n==4)
        cout<<"aa =cc"<<endl;
    else
        cout<<"aa!=cc"<<endl;
    vector<int> aa1={1,2,3,4};
    vector<int> bb1={1,2,3,0};
    vector<int> cc1={1,2,3,4};
    auto aa2=aa1.begin();
    auto bb2=bb1.begin();
    auto cc2=cc1.begin();
    int m1=0;
    int n1=0;
    for (int i = 0; i!=4; ++i) {
        if (*(aa2 + i) == *(bb2 + i))
            ++m1;
    }
    for (int i = 0; i!=4; ++i) {
        if(*(aa2+i)==*(cc2+i))
            ++n1;
    }
    if(m1==4)
        cout<<"aa1 =bb1"<<endl;
    else
        cout<<"aa1!=bb1"<<endl;
    if(n1==4)
        cout<<"aa1 =cc1"<<endl;
    else
        cout<<"aa1!=cc1"<<endl;
    return 0;
}
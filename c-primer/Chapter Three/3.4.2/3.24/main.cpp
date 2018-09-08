//3.24：请使用迭代器重做3.3.3节（第105页）的最后一个练习。

//3.20 读入一组整数并把它们存入一个vector对象，将每对相邻整数的和输出出来。改写你的程序，这次要求先输出第1个和最后1个元素的和，接着输出第2个和倒数第2个元素的和，以此类推。

#include <iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int aa;
    vector<int> bb{10,20,30,40,50,60,70,100,120};
    /*while(cin>>aa)
        bb.push_back(aa);*/
    int j=0;
    for(auto i=bb.begin();i!=bb.end();++i)
    {
        cout<<"a["<<j<<"] + a["<<j+1<<"] = "<<(*i)+(*(i+1))<<endl;
        ++j;
    }
    int l=0;
    auto a = bb.begin();
    auto e =bb.end()-1;
    auto mid = a + (e-a)/2;
    while (a <= mid && e >= mid  )
    {
        cout<<"b["<<l<<"] + b["<<bb.size()-l<<"] = "<<*a+*e<<endl;
        l++;
        ++a;
        --e;
    }
    return 0;
}
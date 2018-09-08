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
    for(int i=0;i!=bb.size();++i)
    {
        cout<<"a["<<i<<"] + a["<<i+1<<"] = "<<bb[i]+bb[i+1]<<endl;
    }
    for (int j = 0; j != bb.size(); ++j) {
        cout<<"b["<<j<<"] + b["<<bb.size()-1<<"] = "<<bb[j]+bb[bb.size()-1]<<endl;
    }
    return 0;
}
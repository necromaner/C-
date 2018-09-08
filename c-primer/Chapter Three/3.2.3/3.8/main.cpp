//3.8 分别用while循环和传统for循环重写第一题的程序，你觉得那种形式更好
// /3.6:编写一段程序，使用范围for语句将字符串内的所有字符用X代替

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    string aa,bb,cc;
    cout<<"Enter :"<<endl;
    getline(cin,aa);
    bb=aa;
    cc=aa;
    int i=0;
    while(i<bb.size()) {
        if (isgraph(bb[i]))
            bb[i] = 'X';
        ++i;
    }
    cout<<"while :"<<bb<<endl;
    for(int j=0;j<cc.size();++j){
        if (isgraph(cc[j]))
        //if(cc[i]!=' ')
            cc[j] = 'X';
    }
    cout<<"for :"<<cc<<endl;
    return 0;
}
//6.42：给make_plural函数（参见6.3.2节，第201页）的第二个形参赋予默认实参‘s’,利用新版本的函数输出单词success和failure的单数和复数形式。
/*
string make_plural(size_t ctr, const string &word, const string &ending){
    return (ctr>1)?word+ending:word;
}
*/
#include <iostream>
#include<string>
using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending="s"){
    return (ctr>0)?word+ending:word;
}

int main() {
    bool a;
    cout<<"(singular input 0,plural input 1)"<<endl<<"Enter :";
    cin>>a;
    cout<<make_plural(a,"success","es")<<endl;
    cout<<make_plural(a,"failure","s")<<endl;

    return 0;
}
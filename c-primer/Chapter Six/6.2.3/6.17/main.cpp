//6.17：编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全都改成小写形式。在两个函数中你使用的类型相同吗？为什么？

//不一样，一个是const string &word,另一个是string &word
#include "Chapter6.h"


int main() {
    string word;
    cout<<"Enter word :";
    cin>>word;
    cout<<"Input : "<<word<<endl;
    if(inspect(word)){
        cout<<"Output: "<<change(word)<<endl;
    } else
        cout<<"No capital letters"<<endl;
    return 0;
}
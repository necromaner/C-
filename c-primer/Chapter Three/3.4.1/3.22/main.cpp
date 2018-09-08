//3.22 修改之前那个输出text第一段的程序，首先把text的第一段全都改成大写形式，然后再输出它。

#include <iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    vector<string>text;
    string word;
    cout<<"Enter word:";
    while(cin>>word)
    {
        text.push_back(word);
        cout<<"Enter word:";
    }
    auto it=text.begin();
    for (auto aa=(*it).begin();aa!=(*it).end();aa++)
        *aa=toupper(*aa);
    for(auto it=text.begin();it!=text.end();++it)
        cout<<*it<<endl;
    return 0;
}
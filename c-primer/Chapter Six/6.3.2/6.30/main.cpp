//6.30：编译第200页的str_subrange函数，看看你的编译器是如何处理函数中的错误的。

//returning 'void' from a function returning 'bool'

#include <iostream>
#include<string>
using namespace std;

bool str_subrange(const string &str1,const string &str2){
    if(str1.size()==str2.size())
        return str1==str2;
    auto size=(str1.size()<str2.size())
              ?str1.size():str2.size();
    for(decltype(size)i=0;i!=size;++i){
        if(str1[i]!=str2[i])
            return;//returning 'void' from a function returning 'bool'
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
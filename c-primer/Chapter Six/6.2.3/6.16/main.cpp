/*6.16：下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。

bool is_empty(string &s) {return s.empty()}
 */

#include <iostream>
#include <string>
using namespace std;

bool is_empty(const string &s) {//判断字符串是否为空
    return s.empty();//empty:字符串是空的话返回是true
}

int main() {
    string i=("aaas");
    if(is_empty(i))
        cout<<"yse"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
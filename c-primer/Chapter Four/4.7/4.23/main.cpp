/*4.23: 因为运算符的优先级问题，下面这条表达式无法通过编译。根据4.12节中的表（第147页）指出它的问题在哪里？应该如何修改？
    string s="word";
    string p1=s+s[s.size()-1]=="s"?"":"s";
 */


#include <iostream>

using std::string;
int main() {
    string s="word";
    string p1=((s+s[s.size()-1])=="s")?"":"s";

    return 0;
}
/*4.27：下列表达式的结果是什么？
unsigned long ul1 = 3, ul2 = 7;
(a) ul1 & ul2 (b) ul1 | ul2 (c) ul1 && ul2 (d) ul1 || ul2
 */

#include <iostream>

using std::cout;
using std::endl;
int main() {
    unsigned long ul1 = 3, ul2 = 7;//ul1 00000000 00000000 00000000 00000011 ul2 00000000 00000000 00000000 00000111
    cout<<(ul1 &  ul2)<<endl; //00000000 00000000 00000000 00000011
    cout<<(ul1 |  ul2)<<endl; //00000000 00000000 00000000 00000111
    cout<<(ul1 && ul2)<<endl; //ul1=3为真，ul2=7为真，true，为1
    cout<<(ul1 || ul2)<<endl; //ul1=3为真，ul2=7为真，true，为1
    return 0;
}
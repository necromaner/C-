/*3.37：下面的程序是何含义，程序的输出结果是什么？


    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp){
        cout << *cp << endl;
        ++cp;
    }
 */
/*输出
 * h
 * e
 * l
 * l
 * o
 * */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main(){
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp){
        cout << *cp << endl;
        ++cp;
    }
    return 0;
}
/*4.13：在下列语句中，当赋值完成后i和d的值分别是多少？
int i; double d;
(a). d = i = 3.5;
(b) i = d = 3.5;
*/

#include <iostream>
using std::cout;
using std::endl;

int main() {
    int i; double d;
    d = i = 3.5;//i=3,d=3.0
    cout<<"d = i = 3.5    d = "<<d<<"  i = "<<i<<endl;
    i = d = 3.5; //d=3.5,i=3
    cout<<"i = d = 3.5    i = "<<i<<"  d = "<<d<<endl;
    return 0;
}
/*5.7；改正下面代码段中的错误。

（a）
    if (iva11 != iva12)
        iva11 = iva12;
    else iva11 = iva12 = 0;

(b)
    if(ival < minval)
        minval = ival;
        occurs = 1;

(c)
    if (int ival = get_value())
        cout <<"ival = "<< ival << endl;
    if(!ival)
        cout<<"ival=0\n";

(d)
    if (ival = 0)
        ival = get_value();
*/

#include <iostream>

using std::cout;
using std::endl;

int main() {
    int iva11,iva12;
    if (iva11 != iva12)
        iva11 = iva12;
    else iva11 = 0, iva12 = 0;

    int ival,minval,occurs;
    if(ival < minval) {
        minval = ival;
        occurs = 1;
    }

    int ival2;
    if (ival2 = get_value())
        cout <<"ival = "<< ival << endl;
    else if(!ival)
        cout<<"ival=0\n";

    if (ival == 0)
        ival = get_value();

    return 0;
}
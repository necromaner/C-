/*4.37：用命名的强制类型转换改写下列旧式的转换语句。

int i; double d; const string *ps; char *pc; void *pv;

(a) pv = (void*)ps;  (b) i = int(*pc);

(c) pv = &d;    (d) pc = (char*) pv;
 */

#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main() {
    int i;
    double d;
    const string *ps;
    char *pc;
    void *pv;

    //pv = (void*)ps;
    pv= const_cast<void*>(ps);
    //i = int(*pc);
    i= static_cast<int>(*pc);
    //pv = &d;
    pv= static_cast<double *>(&d);
    //pc = (char*) pv;
    pc= static_cast<char *>(pv);//pc=reinterpret_cast<char *>(pv);
    return 0;
}
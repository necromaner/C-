/*5.18：说明下列循环的含义并改正其中的错误。

（a）
 do
    int v1, v2;
    cout <<"please enter two numbers to sum:";
    if (cin >> v1 >> v2)
        cout <<"sum is: " << v1 + v2 << endl;
    while (cin);
(b)
do {
//...
}while (int ival = get_response());

(c)
do {
int ival = get_response();
} while (ival);
*/

#include <iostream>
using namespace std;

int main() {

    do {                //缺少花括号
        int v1, v2;
        cout << "please enter two numbers to sum:";
        if (cin >> v1 >> v2)
            cout << "sum is: " << v1 + v2 << endl;
    }
    while (cin);

    int ival;
    do {
//...

    }while(ival = get_response());//变量要声明在do的条件部分

    int ival2;
    do {
        ival2 = get_response();
    } while (ival2);//ival是局部变量，出了括号，while不认识了
    return 0;
}
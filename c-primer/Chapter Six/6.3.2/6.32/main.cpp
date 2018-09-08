/*6.32：下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。

int &get(int *arry, int index){return arry[index];}
int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
 */

//合法的，给ia赋值{0，1，2，3，4，5，6，7，8，9}
#include <iostream>
using namespace std;

int &get(int *arry, int index){
    return arry[index];
}
int main() {
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
    for (int j = 0; j != 10; ++j)
        cout<<get(ia, j)<<" ";
    cout<<endl;
}
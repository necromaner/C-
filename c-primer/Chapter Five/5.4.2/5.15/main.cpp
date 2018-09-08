
/*5.15：说明下列循环的含义并改正其中的错误。

(a). for (int ix = 0; ix != sz; ++ix) {/*…* /}
if( ix != sz)
        //...
(b).

int ix;
for (ix != sz; ++x) {/*…* /}


(c).for (int ix = 0; ix != sz; ++ix, ++sz) {/*…* /}
*/
#include <iostream>

int main() {
    for (int ix = 0; ix != sz; ++ix) {//ix在for内定义，所以if要在for里
    if (ix != sz){}
}


    for (int ix=0;ix != sz; ++x) {/*…*/}//少加分号,而且ix没有初始化

    for (int ix = 0; ix != sz; ++ix/*,++sz*/) {/*…*/}//无限循环
    return 0;
}
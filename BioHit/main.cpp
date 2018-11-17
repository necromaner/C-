#include "commentMove/position.h"
#include "add/add.h"
#include <iostream>
using namespace std;
int main() {
//    string s;
//    cin>>s;
//    Position position("");
//    position.mobile(30);



    Add add;
//    int a=10;
//    int b=20;
//    int c=2;
//    int d=1;
//    add.resizeDigital(a,b,c,d);
//    printf("%d--%d--%d--%d",a,b,c,d);
    double ChxBuf[4][2000]; //荧光采集的初始值
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2000; ++j) {
            ChxBuf[i][j]=i*0.1+j;
        }
    }
    int index=1;
    add.x(&ChxBuf[index][10]);
    return 0;
}
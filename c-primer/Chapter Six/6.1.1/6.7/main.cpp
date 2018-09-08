//6.7：编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1。

#include <iostream>
using namespace std;

int abc(){
    static size_t cc=0;
    return ++cc;
}
int main() {
    for(int i=10;i>0;i--){
        cout<<abc()<<endl;
    }
    return 0;
}
//5.22：本节的最后一个例子跳回到begin,其实使用循环能更好地完成该任务，重写这段代码，注意不再使用goto语句。



#include <iostream>

using namespace std;

int get_size()
{
    return 5;
}

int main() {
    int sz=-1;
    //代码
    begin:
    sz=get_size();
    if(sz<=0){
        goto begin;
    }
    //修改后
    sz=get_size();
    while(sz<=0)
        sz=get_size();
    return 0;
}
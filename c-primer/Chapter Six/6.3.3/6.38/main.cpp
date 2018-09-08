//6.38:修改arrPtr函数，使其返回数组的引用。
/*
int odd[]={1,3,5,7,9};
int even[]={0,2,4,6,8};
decltype(odd)*arrPtr(int i){
    return ((i%2)?&odd:&even);
}*/

#include <iostream>

int main() {
    int odd[]={1,3,5,7,9};
    int even[]={0,2,4,6,8};
    decltype(odd)&arrPtr(int i){
        return ((i%2)?odd:even);
    }
    return 0;
}
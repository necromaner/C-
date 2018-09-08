//3.19：如果想定义一个含有10个元素的vector对象，所有元素的值都是42，请列举出三种不同的实现方法。哪种方法更好呢？为什么？
//vector<int> a1(10,42);这种方法好
#include <iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    vector<int> a1(10,42);
    vector<int> a2{42,42,42,42,42,42,42,42,42,42};
    vector<int> a3(10);
    for(int i=0;i!=10;++i){
        a3[i]=42;
    }
    cout<<"a1 = ";
    for(int i=0;i!=10;++i){
        cout<<a1[i]<<" ";
    }
    cout<<endl;
    cout<<"a2 = ";
    for(int i=0;i!=10;++i){
        cout<<a2[i]<<" ";
    }
    cout<<endl;
    cout<<"a3 = ";
    for(int i=0;i!=10;++i){
        cout<<a3[i]<<" ";
    }
    cout<<endl;
    return 0;
}
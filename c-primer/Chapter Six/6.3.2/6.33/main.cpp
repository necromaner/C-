//6.33：编写一个递归函数，输出vector对象的内容。 

#include <iostream>
#include <vector>
using namespace std;

int output(const vector<int>aa,unsigned long bb){
    static unsigned long cc = bb;
    if(cc-bb<cc){
        cout<<aa[cc-bb]<<" ";
        return output(aa,bb-1);
    }
}
int main() {
    vector<int> vec{1,2,3,4,5,6,7,8,9,0};
    unsigned long a=vec.size();
    cout<<"output :";
    output(vec,a);
    return 0;
}
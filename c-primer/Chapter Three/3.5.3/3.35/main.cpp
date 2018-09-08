//3.35：编写一段程序，利用指针将数组中的元素置为0.

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    int aa[]={1,2,3,4,5,6,7};
    int *bb=aa;
    cout<<"aa = ";
    for(int c=0;c!=6;++c){
        *bb=0;
        cout<<aa[c];
        ++bb;
    }

    return 0;
}
#include "Output.h"
void executable(string folder,int file,vector<string> other){
    //add_executable(T1_01 T1/T1.cpp Output.cpp)
    for (int i = 1; i < file+1; ++i) {
        printf("add_executable(%s_",folder.c_str());
        if(i<10)
            printf("0");
        printf("%d %s/T%d.cpp",i,folder.c_str(),i);
        for (int j = 0; j < other.size(); ++j) {
            printf(" %s.cpp",other[j].c_str());
        }
        printf(")\n");
    }
}
int main() {
    string folder="T1";
    int file=18;
    vector<string> other={"Output","TestCase"};
    executable(folder,file,other);
    return 0;
}
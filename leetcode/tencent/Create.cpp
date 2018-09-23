#include "Output.h"
struct Data{
    string folder;
    int file;
    vector<string> other;
};
void executable(string folder,int file,vector<string> other){
    //add_executable(T1_01 T1/T1.cpp Output.cpp)
    printf("\n");
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
    Data data={"T3",5,{"Output"}};
    executable("T3",5,data.other);
    executable("T4",8,data.other);
    executable("T5",4,data.other);
    executable("T6",6,data.other);
    executable("T7",2,data.other);
    executable("T8",1,data.other);
    return 0;
}
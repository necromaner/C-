#include "Output.h"
#define    FINISH_FLAG    "FILE_TRANSPORT_FINISH"
int file_size(string filename) {
    FILE *fp=fopen(filename.c_str(),"r");
    if(!fp) return -1;
    fseek(fp,0L,SEEK_END);
    int size=ftell(fp);
    fclose(fp);
    return size;
}
//新建一个二维数组
//max:最大数
//size:vector<int >长度
//返回：从1到max的二维数组
vector<vector<int >> newVector(int max,int size){
    vector<vector<int >> xx;
    int y=max/size+1;
    for (int i = 0; i < y; ++i) {
        vector<int> xs;
        for (int j = 0; j < size; ++j) {
            int z = i * size + j + 1;
            if (z <= max)
                xs.push_back(z);
            else
                xs.push_back(0);
        }
        xx.push_back(xs);
    }
    return xx;
}
void q(char* x){
    printf("%s\n",x);
}
int main() {
//    vector<bool> x(10, false);
    
//    string file1="/Users/necromaner/program/C-/UDP/test/send/send.txt";
//    string file2="/Users/necromaner/program/C-/UDP/test/send/send.txt";
//    string file3=file1+file2;
//    outPut(file3);
//    vector<bool> xx1={false,};
//    vector<vector<int>> xx=newVector(1234,100);
//    outPut(1,xx);
    q(FINISH_FLAG);
    return 0;
}
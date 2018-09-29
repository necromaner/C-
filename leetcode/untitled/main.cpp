#include<stdio.h>
#include<string>
using namespace std;
#include "Md5.hpp"
int file_size(string filename)
{
    FILE *fp=fopen(filename.c_str(),"r");
    if(!fp) return -1;
    fseek(fp,0L,SEEK_END);
    int size=ftell(fp);
    fclose(fp);
    
    return size;
}
string MD5(char* buf){
    string answer="";
    unsigned char encrypt[]="";
    unsigned char decrypt[16];
    sprintf(reinterpret_cast<char *>(encrypt),buf);
    MD5_CTX md5;
    
    MD5Init(&md5);
    MD5Update(&md5, encrypt, (int)strlen((char *)encrypt));//只是个中间步骤
    MD5Final(&md5, decrypt);//32位
    for (int i = 1; i<16; i++){
        
        char firstNum[32] = {0};
        sprintf(firstNum, "%02x", decrypt[i]);
        answer.push_back(firstNum[0]);
        answer.push_back(firstNum[1]);
    }
    return answer;
}
struct Data{
    char buf[984];
    int num;
    char md5[32];
};
int main()
{
    
    FILE *fp1;
    FILE *fp2;
    string file1="/Users/necromaner/test/send/2.zip";
    string file2="/Users/necromaner/test/send/send3.zip";
    fp1=fopen(file1.c_str(),"rb+");
    int x=file_size(file1);
    fp2=fopen(file2.c_str(),"w+");
    fclose(fp2);
    fp2=fopen(file2.c_str(),"rb+");
    
    
    Data data{};
    int max=984;
    
    for (int i = 0; i < 11; ++i) {
        fseek(fp1,i*max, SEEK_SET);
        fread(data.buf, sizeof(char), max, fp1);
        printf("%d---%s\n",i,MD5(data.buf).c_str());
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
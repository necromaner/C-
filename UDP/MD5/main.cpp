#include <iostream>
#include "Md5.h"
#include "SHA1.h"
using namespace std;

int file_size(string filename)
{
    FILE *fp=fopen(filename.c_str(),"r");
    if(!fp) return -1;
    fseek(fp,0L,SEEK_END);
    int size=ftell(fp);
    fclose(fp);
    
    return size;
}
struct Data{
    char buf[984];
    int num;
    char md5[32];
};
int main() {
//
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
    
    
    
    
    for (int i = 0; i < 14; ++i) {

        fseek(fp1,i*max, SEEK_SET);
        fread(data.buf, sizeof(char), max, fp1);


        CSHA1 sha1;
        sha1.Update((unsigned char*)data.buf,strlen(data.buf));
        sha1.Final();
        unsigned char chSha1[20] = "";
        sha1.GetHash(chSha1);
        printf("%d----%s\n",i,chSha1);
    }
    
    
//    Md5Encode md5;
//    for (int i = 0; i < 100; ++i) {
//
//        fseek(fp1,i*max, SEEK_SET);
//        fread(data.buf, sizeof(char), max, fp1);
//        printf("%d---%s\n",i,md5.Encode(data.buf).c_str());
//    }


    return 0;
}
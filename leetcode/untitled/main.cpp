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
struct Data{
    char buf[BUFSIZ];
    int num;
    string md5;
};
string MD5(char* buf){
    string answer="";
    unsigned char encrypt[]="";
    unsigned char decrypt[16];
    sprintf(reinterpret_cast<char *>(encrypt),buf);
    MD5_CTX md5;
    
    MD5Init(&md5);
    MD5Update(&md5, encrypt, (int)strlen((char *)encrypt));//只是个中间步骤
    MD5Final(&md5, decrypt);//32位
    for (int i = 0; i<16; i++){
        
        char firstNum[32] = {0};
        sprintf(firstNum, "%02x", decrypt[i]);
        answer.push_back(firstNum[0]);
        answer.push_back(firstNum[1]);
    }
    return answer;
}
struct XX{
    char buf[300];
    int x;
};
int main()
{
    
    FILE *fp1;
    FILE *fp2;
    string file1="/Users/necromaner/program/C-/UDP/test/send/send4.txt.zip";
    string file2="/Users/necromaner/program/C-/UDP/test/send/send3.txt.zip";
    fp1=fopen(file1.c_str(),"rb+");
    int x=file_size(file1);
    fp2=fopen(file2.c_str(),"w+");
    fclose(fp2);
    fp2=fopen(file2.c_str(),"rb+");
//    fwrite("", sizeof(char), x, fp2);
    
    
    
//    char buf[300];
    int max=300;
    string ss="charu";
//    for (int i = 0; i <= x/max; ++i) {
//        fseek(fp1, i*max, SEEK_SET);
//        if(i==x/max){
//            fread(buf, sizeof(char), x%max, fp1);
//            printf("最后=%s|-(循环%d次)\n",buf,i+1);
//            fwrite(buf, sizeof(char), x%max, fp2);
//        } else{
//            fread(buf, sizeof(char), max, fp1);
//            printf("buf=%s\n",buf);
//            fwrite(buf, sizeof(char), max, fp2);
//        }
//    }
    
    
    char buf1[300];
    char buf2[300];
    char buf3[300];
    char buf11[400];
    char buf21[400];
    char buf31[300];
    
    XX xx1;
    XX xx2;
    XX xx3;
    fseek(fp1, 0*max, SEEK_SET);
    fread(buf1, sizeof(char), max, fp1);
    fread(xx1.buf, sizeof(char), max, fp1);
//    sprintf(buf11,"%s/%s",buf1,MD5(buf1).c_str());
    sprintf(buf11,"%s",buf1);
    xx1.x=0;
    
    printf("md5=%s\n",MD5(buf1).c_str());
    printf("md5=%s\n",MD5(buf11).c_str());
    
    printf("buf=%s\n",buf1);
    printf("buf=%s\n\n",buf11);
    

    fseek(fp1, 1*max, SEEK_SET);
    fread(buf2, sizeof(char), max, fp1);
//    sprintf(buf21,"%s/%s",buf2,MD5(buf2).c_str());
    sprintf(buf21,"%s",buf2);
    printf("buf=%s\n",buf2);
    printf("buf=%s\n\n",buf21);
    
    

    fseek(fp1, 2*max, SEEK_SET);
    fread(buf3, sizeof(char), x%max, fp1);
//    sprintf(buf31,"%s/%s",buf3,MD5(buf3).c_str());
    sprintf(buf31,"%n",buf3);
    printf("最后=%s\n",buf3);
    printf("最后=%s\n",buf31);
    
    
    fseek(fp2, 2*max, SEEK_SET);
    fwrite(buf31, sizeof(char), x%max, fp2);
    
    
    
    fseek(fp2, 1*max, SEEK_SET);
    fwrite(buf2, sizeof(char), max, fp2);
    
    
    
    
    fseek(fp2, 0*max, SEEK_SET);
    fwrite(buf1, sizeof(char), max, fp2);








//    fseek(fp1, 0, SEEK_SET);
//    fread(buf, sizeof(char), 10, fp1);
//    fwrite(buf, sizeof(char), 10, fp2);


//    int x=100;
////    fwrite("", sizeof(char), x, fp);
//    int xx[]={10,20,30,50,60,70};
//    int now=0;
//    if(NULL != fp) {
//        for (int i = 0; i <x;i+=10) {
//            if (xx[now]==i) {
//                if (-1 == (fseek(fp, i, SEEK_SET)))
//                    printf("seek error\n");
//                fwrite("123456789\n", sizeof(char), 10, fp);
//                now++;
//            }
//        }
//        fclose(fp);
//    }
//    else
//    {
//        printf("fopen error");
//        return 0;
//    }
    fclose(fp1);
    fclose(fp2);
    
    
    fp1=fopen(file1.c_str(),"rb+");
    fp2=fopen(file2.c_str(),"rb+");
    
    char xx1[2000];
    char xx2[2000];
    fread(xx1, sizeof(char), 3, fp1);
    fread(xx2, sizeof(char), 3, fp2);
    
    
    printf("md5=%s------%s\n",MD5(xx1).c_str(),xx1);
    printf("md5=%s------%s\n",MD5(xx2).c_str(),xx2);
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}
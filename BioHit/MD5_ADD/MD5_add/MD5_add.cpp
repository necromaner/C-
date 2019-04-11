//
// Created by necromaner on 2019-03-06.
//

#include "MD5_add.h"
#include <stdio.h>
#define SIZE_FILE 1000000
#define SIZE_MD5 32
#define SIZE_HEAD 10
MD5_add::MD5_add() {}

MD5_add::~MD5_add() {

}
MD5_add::MD5_add(string old_file,string new_file){
    file.newFile(new_file);
//    printf("%s--%s\n",old_file.c_str(),new_file.c_str());
}

bool File::newFile(string new_file) {
    fp = fopen(new_file.c_str(), "w+");
    fclose(fp);
    return true;
}

char *File::readFile(string old_file) {
    char *read=new char[SIZE_FILE];
    fp = fopen(old_file.c_str(), "rb+");
    fseek(fp, 0, SEEK_SET);//读取开始坐标位置
    fread(read, sizeof(char), SIZE_FILE, fp);
    fclose(fp);
    printf("---%s==\n",read);
    return read;
}
char *File::readFile(string old_file, long size) {
    char *read=new char[SIZE_FILE];
    fp = fopen(old_file.c_str(), "rb+");
    fseek(fp, size, SEEK_SET);//读取开始坐标位置
    fread(read, sizeof(char), SIZE_FILE, fp);
    fclose(fp);
    printf("---%s==\n",read);
    return read;
}
char *File::readFile(string old_file, long size,long length) {
    char *read=new char[SIZE_FILE];
    fp = fopen(old_file.c_str(), "rb+");
    fseek(fp, size, SEEK_SET);//读取开始坐标位置
    fread(read, sizeof(char), length, fp);
    fclose(fp);
    return read;
}

int File::sizeFile(string old_file) {
//    fp = fopen(getFileName().c_str(), "rb+");
    return 0;
}
long long File::file_Size(string old_file) {
    fp = fopen(old_file.c_str(), "r");
    if (!fp) return -2;
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    return size;
}

//bool File::writeFile(string new_file, char *head,char *md5,char *data) {
//
//    fp = fopen(new_file.c_str(), "rb+");
////    fseek(fp,0, SEEK_SET);//写入坐标
//    fwrite(head, sizeof(char), (size_t) SIZE_FILE, fp);
//    fclose(fp);
//    return false;
//}
bool File::writeFile(string new_file,char *data, unsigned long size) {

    fp = fopen(new_file.c_str(), "at");
//    fseek(fp,0, SEEK_SET);//写入坐标
    fwrite(data, sizeof(char), (size_t) size, fp);
    fclose(fp);
    return false;
}

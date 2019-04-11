//
// Created by necromaner on 2019-03-06.
//

#ifndef MD5_ADD_MD5_ADD_H
#define MD5_ADD_MD5_ADD_H

#include <string>
using namespace std;
class File{
private:
    FILE *fp;                                         //文件
public:
    bool newFile(string new_file);
    int sizeFile(string old_file);
    char *readFile(string old_file);
    char *readFile(string old_file, long size);
    char *readFile(string old_file, long size,long length);
//    bool writeFile(string new_file, char *head,char *md5,char *data);
    bool writeFile(string new_file,char *data,unsigned long size);
    long long file_Size(string old_file);
};
class MD5_add {
private:
    File file;
public:
    virtual ~MD5_add();

    MD5_add();
    MD5_add(string old_file,string new_file);
};


#endif //MD5_ADD_MD5_ADD_H

//
// Created by 温亚奇 on 2018/9/8.
//

#ifndef TENCENT_OUTPUT_H
#define TENCENT_OUTPUT_H

#include<vector>
#include<string>
#include <iostream>
#include<map>
#include <stack>
using namespace std;

void outPut();

void outPut(vector<int> strs);
void outPut(int output,vector<int> strs);
void outPut(string output,vector<int> strs);

void outPut(vector<string> strs);
void outPut(int output,vector<string> strs);
void outPut(string output,vector<string> strs);

void outPut(vector<vector<int>> strs);
void outPut(int output,vector<vector<int>> strs);
void outPut(string output,vector<vector<int>> strs);

void outPut(int strs);
void outPut(int output,int strs);
void outPut(string output,int strs);

void outPut(bool s);
void outPut(int output,bool s);
void outPut(string output,bool s);

void outPut(string s);
void outPut(int output,string s);
void outPut(string output,string s);

void outPut(double s);
void outPut(int output,double s);
void outPut(string output,double s);

void problem(string filepath,string s);

#endif //TENCENT_OUTPUT_H

//
// Created by necromaner on 2019-02-18.
//

#ifndef MODULE_M1_H
#define MODULE_M1_H
#define QQQ "q"
#define WWW "2"

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
typedef struct FoundPeakVol
{
    int Location;
    double ReadData;
}FoundPeakVol;
class M1 {
public:
    void T1();
    void T2();
    void T3();
    void T4(int DX_c);
    void T5();
    FoundPeakVol* T6();
    char* T7();
    void Rank_Data(FoundPeakVol *arr, int lengh);
//    bool ReWriteFile(QString Key, QString Data);
};



#endif //MODULE_M1_H

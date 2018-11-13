//
// Created by necromaner on 2018/11/9.
//

#include "add.h"

Add::Add() {}
Add::~Add() {}


void Add::resizeDigital(int &Mea_Limit,int &Mea_Max,int &Ref_Limit,int &Ref_Max){
    int num[4];
    num[0]=Mea_Limit;
    num[1]=Ref_Limit;
    num[2]=Ref_Max;
    num[3]=Mea_Max;
    for (int i = 0; i < 3; ++i) {
        for (int j = 2; j < 4; ++j) {
            if(num[i]>num[j]){
                int x=num[i];
                num[i]=num[j];
                num[j]=x;
            }
        }
    }
    Mea_Limit=num[0];
    Ref_Limit=num[1];
    Ref_Max=num[2];
    Mea_Max=num[3];
}

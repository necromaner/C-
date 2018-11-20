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

void Add::x(double *bufP){
    double Samll_Peak[180] = {0};
    int iDiff = 0;
    int iSum = 0;
    int iDex = 0;
    for(int i = 0; i < 180; i++)                            //   将曲线原值进行滤波处理
    {
        iDiff = 1800 - iDex;
        if(iDiff > 10)
        {
            iDiff = 10;
        }
        printf("%4d-%4d\n",iDiff,1800 - iDex);
        iSum = 0;
        for(int j = i * 10; j < i * 10 + iDiff; j++)
        {
            iSum += bufP[j];//bufP：荧光采集的初始值
            Samll_Peak[i] =   iSum / iDiff;
            iDex++;
            printf("%4d-%2d-%5.1f-%3d-%5d-%4d-%3.1f\n",i,j,Samll_Peak[i],iDiff,iSum,iDex,bufP[i]);
        }
        printf("\n");
    }
}
void Add::x1() {
//
//    string Rank_str;
//    int c_Left = 0;
//    int c_Right = 0;
//    int C_Lefttimes = 0;
//    int C_Righttimes = 0;
//    bool isCpeakOK = false;
//    bool ok = false;
//    for (int i = 170; i > 10; i--)                           //在滤波之后的曲线的倒数曲线寻找峰值点
//    {
//
//        C_Lefttimes = 0;
//        C_Righttimes = 0;
//        c_Left = i - 5;
//        c_Right = i + 5;
//        for (int j = c_Left; j < i; j++) {
//            if (Samll_Rank[j] > 0) {
//                C_Lefttimes++;
//            } else if (Samll_Rank[j] < 0) {
//                break;
//            }
//        }
//        if (C_Lefttimes > 1) {
//            for (int k = i; k < c_Right; k++) {
//                if (Samll_Rank[k] < 0) {
//                    C_Righttimes++;
//                } else {
//                    break;
//                }
//            }
//        }
//        if (C_Righttimes > 1) {
//            if (isCpeakOK == false) {
//                isCpeakOK = true;
//                Rank_str += ";";
//            }
//            Rank_str += QString::number(i) + ",";
//        } else {
//            isCpeakOK = false;
//        }
//    }
//    cout<< "We found Rank_str " << Rank_str;

}

void Add::x2(int DX_c){
    int bufP[1800];
    for (int k = 0; k < 1800; ++k) {
        bufP[k] = k;
    }
    for (int l = 0; l < 1800; ++l) {
        printf("%4d ", bufP[l]);
        if ((l + 1) % 100 == 0)
            printf("\n");
    }
    printf("---------------------------\n");
    if (DX_c < 0) {
        for (int i = 0; i < 1800 + DX_c; i++) {
            bufP[i] = bufP[i - DX_c];
        }
        for (int i = 1800 + DX_c; i < 1800; i++) {
            bufP[i] = bufP[1799 + DX_c];
        }
    } else if (DX_c > 0) {
        for (int i = 1799; i > DX_c; i--) {
            bufP[i] = bufP[i - DX_c];
        }
        for (int i = DX_c; i > 0; i--) {
            bufP[i] = bufP[DX_c];
        }
    }

    for (int l = 0; l < 1800; ++l) {
        printf("%4d ", bufP[l]);
        if ((l + 1) % 100 == 0)
            printf("\n");
    }
}
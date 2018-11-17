//
// Created by necromaner on 2018/11/9.
//

#ifndef BIOHIT_ADD_H
#define BIOHIT_ADD_H

#include <iostream>
using namespace std;

class Add {
public:
    Add();
    virtual ~Add();
    void resizeDigital(int &Mea_Limit,int &PG1_Mea_Max,int &Ref_Limit,int &Ref_Max);
    void x(double *bufP);
    void x1();
};


#endif //BIOHIT_ADD_H

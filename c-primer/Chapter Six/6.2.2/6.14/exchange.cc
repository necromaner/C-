#include "Chapter6.h"

void exchange1(int &xx,int &yy){
    int i=xx;
    xx=yy;
    yy=i;
}

void exchange2(int *xx,int *yy){
    int i=*xx;
    *xx=*yy;
    *yy=i;
}
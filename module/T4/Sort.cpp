#include "Sort.h"
void quickSort1(vector<int> &x,int min1,int max1) {
    int min = min1;
    int max = max1;
    int now = x[min1];
    bool b = false;
    while (min < max) {
        if (b) {
            if (now < x[min]) {
                x[max] = x[min];
                x[min] = now;
                b = false;
                max--;
            } else
                min++;
        } else {
            if (now >= x[max]) {
                x[min] = x[max];
                x[max] = now;
                b = true;
                min++;
            } else
                max--;
        }
    }
    if (min1 < min) quickSort1(x, min1, min - 1);
    if (max1 > max) quickSort1(x, max + 1, max1);
}
void quickSort(vector<int> &x){
    quickSort1(x,0,  (int)x.size()-1);
}

void outPut(vector<int> s){
    int max_length=0;
    for (int k = 0; k < s.size(); ++k) {
        int max = (int)to_string(s[k]).size();
        if (max_length < max) {
            max_length = max;
        }
    }
    printf("[");
    for (int i = 0; i < s.size(); ++i) {
        int max=(int)to_string(s[i]).size();
        for (int k = 0; k < max_length-max; ++k) {
            printf(" ");
        }
        printf("%d",s[i]);
        if(i<s.size()-1)
            printf(",");
    }
    printf("]\n");
}
void outPut_quickSort(vector<int> s){
    printf("排序前:");
    outPut(s);
    printf("排序后:");
    quickSort(s);
    outPut(s);
}
/*6.39：说明在下面的每组声明中第二条声明语句是何含义。如果有非法的声明，请指出来。

(a）. int calc(int,int);
      int calc(const int, const int);

(b). int get();
   double get();

(c). int *reset(int *);
   double *reset(double *);
   */

#include <iostream>

int main() {
    int calc(int, int);
    int calc(const int, const int);//定义一个整型函数calc，有两个const int型形参。非法：重复声明

    int get();
    double get();//定义一个double型函数。非法：无法判断调用哪个函数

    int *reset(int *);
    double *reset(double *);//定义一个double*类型指针函数，行参为double*
    return 0;
}
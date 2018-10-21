#include "operator.h"
/*
 * 运算符优先级练习
 */

int T1::t1_1() {//()调节优先级的括号操作符
    return (a + b) / 2;
}
int T1::t1_2() {//[]数组下标访问操作符
    return c[2] / 2;
}
int T1::t1_3() {//->通过指向对象的指针访问成员的操作符
    return c[2] / 2;
}
int T1::t1_4() {//.通过对象本身访问成员的操作符
    return c[2] / 2;
}
int T1::t1_5() {//::作用域操作符
    return c[2] / 2;
}
int T1::t1_6() {//++后置自增操作符
    return a++ + b;
}
int T1::t1_7() {//--后置自减操作符
    return a-- + b;
}


void t2() {//右到左
    int a = 1, b = 2;
    int c[] = {1, 2, 3};
//-负号运算符
    int d = -a / 2;
    printf("d=%d\n", d);
//(类型)强制类型转换
    double e = (double) a / 2;
    printf("e=%f\n", e);
//前置++
    int f = - ++a;
    printf("f=%d\n", f);
    printf("a=%d\n", a);
//前置--
//*取值运算符
//&取地址运算符
int i=*&a;
    printf("i=%d\n", i);
//!逻辑非运算符
//~按位取反运算符
//sizeof长度运算符
}
void t3(){//左到右
// /除
//*乘
//%余数
}
void t4(){//左到右
//+加
//-减
}
void t5(){//左到右
//<<左移
//>>右移
}
void t6(){//左到右
//>大于
//>=大于等于
//<小于
//<=小于等于
}
void t7(){//左到右
//==恒等于
//!=不等于
}
void t8(){//左到右
//&按位与
}
void t9(){//左到右
//^按位异或
}
void t10(){//左到右
//|按位或
}
void t11(){
//&&逻辑与//左到右
}
void t12(){//左到右
//||逻辑或
}
void t13(){//右到左
//?:条件运算符
}
void t14(){//右到左
//=赋值运算符
///=除后赋值
//*=乘后赋值
//%=取模后赋值
//+=加后赋值
//-=减后赋值
//<<=左移后赋值
//>>=右移后赋值
//&=按位与后赋值
//^=按位异或后赋值
//|=按位或后赋值
}
void t15(){//左到右
//,逗号运算符
}
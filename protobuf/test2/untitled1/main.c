#include <dos.h>

#include <stdio.h>
/*

1b 40 初始化打印机

1b 20 0 设置字间距为0

1b 63 0 反向打印

1b 38 0 16*16 汉字打印

1b 57 2 放大两倍

1b 36   调用字符集1

0A 0D   换行,回车

*/
#define PROTADDRESS 0x378

#define DATA PROTADDRESS+0

#define CONTROL PROTADDRESS+2

#define STATUS PROTADDRESS+1

unsigned char init[11] ={0x1b,0x40,0x1b,0x20,0x00,0x1b,0x63,0x0,0x1b,0x38,0x0};

unsigned char fangda[3]={0x1b,0x57,0x02};

unsigned char huanyuan[3]={0x1b,0x57,0x01};

unsigned char shuju[11]="   灭菌记录";

unsigned char shuju1[45]={0x1b,0x36,

0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,0xde,

0x1b,0x38,0x00};

unsigned char shuju2[]="日期:2008年7月21日";

unsigned char shuju3[]="批号:000012456";

unsigned char shuju4[]="品名:ABC";

unsigned char shuju5[]="操作员:001";

unsigned char shuju6[]="设定温度:121℃";

unsigned char shuju7[]="设定时间:30分";

unsigned char shuju8[]="时间:08-07-21 温度  F0值";

char lprintf(unsigned char value) {
    int c = 0;

    while (c == 0x00) { c = inportb(STATUS) & 0x80; }

    outportb(DATA, value);

    c = 0x03;

    outportb(CONTROL, c);

    c = inportb(CONTROL);

    c = 0x02;

    outport(CONTROL, c);

    return 0;

}

main() {
    int i;

    i = inportb(STATUS);

    i = inportb(CONTROL);

    i = 0x02;

    outportb(CONTROL, i);

    i = inportb(CONTROL);

    for (i = 0; i < 11; i++) { lprintf(init[i]); }

    for (i = 0; i < 3; i++) { lprintf(fangda[i]); }

    for (i = 0; i < 11; i++) { lprintf(shuju[i]); }

    lprintf(0x0d);

    for (i = 0; i < 3; i++)

        lprintf(huanyuan[i]);

    for (i = 0; i < strlen(shuju1); i++) { lprintf(shuju1[i]); }

    lprintf(0x0d);

    for (i = 0; i < strlen(shuju2); i++) { lprintf(shuju2[i]); }

    lprintf(0x0d);

    for (i = 0; i < strlen(shuju3); i++) { lprintf(shuju3[i]); }

    lprintf(0x0d);

    for (i = 0; i < strlen(shuju4); i++) { lprintf(shuju4[i]); }

    lprintf(0x0d);

    for (i = 0; i < strlen(shuju5); i++) { lprintf(shuju5[i]); }

    lprintf(0x0d);

    for (i = 0; i < strlen(shuju1); i++) { lprintf(shuju1[i]); }

    lprintf(0x0d);

    for (i = 0; i < strlen(shuju6); i++) { lprintf(shuju6[i]); }

    lprintf(0x0d);

    for (i = 0; i < strlen(shuju7); i++) { lprintf(shuju7[i]); }

    lprintf(0x0d);

    for (i = 0; i < strlen(shuju1); i++) { lprintf(shuju1[i]); }

    lprintf(0x0d);

    for (i = 0; i < strlen(shuju8); i++) { lprintf(shuju8[i]); }

    lprintf(0x0d);

    lprintf(0x0d);

    lprintf(0x0d);

    lprintf(0x0d);

    lprintf(0x0d);

    printf("\n press ENTER to quit \n");

    while ((i = getchar()) != '\n')

        printf("%c", i);

    return 0;

}
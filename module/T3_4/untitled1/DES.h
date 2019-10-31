#pragma once
#include "table.h"
#include <iostream>
/*
*构造方法:传入秘钥(即c字符串),并,将c字符串转化为内部类(DESKey),内部类处理c字符串,转化为能处理的数据结构
*bdata-n,秘钥长度是固定的.
*
*使用方法: 外部调用public函数decode(char*)或者decode(bdata*),鉴于这是一个工具类,我们不需要添加bdata结构对象.
*返回一个bdata-n数组指针.外部调用encode(bdata*)
*
*/
class DES {
public:
    typedef struct BDATA64
    {
        //8*8=64
        char bit[8];
    }bdata64;
private:
    typedef struct BDATA56
    {
        char bit[7];
    }bdata56;
    typedef struct BDATA32
    {
        char bit[4];
    }bdata32;
    typedef struct BDATA48
    {
        char bit[6];
    }bdata48;
    typedef struct BDATA28
    {
        char bit[4];//28位的bit我们只能用32位的代替,多余的四位用不上.
    }bdata28;


    class DESKey {
    private:
        //计算十六轮,每一轮要用的秘钥c0,d0转化为exkey.
        int distributeKey(bdata28* c0, bdata28* d0, int times)
        {
            char table[] = { 0,1,3 };
            //赋值三个char,以及四个位
            for (int i = 0; i < 3; i++)
            {
                c0->bit[i] = realkey.bit[i];
                d0->bit[3 - i] = realkey.bit[6 - i];
            }
            char temp = realkey.bit[3];
            c0->bit[3] = temp & 0xf0;
            d0->bit[0] = temp & 0x0f;

            int step = keytable3[times];
            char buf = c0->bit[0];
            char buf2 = d0->bit[0];
            for (int i = 0; i < 3; i++)
            {
                //theshift是要补入的一位或两位
                char theshift = c0->bit[i + 1];
                theshift = theshift >> (8 - step);
                theshift = theshift & table[step];
                c0->bit[i] = c0->bit[i] << step;
                c0->bit[i] = c0->bit[i] & (~table[step]);//需要移入的位先置位0
                c0->bit[i] = c0->bit[i] | theshift;
                //d0
                theshift = d0->bit[i + 1];
                theshift = theshift >> (8 - step);
                theshift = theshift & table[step];
                d0->bit[i] = d0->bit[i] << step;
                d0->bit[i] = d0->bit[i] & (~table[step]);//置位0
                d0->bit[i] = d0->bit[i] | theshift;

            }
            buf = buf >> (4 - step);
            buf = buf & (table[step] << 4);
            c0->bit[3] = c0->bit[3] << step;
            c0->bit[3] = c0->bit[3] & (~(table[step] << 4));
            c0->bit[3] = c0->bit[3] | buf;

            buf2 = buf2 >> (4 - step);
            buf2 = buf2 & (table[step]);
            d0->bit[3] = d0->bit[3] << step;
            d0->bit[3] = d0->bit[3] & (~table[step]);
            d0->bit[3] = d0->bit[3] | buf2;
            d0->bit[0] = d0->bit[0] & 0x0f;//保持d0前四位为0的格式

            return 0;
        }
        int exKey(bdata28 c0, bdata28 d0, bdata48* exkey)
        {
            char buf;//buf用于暂存当前bit位所在的字节
            char table[] = { -128,64,32,16,8,4,2,1 };
            for (int i = 0; i < 48; i++)
            {
                int position = exkeytable[i] - 1;
                int row = position / 8;
                int offset = position % 8;
                if (row >= 3 && offset > 3)
                {
                    buf = d0.bit[row - 3];
                }
                else
                {
                    buf = c0.bit[row];
                }
                int answer = buf & table[offset];
                if (answer)
                {
                    row = i / 8;
                    offset = i % 8;
                    exkey->bit[row] = exkey->bit[row] | table[offset];
                }
                else
                {
                    row = i / 8;
                    offset = i % 8;
                    exkey->bit[row] = exkey->bit[row] & (~table[offset]);
                }
            }
            return 0;
        }
        int mergeKey(bdata28 c0, bdata28 d0)
        {
            for (int i = 0; i < 3; i++)
            {
                realkey.bit[i] = c0.bit[i];
            }
            for (int i = 4; i < 7; i++)
            {
                realkey.bit[i] = d0.bit[i - 3];
            }
            c0.bit[3] = c0.bit[3] & 0xf0;
            d0.bit[0] = d0.bit[0] & 0x0f;
            realkey.bit[3] = c0.bit[3] | d0.bit[0];
            return 0;
        }
        void keyOperate() {
            bdata28 c0, d0;
            for (int i = 0; i <= 15; i++) {
                distributeKey(&c0, &d0, i);
                exKey(c0, d0, &exkey[i]);
                mergeKey(c0, d0);
            }
        }
    public:
        void showExKey() {
            for (int i = 0; i < 16; i++) {
                printf("the %d th exkey ", i + 1);
                for (int j = 0; j < 6; j++) {

                    printf("%d ", exkey[i].bit[j]);

                }
                printf("\n");
            }
        }
        void showRawKey() {
            for (int i = 0; i < 8; i++) {
                printf("%d ", rawkey.bit[i]);
            }
            printf("\n");
        }
        void showRealKey() {
            for (int i = 0; i < 7; i++) {
                printf("%d ", realkey.bit[i]);
            }
            printf("\n");
        }
        bdata56 realkey;
        bdata64 rawkey;
        bdata48 exkey[16];
        DESKey(char* cp)
        {

            int length = strlen(cp);

            length < 8 ? true : length = 8;

            for (int i = 0; i < length; i++) {
                rawkey.bit[i] = *cp;
                cp++;
            }

            for (int i = length; i < 8; i++) {
                rawkey.bit[i] = 0;
                cp++;
            }

            char table[] = { -128,64,32,16,8,4,2,1 };
            //rawkey to realkey
            for (int i = 0; i < 56; i++)
            {
                int position = keytable1[i] - 1;
                int row = position / 8;
                int offset = position % 8;
                //我们需要获得他所在的位
                int answer = rawkey.bit[row] & table[offset];
                //answer确定所选位是否使能
                if (answer)
                {
                    row = i / 8;
                    offset = i % 8;
                    realkey.bit[row] = realkey.bit[row] | table[offset];
                }
                else
                {
                    row = i / 8;
                    offset = i % 8;
                    realkey.bit[row] = realkey.bit[row] & (~table[offset]);
                }
            }
            keyOperate();
        };
    };



    void ipExchange(bdata64* m);
    void extendRdata(bdata32, bdata48*);
    void xorEdata(bdata48*, bdata48);
    void sBox(bdata48 edata, bdata32* result);
    void pExchange(bdata32*);
    void unipExchange(bdata64*);
public:
    DESKey key;
    //返回一个指针,这个指针是bdata类型指针,指向bdata数组的第一个元素.
    DES(char* cp) :key(cp) {};
    //n是bdata64数量
    static void showBdata64InB(bdata64* p, int n);
    static void showBdata64InC(bdata64* p, int n);

    bdata64* decode(char* p);
    bdata64* decode(bdata64* p, int n);
    bdata64* encode(char* p);
    bdata64* encode(bdata64* p, int n);

};


DES::bdata64* DES::encode(char* p) {
    int length = strlen(p);
    int num = ((length - 1) / 8) + 1;
    bdata64* mingwen = new bdata64[num];
    for (int i = 0; i < length; i++) {
        mingwen[i / 8].bit[i % 8] = *(p + i);
    }
    for (int i = length; i < num * 8; i++) {
        mingwen[i / 8].bit[i % 8] = 0;
    }
    return encode(mingwen, num);
}


DES::bdata64* DES::encode(DES::bdata64* pt, int n) {
    //我们不希望破坏原来的明文,所以new内存
    bdata64* m = new bdata64[n];//密文对象数组
    for (int k = 0; k < n; k++) {
        bdata64 mt = *(pt + k);//对这个temp对象进行修改.
        ipExchange(&mt);//mt被重映射
        bdata32 rdata, ldata;
        bdata32 SOUT;
        bdata48 edata;
        for (int i = 0; i <= 15; i++) {
            for (int j = 0; j < 4; j++) {
                ldata.bit[j] = mt.bit[j];
                rdata.bit[j] = mt.bit[j + 4];
            }
            extendRdata(rdata, &edata);
            xorEdata(&edata, key.exkey[i]);
            sBox(edata, &SOUT);
            pExchange(&SOUT);
            for (int j = 0; j < 4; j++) {
                mt.bit[j + 4] = SOUT.bit[j] ^ ldata.bit[j];
                mt.bit[j] = rdata.bit[j];
            }
        }
        //after the last loop , exchange left and right.
        bdata64 temp = mt;
        for (int j = 0; j < 4; j++)
        {
            mt.bit[j + 4] = temp.bit[j];
            mt.bit[j] = temp.bit[j + 4];
        }
        unipExchange(&mt);
        m[k] = mt;
    }
    return m;
}

DES::bdata64* DES::decode(char* p) {
    int length = strlen(p);
    int num = (length - 1 / 8) + 1;
    bdata64* miwen = new bdata64[num];
    for (int i = 0; i < length; i++) {
        miwen[i / 8].bit[i % 8] = *(p + i);
    }
    for (int i = length; i < num * 8; i++) {
        miwen[i / 8].bit[i % 8] = 0;
    }
    return decode(miwen, num);
}

DES::bdata64* DES::decode(bdata64* p, int n) {
    //我们不希望破坏原来的密文,所以new内存
    bdata64* m = new bdata64[n];//明文对象数组
    for (int k = 0; k < n; k++) {
        bdata64 mt = *(p + k);//对这个temp对象进行修改.
        ipExchange(&mt);//mt被重映射
        bdata32 rdata, ldata;
        bdata32 SOUT;
        bdata48 edata;
        for (int i = 0; i <= 15; i++) {
            for (int j = 0; j < 4; j++) {
                ldata.bit[j] = mt.bit[j];
                rdata.bit[j] = mt.bit[j + 4];
            }
            extendRdata(rdata, &edata);
            xorEdata(&edata, key.exkey[15 - i]);//这里是关键
            sBox(edata, &SOUT);
            pExchange(&SOUT);
            for (int j = 0; j < 4; j++) {
                mt.bit[j + 4] = SOUT.bit[j] ^ ldata.bit[j];
                mt.bit[j] = rdata.bit[j];
            }
        }
        //after the last loop , exchange left and right.
        bdata64 temp = mt;
        for (int j = 0; j < 4; j++)
        {
            mt.bit[j + 4] = temp.bit[j];
            mt.bit[j] = temp.bit[j + 4];
        }
        unipExchange(&mt);
        m[k] = mt;
    }
    return m;

}

void DES::ipExchange(bdata64* mp) {
    bdata64 oldmingwen = *mp;
    char table[] = { -128,64,32,16,8,4,2,1 };
    for (int i = 0; i < 64; i++)
    {
        int position = iptable[i] - 1;
        int row = position / 8;
        int offset = position % 8;
        int answer = oldmingwen.bit[row] & table[offset];
        if (answer)//该位置1
        {
            row = i / 8;
            offset = i % 8;
            mp->bit[row] = mp->bit[row] | table[offset];
        }
        else//该位置0
        {
            row = i / 8;
            offset = i % 8;
            mp->bit[row] = mp->bit[row] & (~table[offset]);
        }
    }
    return;
}
void DES::extendRdata(bdata32 rdata, bdata48* edata) {
    char table[] = { -128,64,32,16,8,4,2,1 };
    for (int i = 0; i < 48; i++)
    {
        int position = extendtable[i] - 1;
        int row = position / 8;
        int offset = position % 8;
        int answer = rdata.bit[row] & table[offset];
        if (answer)
        {
            row = i / 8;
            offset = i % 8;
            edata->bit[row] = edata->bit[row] | table[offset];
        }
        else
        {
            row = i / 8;
            offset = i % 8;
            edata->bit[row] = edata->bit[row] & (~table[offset]);
        }

    }
    return;
}
void DES::xorEdata(bdata48* edata, bdata48 exkey)
{
    for (int i = 0; i <= 6; i++)
    {
        edata->bit[i] = edata->bit[i] ^ exkey.bit[i];
    }
    return;
}
void DES::unipExchange(bdata64* mingwen) {
    bdata64 oldmingwen = *mingwen;
    char table[] = { -128,64,32,16,8,4,2,1 };
    for (int i = 0; i < 64; i++)
    {
        int position = iviptable[i] - 1;
        int row = position / 8;
        int offset = position % 8;
        int answer = oldmingwen.bit[row] & table[offset];
        if (answer)//该位置1
        {
            row = i / 8;
            offset = i % 8;
            mingwen->bit[row] = mingwen->bit[row] | table[offset];
        }
        else//该位置0
        {
            row = i / 8;
            offset = i % 8;
            mingwen->bit[row] = mingwen->bit[row] & (~table[offset]);
        }
    }
    return;
}
void DES::sBox(bdata48 edata, bdata32* result)
{
    char S[8] = { 0 };
    char table[] = { -128,64,32,16,8,4,2,1 };
    //取出第一和第六个bit位,
    char temp = edata.bit[0] & table[0];
    char temp2 = edata.bit[0] & table[5];
    temp = temp >> 6;
    temp = temp & table[6];//只保留有用位
    temp2 = temp2 >> 2;
    char temp3 = temp | temp2;
    temp = edata.bit[0] & 120;//其实只要最高位0即可,即取出中间四位
    temp = temp >> 3;
    S[0] = stable[0][temp3][temp];

    temp = edata.bit[0] & table[6];
    temp2 = edata.bit[1] & table[3];
    temp2 = temp2 >> 4;
    temp3 = temp | temp2;
    temp = edata.bit[0] & table[7];
    temp2 = edata.bit[1] & -32;
    temp2 = temp2 >> 5;
    temp2 = temp2 & 7;
    temp = temp << 3;
    temp = temp | temp2;
    S[1] = stable[1][temp3][temp];

    temp = edata.bit[1] & table[4];
    temp2 = edata.bit[2] & table[1];
    temp = temp >> 2;
    temp2 = temp2 >> 6;
    temp3 = temp | temp2;
    temp = edata.bit[1] & 7;
    temp = temp << 1;
    temp2 = edata.bit[2] & 128;
    temp2 = temp2 >> 7;
    temp2 = temp2 & table[7];//消除移位补位影响
    temp = temp | temp2;
    S[2] = stable[2][temp3][temp];

    temp = edata.bit[2] & table[2];
    temp2 = edata.bit[2] & table[7];
    temp = temp >> 4;
    temp3 = temp | temp2;
    temp = edata.bit[2] & 30;
    temp = temp >> 1;
    S[3] = stable[3][temp3][temp];

    //////////////////////////////////////////

    temp = edata.bit[3] & table[0];
    temp2 = edata.bit[3] & table[5];
    temp = temp >> 6;
    temp = temp & table[6];//消解移位头部副作用
    temp2 = temp2 >> 2;
    temp3 = temp | temp2;
    temp = edata.bit[3] & 120;//其实只要最高位0即可
    temp = temp >> 3;
    S[4] = stable[4][temp3][temp];

    temp = edata.bit[3] & table[6];
    temp2 = edata.bit[4] & table[3];
    temp2 = temp2 >> 4;
    temp3 = temp | temp2;
    temp = edata.bit[3] & table[7];
    temp2 = edata.bit[4] & -32;
    temp2 = temp2 >> 5;
    temp2 = temp2 & 7;
    temp = temp << 3;
    temp = temp | temp2;
    S[5] = stable[5][temp3][temp];

    temp = edata.bit[4] & table[4];
    temp2 = edata.bit[5] & table[1];
    temp = temp >> 2;
    temp2 = temp2 >> 6;
    temp3 = temp | temp2;
    temp = edata.bit[4] & 7;
    temp = temp << 1;
    temp2 = temp2 >> 7;
    temp2 = temp2 & table[7];
    temp = temp | temp2;
    S[6] = stable[6][temp3][temp];


    temp = edata.bit[5] & table[2];
    temp2 = edata.bit[5] & table[7];
    temp = temp >> 4;
    temp3 = temp | temp2;
    temp = edata.bit[5] & 30;
    temp = temp >> 1;
    S[7] = stable[7][temp3][temp];

    for (int i = 0; i <= 3; i++)
    {
        S[i * 2] = S[i * 2] << 4;
        result->bit[i] = S[i * 2] | S[i * 2 + 1];
    }

}

void DES::pExchange(bdata32 * SOUT)
{
    bdata32 backup = *SOUT;
    char table[] = { -128,64,32,16,8,4,2,1 };
    for (int i = 0; i < 32; i++)
    {
        int position = ptable[i] - 1;
        int row = position / 8;
        int offset = position % 8;
        int answer = backup.bit[row] & table[offset];
        if (answer)//该位置1
        {
            row = i / 8;
            offset = i % 8;
            SOUT->bit[row] = backup.bit[row] | table[offset];
        }
        else//该位置0
        {
            row = i / 8;
            offset = i % 8;
            SOUT->bit[row] = backup.bit[row] & (~table[offset]);
        }
    }
}


void DES::showBdata64InB(bdata64* p, int n) {

    char table[] = { -128,64,32,16,8,4,2,1 };
    for (int k = 0; k < n; k++) {
        bdata64 mingwen = *(p + k);
        printf("------\n");
        for (int i = 0; i < 64; i++)
        {
            char buf = mingwen.bit[i / 8] & table[i % 8];
            printf("%d ", (buf > 0) ? 1 : 0);
            if (i % 8 == 7)
                printf("\n");
        }
        printf("\n");
    }

    return;
}
void DES::showBdata64InC(bdata64* p, int n) {
    for (int k = 0; k < n; k++) {
        bdata64 mingwen = *(p + k);
        printf("------\n");
        for (int i = 0; i < 8; i++) {
            printf("%c ", mingwen.bit[i]);
        }
        printf("\n");
    }
}



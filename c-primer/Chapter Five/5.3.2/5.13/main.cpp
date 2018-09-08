/*5.13：下面显示的每个程序都含有一个常见的编程错误，指出错误在哪里，然后修改它们。
（a)
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case'a' : aCnt++;
        case'e' : eCnt++;
        default: iouCnt++;
    }
}
(b)
    unsigned index = some_value();
    switch(index){
        case 1:
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
        ivec [ ix ] = index;
    }
(c).
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit)
    {
        case 1,3,5,7,9:
            oddCnt++;
            break;
        case 2,4,6,8,10:
            evenCnt++;
            break;
    }

(d)
    unsigned ival = 512, jval = 1024, kval = 4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt)
    {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = javl * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
    return 0;
 */


#include <iostream>

int main() {
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case'a' : aCnt++;
            break;  //缺少break；
        case'e' : eCnt++;
            break;  //缺少break；
        default: iouCnt++;
            break;  //缺少break；
    }


    unsigned index = some_value();
    switch(index){
        case 1:
            //int ix = get_value();   //控制流绕过一个显式初始化的变量
            //ivec[ ix ] = index;     //控制流绕过一个显式初始化的变量
            break;
        default:
            ix = ivec.size()-1;
        ivec [ ix ] = index;
    }


    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit)
    {
        case 1:case 3:case 5:case 7:case 9:     //应该为冒号，不为逗号.写法也错了
            oddCnt++;
            break;
        case 2:case 4:case 6:case 8:case 10:    //应该为冒号，不为逗号.写法也错了
            evenCnt++;
            break;
    }


    unsigned ival = 512, jval = 1024, kval = 4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt)
    {
        case ival:                  //case后要跟整数常量
            bufsize = ival * sizeof(int);
            break;
        case jval:                  //case后要跟整数常量
            bufsize = javl * sizeof(int);
            break;
        case kval:                  //case后要跟整数常量
            bufsize = kval * sizeof(int);
            break;
    }
    return 0;
}
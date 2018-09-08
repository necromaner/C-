/*2.6：下面两组定义是否有区别，如果有，请叙述之：

int month = 9,day = 7;

int month = 09,day =07;
 */

#include <iostream>

int main() {
    int month1 = 9,day1 = 7; //十进制
    int month2 = 09,day2 =07;//0开头，所以8进制
    return 0;
}
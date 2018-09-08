/*4.30 根据4.12节中的表，在下述表达式的适当位置加上括号，使得加上括号之后的表达式的含义与原来的含义相同。
(a) sizeof x + y
(b) sizeof p->mem[i]
(c) sizeof a < b
(d) sizeof f()
*/


#include <iostream>

int main() {
    sizeof (x + y);
    sizeof (p->mem[i]);
    sizeof (a < b);
    sizeof (f());


    return 0;
}
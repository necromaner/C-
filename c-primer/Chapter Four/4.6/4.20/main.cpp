/*练习4.20：假设iter的类型是vector<string>::iterator,说明下面的表达式是否合法。如果合法，表达式的含义是什么？如果不合法，错在何处？
(a) *iter++;
(b) (*iter)++;
(c) *iter.empty()
(d) iter->empty()
(e) ++*iter;
(f) iter++->empty();
 */

/*
(a) *iter++;//等价于(iter++)
(b) (*iter)++;//错误，
(c) *iter.empty()//等价于*(iter.empty())
(d) iter->empty()//等价于(*iter).empty()
(e) ++*iter;//等价于++(*iter);
(f) iter++->empty();//等价于((iter++)).empty()
 */
#include <iostream>


int main() {
    return 0;
}
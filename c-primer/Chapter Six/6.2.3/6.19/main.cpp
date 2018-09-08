/*6.19：假定有如下声明，判断哪个调用合法，哪个调用不合法。对于不合法的函数调用，说明原因。

double calc(double) ;
int count(const string&, char);
int sum(vector<int> :: iterator , vector<int> :: iterator, int);
vector<int> vec(10);
(a) calc(23.4, 55.1);
(b) count("abcda", 'a');
(c)  calc(66);
(d)sum(vec.begin(), vec.end(),3.8);
 */

#include <iostream>
#include<vector>

using namespace std;

double calc(double) ;
int count(const string&, char);
int sum(vector<int> :: iterator , vector<int> :: iterator, int);//iterator迭代器
vector<int> vec(10);

int main() {


    calc(23.4, 55.1);//不合法，形参数量不匹配，只能有一个

    count("abcda", 'a');//合法,

    calc(66);//合法，形参数量匹配

    sum(vec.begin(), vec.end(), 3.8);//不合法，最后一个不是整数，非int类型
    return 0;
}
#include<vector>
#include<string>
#include <iostream>

using namespace std;
/*
 最长公共前缀

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"

示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

说明:

所有输入只包含小写字母 a-z 。

 */
/*
vector 是向量类型，它可以容纳许多类型的数据，如若干个整数，所以称其为容器。vector 是C++ STL的一个重要成员，使用它时需要包含头文件：
#include<vector>;
vector<int> a ;                                //声明一个int型向量a
vector<int> a(10) ;                            //声明一个初始大小为10的向量
vector<int> a(10, 1) ;                         //声明一个初始大小为10且初始值都为1的向量
vector<int> b(a) ;                             //声明并用向量a初始化向量b
vector<int> b(a.begin(), a.begin()+3) ;        //将a向量中从第0个到第2个(共3个)作为向量b的初始值
int b[7]={1,2,3,4,5,9,8};
        vector<int> a(b,b+7); //从数组中获得初值
        
vector对象的几个重要操作，举例说明如下：
（1）a.assign(b.begin(), b.begin()+3); //b为向量，将b的0~2个元素构成的向量赋给a
（2）a.assign(4,2); //是a只含4个元素，且每个元素为2
（3）a.back(); //返回a的最后一个元素
（4）a.front(); //返回a的第一个元素
（5）a[i]; //返回a的第i个元素，当且仅当a[i]存在2013-12-07
（6）a.clear(); //清空a中的元素
（7）a.empty(); //判断a是否为空，空则返回ture,不空则返回false
（8）a.pop_back(); //删除a向量的最后一个元素
（9）a.erase(a.begin()+1,a.begin()+3); //删除a中第1个（从第0个算起）到第2个元素，也就是说删除的元素从a.begin()+1算起（包括它）一直到a.begin()+         3（不包括它）
（10）a.push_back(5); //在a的最后一个向量后插入一个元素，其值为5
（11）a.insert(a.begin()+1,5); //在a的第1个元素（从第0个算起）的位置插入数值5，如a为1,2,3,4，插入元素后为1,5,2,3,4
（12）a.insert(a.begin()+1,3,5); //在a的第1个元素（从第0个算起）的位置插入3个数，其值都为5
（13）a.insert(a.begin()+1,b+3,b+6); //b为数组，在a的第1个元素（从第0个算起）的位置插入b的第3个元素到第5个元素（不包括b+6），如b为1,2,3,4,5,9,8         ，插入元素后为1,4,5,9,2,3,4,5,9,8
（14）a.size(); //返回a中元素的个数；
（15）a.capacity(); //返回a在内存中总共可以容纳的元素个数
（16）a.resize(10); //将a的现有元素个数调至10个，多则删，少则补，其值随机
（17）a.resize(10,2); //将a的现有元素个数调至10个，多则删，少则补，其值为2
（18）a.reserve(100); //将a的容量（capacity）扩充至100，也就是说现在测试a.capacity();的时候返回值是100.这种操作只有在需要给a添加大量数据的时候才         显得有意义，因为这将避免内存多次容量扩充操作（当a的容量不足时电脑会自动扩容，当然这必然降低性能）
（19）a.swap(b); //b为向量，将a中的元素和b中的元素进行整体性交换
（20）a==b; //b为向量，向量的比较操作还有!=,>=,<=,>,<
几种重要的算法，使用时需要包含头文件：
#include<algorithm>
（1）sort(a.begin(),a.end()); //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素进行从小到大排列
（2）reverse(a.begin(),a.end()); //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素倒置，但不排列，如a中元素为1,3,2,4,倒置后为4,2,3,1
（3）copy(a.begin(),a.end(),b.begin()+1); //把a中的从a.begin()（包括它）到a.end()（不包括它）的元素复制到b中，从b.begin()+1的位置（包括它）开        始复制，覆盖掉原有元素
（4）find(a.begin(),a.end(),10); //在a中的从a.begin()（包括它）到a.end()（不包括它）的元素中查找10，若存在返回其在向量中的位置
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer;
        if (strs.size() == 0) return answer;
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[0][i] != strs[j][i])
                    return answer;
            }
            answer.push_back(strs[0][i]);
        }
        return answer;
    }
};
int main() {
    Solution solution;
    vector<string> strs={"flower","flow","flight"};
    for (int i = 0; i < strs.size(); ++i) {
        if(i==0)
            printf("输入:[");
        printf("%s",strs[i].c_str());
        if(i<strs.size()-1)
            printf(",");
        if(i==strs.size()-1)
            printf("]\n");
    }
    
    printf("输出：%s\n",solution.longestCommonPrefix(strs).c_str());
    return 0;
}
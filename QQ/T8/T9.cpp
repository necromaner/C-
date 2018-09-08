#include<vector>
#include<string>
#include <iostream>
using namespace std;
/*
  有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。
 */

void outPut_vector_int(vector<int> strs){//输出vector<int>
    for (int i = 0; i < strs.size(); ++i) {
        if(i==0)
            printf("[");
        printf("%d",strs[i]);
        if(i<strs.size()-1)
            printf(",");
        if(i==strs.size()-1)
            printf("]\n");
    }
}
void outPut_vector_vector_int(vector<vector<int>> strs){//输出vector<vector<int>>
    for (int j = 0; j < strs.size(); ++j) {
        for (int i = 0; i < strs[j].size(); ++i) {
            if (i == 0)
                printf("[");
            printf("%d", strs[j][i]);
            if (i < strs[j].size() - 1)
                printf(",");
            else if (i == strs[j].size() - 1)
                printf("]\n");
        }
    }
}
void outPut_int(int strs){//输出vector<vector<int>>
    printf("%d\n",strs);
}
void outPut_bool(bool s) {//输出vector<vector<int>>
    if (s)
        printf("true\n");
    else
        printf("false\n");
    
}






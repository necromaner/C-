//
// Created by 温亚奇 on 2018/9/8.
//

#include "Output.h"
//
// Created by 温亚奇 on 2018/9/8.
//

void outPut(vector<int> strs){
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
void outPut(vector<vector<int>> strs){
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
void outPut(int strs){
    printf("%d\n",strs);
}
void outPut(bool s) {
    if (s)
        printf("true\n");
    else
        printf("false\n");
}
void outPut(string s) {
    printf("%s\n",s.c_str());
}
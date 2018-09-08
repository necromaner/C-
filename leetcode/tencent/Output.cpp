#include "Output.h"

void outPut(vector<int> strs){
    int max_length=0;
    for (int k = 0; k < strs.size(); ++k) {
        int max = to_string(strs[k]).size();
        if (max_length < max) {
            max_length = max;
        }
    }
    for (int i = 0; i < strs.size(); ++i) {
        if(i==0)
            printf("[");
        int max=to_string(strs[i]).size();
        for (int k = 0; k < max_length-max; ++k) {
            printf(" ");
        }
        printf("%d",strs[i]);
        if(i<strs.size()-1)
            printf(",");
        if(i==strs.size()-1)
            printf("]\n");
    }
}
void outPut(vector<string> strs){
    int max_length=0;
    for (int k = 0; k < strs.size(); ++k) {
            int max=strs[k].size();
            if(max_length<max){
                max_length=max;
            }
    }
    for (int i = 0; i < strs.size(); ++i) {
        if(i==0)
            printf("[");
        int max=strs[i].size();
        for (int k = 0; k < max_length-max; ++k) {
            printf(" ");
        }
        printf("%s",strs[i].c_str());
        if(i<strs.size()-1)
            printf(",");
        if(i==strs.size()-1)
            printf("]\n");
    }
}
void outPut(vector<vector<int>> strs){
    int max_length=0;
    for (int k = 0; k < strs.size(); ++k) {
        for (int i = 0; i < strs[k].size(); ++i) {
            int max=to_string(strs[k][i]).size();
            if(max_length<max){
                max_length=max;
            }
        }
    }
    for (int j = 0; j < strs.size(); ++j) {
        for (int i = 0; i < strs[j].size(); ++i) {
            if (i == 0)
                printf("[");
            int max=to_string(strs[j][i]).size();
            for (int k = 0; k < max_length-max; ++k) {
                printf(" ");
            }
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
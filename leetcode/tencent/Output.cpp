#include "Output.h"
//string output,
//printf("%s",output.c_str());
//int output,
//output?printf("输出："):printf("输入：");
void outPut(){
    printf("没有输出内容！\n");
}


void outPut(vector<int> strs){
    int max_length=0;
    for (int k = 0; k < strs.size(); ++k) {
        int max = to_string(strs[k]).size();
        if (max_length < max) {
            max_length = max;
        }
    }
    printf("[");
    for (int i = 0; i < strs.size(); ++i) {
        int max=to_string(strs[i]).size();
        for (int k = 0; k < max_length-max; ++k) {
            printf(" ");
        }
        printf("%d",strs[i]);
        if(i<strs.size()-1)
            printf(",");
    }
    printf("]\n");
}
void outPut(string output,vector<int> strs){
    printf("%s:",output.c_str());
    int max_length=0;
    for (int k = 0; k < strs.size(); ++k) {
        int max = to_string(strs[k]).size();
        if (max_length < max) {
            max_length = max;
        }
    }
    printf("[");
    for (int i = 0; i < strs.size(); ++i) {
        int max=to_string(strs[i]).size();
        for (int k = 0; k < max_length-max; ++k) {
            printf(" ");
        }
        printf("%d",strs[i]);
        if(i<strs.size()-1)
            printf(",");
    }
    printf("]\n");
}
void outPut(int output,vector<int> strs){
    output?printf("输出:"):printf("输入:");
    int max_length=0;
    for (int k = 0; k < strs.size(); ++k) {
        int max = to_string(strs[k]).size();
        if (max_length < max) {
            max_length = max;
        }
    }
    printf("[");
    for (int i = 0; i < strs.size(); ++i) {
        int max=to_string(strs[i]).size();
        for (int k = 0; k < max_length-max; ++k) {
            printf(" ");
        }
        printf("%d",strs[i]);
        if(i<strs.size()-1)
            printf(",");
    }
    printf("]\n");
}

void outPut(vector<string> strs){
    int max_length=0;
    for (int k = 0; k < strs.size(); ++k) {
        int max=strs[k].size();
        if(max_length<max){
            max_length=max;
        }
    }
    printf("[");
    for (int i = 0; i < strs.size(); ++i) {
        int max=strs[i].size();
        for (int k = 0; k < max_length-max; ++k) {
            printf(" ");
        }
        printf("%s",strs[i].c_str());
        if(i<strs.size()-1)
            printf(",");
    }
    printf("]\n");
}
void outPut(string output, vector<string> strs){
    printf("%s:",output.c_str());
    int max_length=0;
    for (int k = 0; k < strs.size(); ++k) {
        int max=strs[k].size();
        if(max_length<max){
            max_length=max;
        }
    }
    printf("[");
    for (int i = 0; i < strs.size(); ++i) {
        int max=strs[i].size();
        for (int k = 0; k < max_length-max; ++k) {
            printf(" ");
        }
        printf("%s",strs[i].c_str());
        if(i<strs.size()-1)
            printf(",");
    }
    printf("]\n");
}
void outPut(int output,vector<string> strs){
    output?printf("输出:"):printf("输入:");
    int max_length=0;
    for (int k = 0; k < strs.size(); ++k) {
        int max=strs[k].size();
        if(max_length<max){
            max_length=max;
        }
    }
    printf("[");
    for (int i = 0; i < strs.size(); ++i) {
        int max=strs[i].size();
        for (int k = 0; k < max_length-max; ++k) {
            printf(" ");
        }
        printf("%s",strs[i].c_str());
        if(i<strs.size()-1)
            printf(",");
    }
    printf("]\n");
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
            int max = to_string(strs[j][i]).size();
            for (int k = 0; k < max_length - max; ++k) {
                printf(" ");
            }
            printf("%d", strs[j][i]);
            if (i < strs[j].size() - 1)
                printf(",");
            else if (i == strs[j].size() - 1)
                printf("]");
        }
        if (j < strs.size() - 1)
            printf("\n");
    }
    printf("\n");
}
void outPut(string output, vector<vector<int>> strs){
    printf("%s:\n",output.c_str());
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
            if (i == 0){
                for (int k = 0; k < output.size()+1; ++k) {
                    printf(" ");
                }
                printf("[");
            }
            int max=to_string(strs[j][i]).size();
            for (int k = 0; k < max_length-max; ++k) {
                printf(" ");
            }
            printf("%d", strs[j][i]);
            if (i < strs[j].size() - 1)
                printf(",");
            else if (i == strs[j].size() - 1)
                printf("]");
        }
        if (j < strs.size() - 1)
            printf("\n");
    }
    printf("\n");
}
void outPut(int output,vector<vector<int>> strs){
    output?printf("输出:\n"):printf("输入:\n");
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
                printf("     [");
            int max=to_string(strs[j][i]).size();
            for (int k = 0; k < max_length-max; ++k) {
                printf(" ");
            }
            printf("%d", strs[j][i]);
            if (i < strs[j].size() - 1)
                printf(",");
            else if (i == strs[j].size() - 1)
                printf("]");
        }
        if (j < strs.size() - 1)
            printf("\n");
    }
    printf("\n");
}

void outPut(int strs){
    printf("%d\n",strs);
}
void outPut(string output,int strs){
    printf("%s:",output.c_str());
    printf("%d\n",strs);
}
void outPut(int output,int strs){
    output?printf("输出:"):printf("输入:");
    printf("%d\n",strs);
}

void outPut(bool s) {
    if (s)
        printf("true\n");
    else
        printf("false\n");
}
void outPut(string output, bool s) {
    printf("%s:",output.c_str());
    if (s)
        printf("true\n");
    else
        printf("false\n");
}
void outPut(int output,bool s) {
    output?printf("输出:"):printf("输入:");
    if (s)
        printf("true\n");
    else
        printf("false\n");
}

void outPut(string s) {
    printf("%s\n",s.c_str());
}
void outPut(string output, string s) {
    printf("%s:",output.c_str());
    printf("%s\n",s.c_str());
}
void outPut(int output,string s) {
    output?printf("输出:"):printf("输入:");
    printf("%s\n",s.c_str());
}

void outPut(double s) {
    printf("%f\n",s);
}
void outPut(string output, double s) {
    printf("%s:",output.c_str());
    printf("%f\n",s);
}
void outPut(int output,double s) {
    output?printf("输出:"):printf("输入:");
    printf("%f\n",s);
}

void outPut(ListNode *s) {
    while(s){
        printf("%d->",*s);
        s=s->next;
    }
    printf("NULL\n");
}
void outPut(string output, ListNode *s) {
    printf("%s:",output.c_str());
    while(s){
        printf("%d->",*s);
        s=s->next;
    }
    printf("NULL\n");
}
void outPut(int output,ListNode *s) {
    output?printf("输出:"):printf("输入:");
    while(s){
        printf("%d->",*s);
        s=s->next;
    }
    printf("NULL\n");
}


ListNode* inPut(){
    return NULL;
}
ListNode* inPut(vector<int> s){
    if(s.size()<1)
        return NULL;
    ListNode *p=new ListNode(s[0]);
    ListNode *q=p;
    for (int i = 1; i < s.size(); ++i) {
        q->next=new ListNode(s[i]);
        q=q->next;
    }
    return  p;
}





void problem(string filepath,string s) {
    if (!filepath.empty())
    {
        int locpoint = filepath.find_last_of('.');
        int locfilename = filepath.find_last_of('/');
        printf("%s.",filepath.substr(locfilename + 1, locpoint - locfilename-1).c_str());
    }
    if(s.size()>0)
        printf("%s\n\n",s.c_str());
    else
        printf("还没有开始编写\n\n");
}
#include "Output.h"
//string output,
//printf("%s",output.c_str());
//int output,
//output?printf("输出："):printf("输入：");
void outPut(){
    printf("没有输出内容！\n");
}

//------------------------------------vector一维----------------------------------------//
void outPut(vector<int> s){
    int max_length=0;
    for (int k = 0; k < s.size(); ++k) {
        int max = to_string(s[k]).size();
        if (max_length < max) {
            max_length = max;
        }
    }
    printf("[");
    for (int i = 0; i < s.size(); ++i) {
        int max=to_string(s[i]).size();
        for (int k = 0; k < max_length-max; ++k) {
            printf(" ");
        }
        printf("%d",s[i]);
        if(i<s.size()-1)
            printf(",");
    }
    printf("]\n");
}

void outPut(vector<string> s){
    int max_length=0;
    for (int k = 0; k < s.size(); ++k) {
        int max=s[k].size();
        if(max_length<max){
            max_length=max;
        }
    }
    printf("[");
    for (int i = 0; i < s.size(); ++i) {
        int max=s[i].size();
        for (int k = 0; k < max_length-max; ++k) {
            printf(" ");
        }
        printf("%s",s[i].c_str());
        if(i<s.size()-1)
            printf(",");
    }
    printf("]\n");
}

//------------------------------------vector二维----------------------------------------//
void outPut(vector<vector<int>> s){
    int max_length=0;
    for (int k = 0; k < s.size(); ++k) {
        for (int i = 0; i < s[k].size(); ++i) {
            int max=to_string(s[k][i]).size();
            if(max_length<max){
                max_length=max;
            }
        }
    }
    for (int j = 0; j < s.size(); ++j) {
        for (int i = 0; i < s[j].size(); ++i) {
            if (i == 0)
                printf("[");
            int max = to_string(s[j][i]).size();
            for (int k = 0; k < max_length - max; ++k) {
                printf(" ");
            }
            printf("%d", s[j][i]);
            if (i < s[j].size() - 1)
                printf(",");
            else if (i == s[j].size() - 1)
                printf("]");
        }
        if (j < s.size() - 1)
            printf("\n");
    }
    printf("\n");
}

void outPut(vector<ListNode*>& s){
    printf("[\n");
    for (int i = 0; i < s.size(); ++i) {
        printf("   ");
        outPut(s[i]);
    }
    printf("]\n");
}
//------------------------------------other----------------------------------------//
void outPut(int s){
    printf("%d\n",s);
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

void outPut(double s) {
    printf("%f\n",s);
}

void outPut(ListNode *s) {
    while(s){
        printf("%d->",s->val);
        s=s->next;
    }
    printf("NULL\n");
}
//---------------------------------------------------------------------------------//
void outPut1(string output){
    printf("%s:",output.c_str());
}
void outPut1(int output){
    output?printf("输出:"):printf("输入:");
}

void outPut(string output,vector<int> s){outPut1(output);outPut(s);}
void outPut(int output,vector<int> s){outPut1(output);outPut(s);}

void outPut(string output, vector<string> s){outPut1(output);outPut(s);}
void outPut(int output,vector<string> s){outPut1(output);outPut(s);}

void outPut(string output,vector<ListNode*>& s){outPut1(output);printf("\n");outPut(s);}
void outPut(int output,vector<ListNode*>& s){outPut1(output);printf("\n");outPut(s);}

void outPut(string output, vector<vector<int>> s){outPut1(output);printf("\n");outPut(s);}
void outPut(int output,vector<vector<int>> s){outPut1(output);printf("\n");outPut(s);}

void outPut(string output,int s){outPut1(output);outPut(s);}
void outPut(int output,int s){outPut1(output);outPut(s);}

void outPut(string output, bool s) {outPut1(output);outPut(s);}
void outPut(int output,bool s) {outPut1(output);outPut(s);}

void outPut(string output, string s) {outPut1(output);outPut(s);}
void outPut(int output,string s) {outPut1(output);outPut(s);}

void outPut(string output, double s) {outPut1(output);outPut(s);}
void outPut(int output,double s) {outPut1(output);outPut(s);}

void outPut(string output, ListNode *s) {outPut1(output);outPut(s);}
void outPut(int output,ListNode *s) {outPut1(output);outPut(s);}





ListNode* inPut(){
    return NULL;
}
ListNode* inPut(vector<int> s) {
    if (s.size() < 1)
        return NULL;
    ListNode *p = new ListNode(s[0]);
    ListNode *q = p;
    for (int i = 1; i < s.size(); ++i) {
        q->next = new ListNode(s[i]);
        q = q->next;
    }
    return p;
}
vector<ListNode*> inPut(vector<vector<int>> s) {
    if (s.size() < 1)
        return {NULL};
    vector<ListNode *> x;
    for (int j = 0; j < s.size(); ++j) {
        x.push_back(inPut(s[j]));
    }
    return x;
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
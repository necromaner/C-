#include "Output.h"

/*
 一.函数和答案1
 例：bool isValid(string s) ，输出bool类型；bool类型与答案1做对比
 1.存储不同类型数据
 
 
 2.判断数据是否相同
 
 二.函数和答案1，答案2
 例：int removeDuplicates(vector<int>& nums)，输出int类型，nums变化；int类型与答案1做对比，nums与答案2做对比
 */
string longestPalindrome(string s) {
    string answer=s;
    int min=0;
    int max=0;
    int s_size=s.size();
    for (int i = 0; i < s_size; ++i) {
        for (int j = s_size-1; j >i ; --j) {
            if(s[i]==s[j]){
                int k;
                bool yes=1;
                for (k = 1; k <= (j-i)/2; ++k) {
                    if(s[i+k]!=s[j-k]){
                        yes=0;
                        break;
                    }
                    
                }
                if(yes&&(j-i)>(max-min)){
                    min=i;
                    max=j;
                }
            }
        }
    }
    return s.substr(min,max-min+1);
}
typedef int TEST_TYPE;

template <typename T>
struct test_node
{
    vector<T> original;
    vector<T> sorted;
};




void testCase(string output,string answer,int& num,bool& yes){
    if(output.compare(answer)){
        printf("%d.did not pass test.\n", num);
        printf("output:\t%s\n",output.c_str());
        printf("answer:\t%s\n\n",answer.c_str());
        yes=false;
    }
    num++;
}
void testCase(int output,int answer,int& num,bool& yes){
    if(output!=answer){
        printf("%d.did not pass test.\n",num);
        printf("output:\t%d\n",output);
        printf("answer:\t%d\n\n",answer);
        yes=false;
    }
    num++;
}
void testCase(bool output,bool answer,int& num,bool& yes){
    
    if(output!=answer){
        string output1=output?"true":"fales";
        string answer1=answer?"true":"fales";
        printf("%d.did not pass test.\n",num);
        printf("output:\t%s\n",output1.c_str());
        printf("answer:\t%s\n\n",answer1.c_str());
        yes=false;
    }
    num++;
}
void testCase(vector<int> output,vector<int> answer,int& num,bool& yes){
    if(output!=answer){
        printf("%d.did not pass test.\n",num);
        yes=false;
    }
    num++;
}

//int main(){
//    string s="cbbdbbbc";
//    int num=1;
//    testCase(true, false,num);
//    testCase(1,2,num);
//    testCase(1,2,num);
//    testCase(1,2,num);
//    testCase(1,2,num);
//    return 0;
//}
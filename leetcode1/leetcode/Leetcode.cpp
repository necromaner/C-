#include "Leetcode.h"

ListNode *Solution::SetListNode(vector<int> list) {
    int size=list.size();
    if(size<=0)
        return NULL;
    ListNode *lists = new ListNode(list[0]);
    ListNode *list_now=lists;
    for(int i=1;i<size;i++){
        ListNode *list_new=new ListNode(list[i]);
        lists->next=list_new;
        lists=list_new;
    }
    return list_now;
}
vector<int> Solution::GetListNode(ListNode *list) {
    vector<int> answer;
    if(list==NULL)
        return answer;
    ListNode *lists = list;
    while (lists->next!=NULL){
        answer.push_back(lists->val);
        lists=lists->next;
    }
    if(lists!=NULL)
        answer.push_back(lists->val);
    return answer;
}
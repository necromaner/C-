#include "ListNode.h"

void outPut(ListNode *s) {
    while(s){
        printf("%d->",s->val);
        s=s->next;
    }
    printf("NULL\n");
}

void insert(ListNode *&s,int x) {
    ListNode *p = new ListNode(0);
    ListNode *q = p;
    p->next = s;
    ListNode *l = new ListNode(x);
    while (q->next) {
        if (q->next->val < x)
            q = q->next;
        else
            break;
    }
    l->next=q->next;
    q->next=l;
    
    s = p->next;
    
    p->next= NULL;
    delete p;
}


ListNode* build(vector<int> x){
    int xs=x.size();
    if(xs<1)
        return NULL;
    ListNode* l=new ListNode(x[0]);
    for (int i = 1; i <xs ; ++i) {
        insert(l,x[i]);
    }
    return l;
}
void close(ListNode *&s,int x){
    ListNode *p = new ListNode(0);
    ListNode *q = p;
    p->next = s;
    while (q->next){
        if(q->next->val==x){
            ListNode *l=q->next->next;
            q->next->next=NULL;
            delete q->next;
            q->next=l;
            break;
        }
        q=q->next;
    }
    s = p->next;
    p->next= NULL;
    delete p;
}
void closeAll1(ListNode *&s){
    if(s->next){
        closeAll(s->next);
    }
    s->next= NULL;
    delete s;
}
void closeAll(ListNode *&s){
    closeAll1(s);
    s->next=NULL;
}
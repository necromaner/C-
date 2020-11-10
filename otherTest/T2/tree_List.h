#ifndef T2_TREE_LIST_H
#define T2_TREE_LIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define LIST_POISON1  ((void *) 0x00100100)
#define LIST_POISON2  ((void *) 0x00200200)
struct list_tree{//next：下一个链表的地址 prev：上一个链表的地址
    int num;
    struct list_tree *left,*right,*prev;
};
//初始化
#define LIST_HEAD_INIT(name) {0, &(name), &(name) }
#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)
static inline void INIT_LIST_HEAD(struct list_tree *list) {
    list->num = 0;
    list->left = LIST_POISON1;
    list->right = LIST_POISON1;
    list->prev = LIST_POISON2;
}

static inline void __list_add(struct list_tree *new, struct list_tree *prev, bool isLeft) {
    if (isLeft) {
        prev->left = new;
    } else {
        prev->right = new;
    }
    new->prev = prev;
}
static inline void list_add(struct list_tree *new, struct list_tree *head) {
    while (true){
        if(head->num<new->num){
            if(head->left!=LIST_POISON1){
                head=head->left;
            }else{
                __list_add(new,head,true);
                return;
            }
        }else{
            if(head->right!=LIST_POISON1){
                head=head->right;
            }else{
                __list_add(new,head,false);
                return;
            }
        }
    }
}
//static inline void __list_del(struct list_tree * prev, struct list_tree * next){
//    next->prev = prev;
//    prev->next = next;
//}
//static inline void list_del(struct list_tree *entry){
//    __list_del(entry->prev, entry->next);
//    entry->next = LIST_POISON1;
//    entry->prev = LIST_POISON2;
//}

#define list_entry(ptr, type, member) \
((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

#define list_for_each(pos, head) \
    	for (pos = (head)->next; prefetch(pos->next), pos != (head); \
            	pos = pos->next)

#define list_for_each_prev(pos, head) \
for (pos = (head)->prev; pos != (head); \
pos = pos->prev)

#define list_for_each_entry_reverse(pos, head, member)			\
    	for (pos = list_entry((head)->prev, typeof(*pos), member);	\
    	     &pos->member != (head); 	\
    	     pos = list_entry(pos->member.prev, typeof(*pos), member))

    	    //pos 结构体 head 二叉树 member pos中二叉树的结构体
#define list_for_each_entry(pos, head, member)                \
for (pos = list_entry((head)->right, typeof(*pos), member);&pos->member != LIST_POISON1;pos = list_entry(pos->member.right, typeof(*pos), member))   \

#define list_for_each_entry_reverse(pos, head, member)			\
	for (pos = list_entry((head)->prev, typeof(*pos), member);	\
	     &pos->member != LIST_POISON2; 	\
	     pos = list_entry(pos->member.prev, typeof(*pos), member))
#endif //T2_TREE_LIST_H

//#ifndef _LINUX_LIST_H
//#define _LINUX_LIST_H
//
//#define LIST_POISON1  ((void *) 0x00100100)
//#define LIST_POISON2  ((void *) 0x00200200)
//struct list_tree{//next：下一个链表的地址 prev：上一个链表的地址
//    struct list_tree *next,*prev;
//};
//
//#define LIST_HEAD_INIT(name) { &(name), &(name) }
//#define LIST_HEAD(name) \
//	struct list_tree name = LIST_HEAD_INIT(name)
//static inline void INIT_LIST_HEAD(struct list_tree *list)
//{
//    list->next = list;
//    list->prev = list;
//}
//static inline void __list_add(struct list_tree *new,
//                              struct list_tree *prev,
//                              struct list_tree *next) {
//    next->prev = new;
//    new->next = next;
//    new->prev = prev;
//    prev->next = new;
//}
//static inline void list_add(struct list_tree *new, struct list_tree *head)    //在结点之后插入新结点
//{
//    __list_add(new, head, head->next);    //__list_add（）这个函数，等等就讲
//}
//static inline void list_add_tail(struct list_tree *new, struct list_tree *head) {
//    __list_add(new, head->prev, head);
//}
//static inline void __list_del(struct list_tree * prev, struct list_tree * next)
//{
//    next->prev = prev;
//    prev->next = next;
//}
//static inline void list_del(struct list_tree *entry)
//{
//    __list_del(entry->prev, entry->next);
//    entry->next = LIST_POISON1;
//    entry->prev = LIST_POISON2;
//}
//
//#define list_entry(ptr, type, member) \
//((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))
//
//#define list_for_each(pos, head) \
//    	for (pos = (head)->next; prefetch(pos->next), pos != (head); \
//            	pos = pos->next)
//
//#define list_for_each_prev(pos, head) \
//for (pos = (head)->prev; pos != (head); \
//pos = pos->prev)
//
//#define list_for_each_entry_reverse(pos, head, member)			\
//    	for (pos = list_entry((head)->prev, typeof(*pos), member);	\
//    	     &pos->member != (head); 	\
//    	     pos = list_entry(pos->member.prev, typeof(*pos), member))
//
//#define list_for_each_entry(pos, head, member)                \
//for (pos = list_entry((head)->next, typeof(*pos), member);&pos->member != (head);   \
//    pos = list_entry(pos->member.next, typeof(*pos), member))   //一个for循环
//
//#endif



//#include <stdio.h>
//#include <stdlib.h>
//#include "kernel_list.h"
//struct student
//{
//    int num;
//    struct list_head mylist;
//};
//// 内核链表的初始化
//struct student * list_init()
//{
//    struct student *head=malloc(sizeof(struct student));
//    INIT_LIST_HEAD(&(head->mylist));
//    return head;
//}
//// 创建新的节点
//struct student * new_node(int data)
//{
//    struct student *new=malloc(sizeof(struct student));
//    new->num=data;
//    INIT_LIST_HEAD(&(new->mylist));
//    return new;
//}
//// 添加新的节点到内核链表中
//int kernellist_add(struct student *new,struct student *head)
//{
//    list_add(&(new->mylist), &(head->mylist));
//    return 0;
//}
//// 打印内核链表的数据
//int show(struct student *head) {
//    struct student *pos;
//    list_for_each_entry(pos, &(head->mylist), mylist) {
//        printf("pos->num is:%d\n", pos->num);
//    }
//
//    return 0;
//}
//int main()
//{
//    int n;
//    int i;
//    struct student *mynewnode;
//    struct student *p=list_init();
//    printf("please input num you want create node!\n");
//    scanf("%d",&n);
//    for(i=1; i<=n; i++)
//    {
//        mynewnode = new_node(i);
//        kernellist_add(mynewnode,p);
//    }
//    show(p);
//    return 0;
//}
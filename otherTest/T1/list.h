//#ifndef T1_LIST_H
//#define T1_LIST_H
//#include <stdio.h>
//#include <stdlib.h>
///*
// * 内核链表
// * 一个双向链表，最后一个元素指向第一个元素，第一个元素指向最后一个元素
// */
//struct list_head{//next：下一个链表的地址 prev：上一个链表的地址
//    struct list_head *next,*prev;
//};
//#define LIST_HEAD_INIT(name) { &(name), &(name) }
//#define LIST_HEAD(name) struct priority_list1 name = LIST_HEAD_INIT(name)//初始化链表 只需要传入链表的名字，就可以初始化完毕了
//#define list_for_each(pos,head) for(pos=(head)->next;pos!=(head);pos=pos->next)//遍历链表 结束判断下一个是否为头节点
//
//static inline void INIT_LIST_HEAD(struct list_head *list){//初始化链表 先定义出链表的实体
//    list->next=list;
//    list->prev=list;
//}
//static inline void _list_head(struct list_head *new_list, struct list_head *prev, struct list_head *next) {//在prev后，next前插入链表
//    prev->next = new_list;
//    new_list->prev = prev;
//    new_list->next = next;
//    next->prev = new_list;
//}
//static inline void list_add(struct list_head *new_list, struct list_head *head){//链表插入 在head后插入new_list
//    _list_head(new_list,head,head->next);
//}
//struct person{
//    struct list_head list;
//    int age;
//};
//void list() {
//    int i;
//    struct person *p;
//    struct person person1;
//    struct list_head *pos;
//
//    INIT_LIST_HEAD(&person1.list);
//
//    for (i = 0; i < 5; i++) {
//        p = (struct person *) malloc(sizeof(struct person));
//        p->age = i * 10;
//        list_add(&p->list, &person1.list);
//    }
//
//    list_for_each(pos, &person1.list) {
//        printf("age = %d\n", ((struct person *) pos)->age);
//    }
//}
//#endif //T1_LIST_H

//
// Created by necromaner on 2020/11/9.
//

#ifndef T1_KERNEL_LIST_H
#define T1_KERNEL_LIST_H


#define LIST_POISON1  nullptr
#define LIST_POISON2  nullptr
#include <cstdlib>

struct list_head{//next：下一个链表的地址 prev：上一个链表的地址
    struct list_head *next,*prev;
};
#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(struct list_head *list)
{//初始化
    list->next = list;
    list->prev = list;
}

#endif //T1_KERNEL_LIST_H

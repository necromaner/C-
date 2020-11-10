//
// Created by necromaner on 2020/11/9.
//

#ifndef T1_R_H
#define T1_R_H
#include <cstdio>
#include <cstdlib>
#include "kernel_list.h"
struct student
{
    int num;
    struct list_head mylist;
};
// 内核链表的初始化
struct student * list_init()
{
    struct student *head=malloc(sizeof(struct student));
    INIT_LIST_HEAD(&(head->mylist));
    return head;
}
// 创建新的节点
struct student * new_node(int data)
{
    struct student *new=malloc(sizeof(struct student));
    new->num=data;
    INIT_LIST_HEAD(&(new->mylist));
    return new;
}
// 添加新的节点到内核链表中
int kernellist_add(struct student *new,struct student *head)
{
list_add(&(new->mylist), &(head->mylist));
return 0;
}
// 打印内核链表的数据
int show(struct student *head)
{
    struct student *pos;
    list_for_each_entry(pos,&(head->mylist),mylist)
    {
        printf("pos->num is:%d\n",pos->num);
    }

    return 0;
}
int main()
{
    int n;
    int i;
    struct student *mynewnode;
    struct student *p=list_init();
    printf("please input num you want create node!\n");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        mynewnode = new_node(i);
        kernellist_add(mynewnode,p);
    }
    show(p);
    return 0;
}
#endif //T1_R_H

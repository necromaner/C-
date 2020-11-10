//#include <stdio.h>
//#include <stdlib.h>
//#include <vector>
//
//
//#include "RedBlackTree/RedBlackTree.h"
////struct person{
////    int age;
////    struct list_head list;
////};
//int main(int argc,char **argv) {
//    RedBlackTree ab;
//    ab.tree_Add(100);
//    ab.tree_Add(200);
//    ab.tree_Add(300);
//    ab.tree_Add(400);
//    ab.tree_Add(500);
//    ab.tree_Add(600);
//    ab.tree_Add(250);
//    ab.tree_Add(350);
//    ab.tree_Add(240);
//
////    ab.tree_Add(250);
////    ab.tree_Add(8);//类型2:左左变形
////    ab.tree_Add(25);
////    ab.tree_Add(27);//类型3:左右变形
////    ab.tree_Add(100);
////    ab.tree_Add(200);//类型2:右右变形 叔叔为空
////    ab.tree_Add(-4);
////    ab.tree_Add(-4);
////    struct person *p;
////    struct person person1;
////    struct list_head *pos;
////
////    INIT_LIST_HEAD(&person1.list);
////
////    std::vector<int> bbb = {-100, -200, -3, -10, 1, 100, 3, 55, -11, 121, 0, 30};
////    for (int i = 0; i < bbb.size(); i++) {
////        p = (struct person *) malloc(sizeof(struct person));
////        p->age = bbb[i];
////        p->list._priority = p->age;
////        list_add(&p->list, &person1.list);
////    }
////    list_for_each(pos, &person1.list) {
////        printf("age = %d\n", ((struct person *) pos)->age);
////    }
//    return 0;
////    test_tree();
//}


#include <stdio.h>
#include <stdlib.h>
#include "list_tree.h"
struct student {
    int num;
    struct list_tree mylist;
};
// 内核链表的初始化
struct student * list_init() {
    student *head=new student;
    INIT_LIST_HEAD(&(head->mylist));
    return head;
}
// 创建新的节点
struct student * new_node(int data) {
    student *new_tree=new student;
    new_tree->num = data*10;
    INIT_LIST_HEAD(&(new_tree->mylist));
    new_tree->mylist._priority=data;
    return new_tree;
}
// 添加新的节点到内核链表中
int kernellist_add(struct student *new_tree,struct student *head) {
    list_add(&(new_tree->mylist), &(head->mylist));
    struct student *pos;
//    list_for_each_entry_reverse(pos, &(new_tree->mylist), mylist) {
//        printf("添加%d is:%d\n", new_tree->num, pos->mylist._priority);
//    }
    return 0;
}
int kernellist_new(struct student *head,int data) {
    struct student *new_tree;
    new_tree = new_node(data);

    list_add(&(new_tree->mylist), &(head->mylist));
    struct student *pos;
//    list_for_each_entry_reverse(pos, &(new_tree->mylist), mylist) {
//        printf("添加%d is:%d\n", new_tree->num, pos->mylist._priority);
//    }
    return 0;
}
// 打印内核链表的数据
int show(struct student *head) {
    struct student *pos;
    list_for_each_entry(pos, &(head->mylist), mylist) {
        printf("pos->num is:%d\n", pos->num);
    }
    return 0;
}
int main() {
    int n;
    int i;
    struct student *mynewnode;
    struct student *p = list_init();
//    printf("please input num you want create node!\n");
//    scanf("%d", &n);
    n=30;
    for (i = 1; i <= n; i++) {
        mynewnode = new_node(i);
        kernellist_add(mynewnode, p);
    }
//    kernellist_new(p,99);
//    kernellist_new(p,-99);

    show(p);
    return 0;
}
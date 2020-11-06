#include <stdio.h>
#include <stdlib.h>
#include <vector>


#include "RedBlackTree/RedBlackTree.h"
//struct person{
//    int age;
//    struct list_head list;
//};
int main(int argc,char **argv) {
    RedBlackTree ab;
    ab.tree_Add(100);
    ab.tree_Add(200);
    ab.tree_Add(300);
    ab.tree_Add(400);
    ab.tree_Add(500);
    ab.tree_Add(600);
    ab.tree_Add(250);
    ab.tree_Add(350);
    ab.tree_Add(240);

//    ab.tree_Add(250);
//    ab.tree_Add(8);//类型2:左左变形
//    ab.tree_Add(25);
//    ab.tree_Add(27);//类型3:左右变形
//    ab.tree_Add(100);
//    ab.tree_Add(200);//类型2:右右变形 叔叔为空
//    ab.tree_Add(-4);
//    ab.tree_Add(-4);
//    struct person *p;
//    struct person person1;
//    struct list_head *pos;
//
//    INIT_LIST_HEAD(&person1.list);
//
//    std::vector<int> bbb = {-100, -200, -3, -10, 1, 100, 3, 55, -11, 121, 0, 30};
//    for (int i = 0; i < bbb.size(); i++) {
//        p = (struct person *) malloc(sizeof(struct person));
//        p->age = bbb[i];
//        p->list._priority = p->age;
//        list_add(&p->list, &person1.list);
//    }
//    list_for_each(pos, &person1.list) {
//        printf("age = %d\n", ((struct person *) pos)->age);
//    }
    return 0;
//    test_tree();
}
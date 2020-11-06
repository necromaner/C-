////
//// Created by necromaner on 2020/10/26.
////
//
//#ifndef T1_BINARY_TREE_H
//#define T1_BINARY_TREE_H
//
//#include "list2.h"
////#include "list_head.h"
//
//struct tree{
//    int val;
//    struct list_head left,right;
//    tree() : val(0), left(), right() {}
//    tree(int x) : val(x), left(), right() {}
//    tree(int x, list_head left, list_head right) : val(x), left(left), right(right) {}
//};
//void test_tree(){
//    struct tree *p;
//    struct tree person1;
//    struct list_head *pos;
//
//    INIT_LIST_HEAD(&person1.left);
//
//    std::vector<int> bbb = {-100, -200, -3, -10, 1, 100, 3, 55, -11, 121, 0, 30};
//    for (int i = 0; i < bbb.size(); i++) {
//        p = (struct tree *) malloc(sizeof(struct tree));
//        p->val = bbb[i];
//        list_add(&p->left, &person1.left);
//    }
//    list_for_each(pos, &person1.left) {
//        printf("left = %d\n", ((struct tree *) pos)->val);
//    }
////    list_for_each_entry(p, &person1.left,tree::left) {
////        printf("left = %d\n", ((struct tree *) pos)->val);
////    }
//}
//#endif //T1_BINARY_TREE_H

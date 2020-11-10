#ifndef T1_LIST_TREE_H
#define T1_LIST_TREE_H

#include <cstdio>
#include <cstdlib>
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)
#define LIST_POISON1  nullptr
#define LIST_POISON2  nullptr
struct list_tree{//next：下一个链表的地址 prev：上一个链表的地址
    int _priority;
    bool isRed;
    struct list_tree *left,*right,*prev;
};
//初始化
#define LIST_HEAD_INIT(name) {INT_MIN, true,&(LIST_POISON1), &(LIST_POISON1), &(LIST_POISON2) }
#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)
static inline void INIT_LIST_HEAD(struct list_tree *list) {
    list->_priority = INT_MIN;
    list->left = LIST_POISON1;
    list->isRed = true;
    list->right = LIST_POISON1;
    list->prev = LIST_POISON2;
}
void TreeNode_DLR(list_tree* root) {//先序遍历-递归
    if (root == LIST_POISON1 || root == LIST_POISON2)
        return;
    if (root->prev != LIST_POISON1)
        printf("%3d%s", root->_priority,root->isRed ? "红 " : "黑 ");
    TreeNode_DLR(root->left);
    TreeNode_DLR(root->right);
}
void TreeNode_LDR(list_tree* root){//中序遍历-递归
    if (root == LIST_POISON1 || root == LIST_POISON2)
        return;
    TreeNode_LDR(root->left);
    if (root->prev != LIST_POISON1)
        printf("%3d%s", root->_priority,root->isRed ? "红 " : "黑 ");
    TreeNode_LDR(root->right);
}
static inline void __list_add(struct list_tree *new_tree, struct list_tree *prev, bool isLeft) {
    if (isLeft) {
        prev->left = new_tree;
    } else {
        prev->right = new_tree;
    }
    new_tree->prev = prev;
}
void list_add_check(struct list_tree *new_tree){
/*
 * 类型0:
 *   1红        1黑
 * T1   T2 =>T1    T2
 * 类型1:
 *       3黑            3红
 *    2红   4红  =>   2黑  4黑
 * 1红             1红
 * 注:1红为添加位置，第三层任意位置均满足
 * 类型2:
 *          3黑                  2黑
 *      2红     4黑    =>    1红      3红
 *   1红   T3 T4   T5     T1   T2  T3    4黑
 * T1   T2                             T4   T5
 * 注:1红为添加位置，4黑可无,可轴对称
 * 类型3:
 *        3黑                     3黑                  2黑
 *   1红       4黑            2红     4黑          1红      3红
 * T1   2红  T4   T5 =>    1红   T3 T4   T5  => T1   T2  T3    4黑
 *    T2   T3            T1   T2                             T4   T5
 * 注:2红为添加位置，4黑可无,可轴对称
 */
    list_tree *now_tree=new_tree;
    list_tree *grandparents[3];//直系三代 0为添加节点 1为父节点 2为爷节点
    for (int i = 0; i < 3; ++i) {
        if(now_tree->prev==LIST_POISON2){
            if(i==1){
                printf("末尾1个元素:");
                for (int aa = 0; aa < 1; ++aa) {
                    printf("%3d%s ", grandparents[aa]->_priority, grandparents[aa]->isRed ? "红 " : "黑 ");
                }
                printf("\n");
                if(grandparents[0]->isRed){
                    printf("类型0:跟节点为红色\n");
                    new_tree->isRed=false;
                }
            } else if (i==2){
                printf("末尾2个元素:");
                for (int aa = 0; aa < 2; ++aa) {
                    printf("%3d%s ", grandparents[aa]->_priority, grandparents[aa]->isRed ? "红 " : "黑 ");
                }
                printf("\n");
                list_add_check(new_tree->prev);
            }
            return;
        }
        grandparents[i] = now_tree;
        now_tree=now_tree->prev;
    }
    printf("末尾3个元素:");
    for (int i = 0; i < 3; ++i) {
        printf("%3d%s ", grandparents[i]->_priority,grandparents[i]->isRed ? "红 " : "黑 ");
    }
    printf("\n");
    if (!(grandparents[0]->isRed && grandparents[1]->isRed)) {//情况合理
        list_add_check(new_tree->prev);
        return;
    }
    if (grandparents[2]->_priority > grandparents[1]->_priority) {//左子树一定小于跟节点
        list_tree *uncle = grandparents[2]->right;//叔叔节点
        if (uncle!=LIST_POISON1 && uncle->isRed) {//类型1 存在兄弟节点切为1
            printf("类型1:左修改颜色\n");
            grandparents[1]->isRed = false;
            grandparents[2]->isRed = true;
            uncle->isRed = false;
            list_add_check(new_tree->prev->prev);
        } else if (grandparents[1]->_priority > grandparents[0]->_priority) {
            printf("类型2:左左变形\n");
            if (now_tree->_priority > grandparents[2]->_priority) {
                now_tree->left = grandparents[1];
            } else {
                now_tree->right = grandparents[1];
            }
            grandparents[1]->prev=now_tree;

            grandparents[2]->left = grandparents[1]->right;
            grandparents[1]->right = grandparents[2];
            grandparents[2]->isRed = true;
            grandparents[1]->isRed = false;
        } else {
            printf("类型3:左右变形\n");
            if (now_tree->_priority > grandparents[2]->_priority) {
                now_tree->left = grandparents[0];
            } else {
                now_tree->right = grandparents[0];
            }
            grandparents[0]->prev=now_tree;

            grandparents[1]->right=grandparents[0]->left;
            grandparents[2]->left=grandparents[0]->right;
            grandparents[0]->left=grandparents[1];
            grandparents[0]->right=grandparents[2];
            grandparents[0]->isRed=false;
            grandparents[2]->isRed=true;
        }
    } else {
        list_tree *uncle = grandparents[2]->left;//叔叔节点
        if (uncle!=LIST_POISON1 && uncle->isRed) {//类型1 存在兄弟节点切为1
            printf("类型1:右修改颜色\n");
            grandparents[2]->isRed = true;
            grandparents[1]->isRed = false;
            uncle->isRed = false;
            list_add_check(new_tree->prev->prev);
        } else if (grandparents[1]->_priority > grandparents[0]->_priority) {
            printf("类型3:右左变形\n");
            if (now_tree->_priority > grandparents[2]->_priority) {
                now_tree->right = grandparents[0];
            } else {
                now_tree->left = grandparents[0];
            }
            grandparents[0]->prev=now_tree;

            grandparents[1]->left = grandparents[0]->right;
            grandparents[2]->right = grandparents[0]->left;
            grandparents[0]->right = grandparents[1];
            grandparents[0]->left = grandparents[2];
            grandparents[0]->isRed = false;
            grandparents[2]->isRed = true;
        } else {
            printf("类型2:右右变形\n");
            if (now_tree->_priority > grandparents[2]->_priority) {//左子树
                now_tree->left = grandparents[1];
            } else {
                now_tree->right = grandparents[1];
            }
            grandparents[1]->prev=now_tree;

            grandparents[2]->right = grandparents[1]->left;
            grandparents[1]->left = grandparents[2];
            grandparents[2]->isRed = true;
            grandparents[1]->isRed = false;
        }
    }

}
static inline void list_add(struct list_tree *new_tree, struct list_tree *head) {
    list_tree *head1=head;
    while (true){
        if(head->_priority>new_tree->_priority){
            if(head->left!=LIST_POISON1){
                head=head->left;
            }else{
                __list_add(new_tree,head,true);
                break;
            }
        }else{
            if(head->right!=LIST_POISON1){
                head=head->right;
            }else{
                __list_add(new_tree,head,false);
                break;
            }
        }
    }
    printf("\n------------------------------------------------------------------------");
    printf("\n修改之前中序遍历:");
    TreeNode_LDR(head1);//中序遍历
    printf("\n修改之前先序遍历:");
    TreeNode_DLR(head1);//先序遍历
    printf("\n-----------------------------------------------------\n");
    list_add_check(new_tree);
    printf("-----------------------------------------------------\n");
    printf("修改之后中序遍历:");
    TreeNode_LDR(head1);//中序遍历
    printf("\n修改之后先序遍历:");
    TreeNode_DLR(head1);//先序遍历
    printf("\n------------------------------------------------------------------------\n");

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
    	for (pos = (head)->next; prefetch(pos->next), pos != (head);pos = pos->next)

#define list_for_each_prev(pos, head) \
        for (pos = (head)->prev; pos != (head);pos = pos->prev)

//#define list_for_each_entry_reverse(pos, head, member)			\
//    	for (pos = list_entry((head)->prev, typeof(*pos), member);	\
//    	     &pos->member != (head); 	\
//    	     pos = list_entry(pos->member.prev, typeof(*pos), member))

//pos 结构体 head 二叉树 member pos中二叉树的结构体
#define list_for_each_entry(pos, head, member)                \
for (pos = list_entry((head)->left, typeof(*pos), member);\
&pos->member != LIST_POISON1;\
pos = list_entry(pos->member.left, typeof(*pos), member))   \

#define list_for_each_entry_reverse(pos, head, member)			\
	for (pos = list_entry((head), typeof(*pos), member);	\
	     &pos->member != LIST_POISON2; 	\
	     pos = list_entry(pos->member.prev, typeof(*pos), member))\

#endif //T1_LIST_TREE_H

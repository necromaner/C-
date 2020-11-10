#include "RedBlackTree.h"
#include <stack>//栈
//

RedBlackTree::RedBlackTree() {
    INIT_LIST_HEAD(&head.list);
}
void RedBlackTree::tree_Add(int val) {
    cout<<"添加链表值:"<<val<<endl;
    tree1 = new TreeNode(val);
    if (list_empty(&head.list)) {//树为空插入头节点
        list_add(&tree1->list, &head.list);
        root=tree1;
    } else {
        __tree_Add(tree1);
    }
    if(root->isRed){
        cout<<"类型0:根节点为红色"<<endl;
        root->isRed=false;
    }
//    struct list_head *pos;
//    printf("       遍历链表:");
//    list_for_each(pos, &head.list) {
//        printf("%3d", ((struct TreeNode *) pos)->val);
//        if (((struct TreeNode *) pos)->isRed)
//            cout << "红 ";
//        else
//            cout << "黑 ";
//    }
    printf("\n修改之后中序遍历:");
    TreeNode_LDR(root);//中序遍历
    printf("\n修改之后先序遍历:");
    TreeNode_DLR(root);//先序遍历
    printf("\n------------------------------------------------------------------------\n");
}
void RedBlackTree::tree_Del(int val) {
    struct list_head *pos;
    list_for_each(pos, &head.list) {
        if(((struct TreeNode *) pos)->val==val){

            return;
        }
    }
}
void RedBlackTree::__tree_Add(TreeNode *tree) {
    tree1 = root;
    stack<TreeNode *> st;
    while (true) {
        st.push(tree1);
        if (tree->val < tree1->val) {
            if (tree1->left) {
                tree1 = tree1->left;
            } else{
                tree_Add_left(tree1, tree);
                tree1->left=tree;
                break;
            }
        } else {
            if (tree1->right) {
                tree1 = tree1->right;
            } else{
                tree_Add_right(tree1, tree);
                tree1->right=tree;
                break;
            }
        }
    }
    st.push(tree);
    tree_Add_check(st);
}

void RedBlackTree::tree_Add_left(TreeNode *tree,TreeNode *add){
    list_add_tail(&add->list, &tree->list);
}
void RedBlackTree::tree_Add_right(TreeNode *tree,TreeNode *add){
    list_add(&add->list, &tree->list);
}
void RedBlackTree::tree_Add_check(stack<TreeNode *> &check_tree) {
/*
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

    stack<TreeNode *> st = check_tree;
    if (st.size() < 3)
        return;
    printf("------------------\n");
    cout << "栈长度为" << st.size() << ",末尾三个:";

    TreeNode *grandparents[3];//直系三代 0为添加节点 1为父节点 2为爷节点
    for (int i = 0; i < 3; ++i) {
        grandparents[i] = st.top();
        st.pop();
    }
    for (int i = 0; i < 3; ++i) {
        printf("%3d", grandparents[2-i]->val);
        if (grandparents[2-i]->isRed)
            cout << "红 ";
        else
            cout << "黑 ";
    }
    cout << endl;
    if (!(grandparents[0]->isRed && grandparents[1]->isRed)) {//情况合理
        check_tree.pop();
        tree_Add_check(check_tree);
        return;
    }
    printf("修改之前中序遍历:");
    TreeNode_LDR(root);//中序遍历
    printf("\n修改之前先序遍历:");
    TreeNode_DLR(root);//先序遍历
    printf("\n");
    if (grandparents[2]->val > grandparents[1]->val) {//左子树一定小于跟节点
        TreeNode *uncle = grandparents[2]->right;//叔叔节点
        if (uncle && uncle->isRed) {//类型1 存在兄弟节点切为1
            cout << "类型1:修改颜色" << endl;
            grandparents[1]->isRed = false;
            grandparents[2]->isRed = true;
            uncle->isRed = false;
            check_tree.pop();
            tree_Add_check(check_tree);
        } else if (grandparents[1]->val > grandparents[0]->val) {
            cout << "类型2:左左变形" << endl;
            if (st.empty())
                root = grandparents[1];
            else {
                TreeNode *tree_top = st.top();
                if (tree_top->val > grandparents[2]->val) {
                    cout << "根部左子树修改" << endl;
                    tree_top->left = grandparents[1];
                } else {
                    cout << "根部右子树修改" << endl;
                    tree_top->right = grandparents[1];
                }
            }
            grandparents[2]->left = grandparents[1]->right;
            grandparents[1]->right = grandparents[2];
            grandparents[2]->isRed = true;
            grandparents[1]->isRed = false;
        } else {
            cout << "类型3:左右变形" << endl;
            if (st.empty())
                root = grandparents[0];
            else {
                TreeNode *tree_top = st.top();
                if (tree_top->val > grandparents[2]->val) {
                    cout << "根部左子树修改" << endl;
                    tree_top->left = grandparents[0];
                } else {
                    cout << "根部右子树修改" << endl;
                    tree_top->right = grandparents[0];
                }
            }
            grandparents[1]->right=grandparents[0]->left;
            grandparents[2]->left=grandparents[0]->right;
            grandparents[0]->left=grandparents[1];
            grandparents[0]->right=grandparents[2];
            grandparents[0]->isRed=false;
            grandparents[2]->isRed=true;
        }
    } else {
        TreeNode *uncle = grandparents[2]->left;//叔叔节点
        if (uncle && uncle->isRed) {//类型1 存在兄弟节点切为1
            cout << "类型1:修改颜色" << endl;
            grandparents[1]->isRed = false;
            grandparents[2]->isRed = true;
            uncle->isRed = false;
            check_tree.pop();
            tree_Add_check(check_tree);
        } else if (grandparents[1]->val > grandparents[0]->val) {
            cout << "类型3:右左变形" << endl;
            if (st.empty())
                root = grandparents[0];
            else {
                TreeNode *tree_top = st.top();
                if (tree_top->val > grandparents[2]->val) {
                    cout << "根部左子树修改" << endl;
                    tree_top->right = grandparents[0];
                } else {
                    cout << "根部右子树修改" << endl;
                    tree_top->left = grandparents[0];
                }
            }
            grandparents[1]->left = grandparents[0]->right;
            grandparents[2]->right = grandparents[0]->left;
            grandparents[0]->right = grandparents[1];
            grandparents[0]->left = grandparents[2];
            grandparents[0]->isRed = false;
            grandparents[2]->isRed = true;
        } else {
            cout << "类型2:右右变形" << endl;
            if (st.empty())
                root = grandparents[1];
            else {
                TreeNode *tree_top = st.top();
                if (tree_top->val > grandparents[2]->val) {//左子树
                    cout << "根部左子树修改" << endl;
                    tree_top->left = grandparents[1];
                } else {
                    cout << "根部右子树修改" << endl;
                    tree_top->right = grandparents[1];
                }
            }
            grandparents[2]->right = grandparents[1]->left;
            grandparents[1]->left = grandparents[2];
            grandparents[2]->isRed = true;
            grandparents[1]->isRed = false;
        }
    }
}
void RedBlackTree::TreeNode_DLR(TreeNode* root) {//先序遍历-递归
    if (root == nullptr)
        return;
    printf("%3d", root->val);
    if(root->isRed)
        cout<<"红 ";
    else
        cout<<"黑 ";
    TreeNode_DLR(root->left);
    TreeNode_DLR(root->right);
}
void RedBlackTree::TreeNode_LDR(TreeNode* root) {//中序遍历-递归
    if (root == nullptr)
        return;
    TreeNode_LDR(root->left);
    printf("%3d", root->val);
    if(root->isRed)
        cout<<"红 ";
    else
        cout<<"黑 ";
    TreeNode_LDR(root->right);
}


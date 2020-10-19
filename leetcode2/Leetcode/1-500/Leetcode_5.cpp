#include "../leetcode.h"

//225. 用队列实现栈
/*
使用队列实现栈的下列操作：
    push(x) -- 元素 x 入栈
    pop() -- 移除栈顶元素
    top() -- 获取栈顶元素
    empty() -- 返回栈是否为空

注意:
    你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
    你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
    你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
 */



//235. 二叉搜索树的最近公共祖先
/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

示例 1:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6
解释: 节点 2 和节点 8 的最近公共祖先是 6。

示例 2:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

说明:
    所有节点的值都是唯一的。
    p、q 为不同节点且均存在于给定的二叉搜索树中。
 */
TreeNode* Leetcode::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {//2020-09-27
//    执行用时：44 ms, 在所有 C++ 提交中击败了70.55% 的用户
//    内存消耗：22.9 MB, 在所有 C++ 提交中击败了41.46% 的用户
        if (root == nullptr)
            return nullptr;
        TreeNode *ans = root;
        while (true) {
            int pp = ans->val - p->val;
            int qq = ans->val - q->val;
            if (pp == 0 || qq == 0 || (pp >> 31) != (qq >> 31)) {
                return new TreeNode(ans->val);
    //            return ans;
            }
            if (pp < 0)
                ans = ans->right;
            else
                ans = ans->left;
        }
////    执行用时：40 ms, 在所有 C++ 提交中击败了89.49% 的用户
////    内存消耗：22.8 MB, 在所有 C++ 提交中击败了68.33% 的用户
//        if (root == nullptr)
//            return nullptr;
//        TreeNode *ans = root;
//        while (true) {
//            if (p->val < ans->val && q->val < ans->val) {
//                ans = ans->left;
//            } else if (p->val > ans->val && q->val > ans->val) {
//                ans = ans->right;
//            } else {
//                return ans;
//            }
//        }
////    执行用时：44 ms, 在所有 C++ 提交中击败了70.55% 的用户
////    内存消耗：22.7 MB, 在所有 C++ 提交中击败了98.41% 的用户
//        if (root == nullptr)
//            return nullptr;
//        if (p->val < root->val && q->val < root->val)
//            return lowestCommonAncestor(root->left, p, q);
//        else if (p->val > root->val && q->val > root->val)
//            return lowestCommonAncestor(root->right, p, q);
//        else
//            return root;
////    执行用时：40 ms, 在所有 C++ 提交中击败了89.49% 的用户
////    内存消耗：22.8 MB, 在所有 C++ 提交中击败了68.33% 的用户
////抄
//    return ((p->val <= root->val && root->val <= q->val) || (q->val <= root->val && root->val <= p->val)) ? root : lowestCommonAncestor(p->val < root->val ?root->left : root->right, p, q);
}
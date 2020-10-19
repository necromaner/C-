#include "../leetcode.h"
#include <stack>
//617. 合并二叉树
/*
给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入:
	Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
输出:
合并后的树:
	     3
	    / \
	   4   5
	  / \   \
	 5   4   7

注意: 合并必须从两个树的根节点开始。
 */
TreeNode* Leetcode::mergeTrees(TreeNode* t1, TreeNode* t2) {//2020-09-23
//    执行用时：76 ms, 在所有 C++ 提交中击败了66.86% 的用户
//    内存消耗：32.8 MB, 在所有 C++ 提交中击败了30.65% 的用户
        if (t1 == nullptr)
            return t2;
        if (t2 == nullptr)
            return t1;
//        t1->val += t2->val;
//        t1->left = mergeTrees(t1->left, t2->left);
//        t1->right = mergeTrees(t1->right, t2->right);
//        return t1;
        TreeNode *t3 = new TreeNode(t1->val + t2->val);
        t3->left = mergeTrees(t1->left, t2->left);
        t3->right = mergeTrees(t1->right, t2->right);
        return t3;

}
TreeNode* Leetcode::mergeTrees_1(TreeNode* t1, TreeNode* t2) {//2020-09-23
////    方法一：深度优先搜索
//    if (t1 == nullptr) {
//        return t2;
//    }
//    if (t2 == nullptr) {
//        return t1;
//    }
//    auto merged = new TreeNode(t1->val + t2->val);
//    merged->left = mergeTrees(t1->left, t2->left);
//    merged->right = mergeTrees(t1->right, t2->right);
//    return merged;
////    方法二：广度优先搜索
//    if (t1 == nullptr) {
//        return t2;
//    }
//    if (t2 == nullptr) {
//        return t1;
//    }
//    auto merged = new TreeNode(t1->val + t2->val);
//    auto q = queue<TreeNode*>();
//    auto queue1 = queue<TreeNode*>();
//    auto queue2 = queue<TreeNode*>();
//    q.push(merged);
//    queue1.push(t1);
//    queue2.push(t2);
//    while (!queue1.empty() && !queue2.empty()) {
//        auto node = q.front(), node1 = queue1.front(), node2 = queue2.front();
//        q.pop();
//        queue1.pop();
//        queue2.pop();
//        auto left1 = node1->left, left2 = node2->left, right1 = node1->right, right2 = node2->right;
//        if (left1 != nullptr || left2 != nullptr) {
//            if (left1 != nullptr && left2 != nullptr) {
//                auto left = new TreeNode(left1->val + left2->val);
//                node->left = left;
//                q.push(left);
//                queue1.push(left1);
//                queue2.push(left2);
//            } else if (left1 != nullptr) {
//                node->left = left1;
//            } else if (left2 != nullptr) {
//                node->left = left2;
//            }
//        }
//        if (right1 != nullptr || right2 != nullptr) {
//            if (right1 != nullptr && right2 != nullptr) {
//                auto right = new TreeNode(right1->val + right2->val);
//                node->right = right;
//                q.push(right);
//                queue1.push(right1);
//                queue2.push(right2);
//            } else if (right1 != nullptr) {
//                node->right = right1;
//            } else {
//                node->right = right2;
//            }
//        }
//    }
//    return merged;
////    栈迭代
//    if(!t1) return t2;
//    stack<pair<TreeNode*, TreeNode*>> stk;
//    if(t1 && t2) stk.push(make_pair(t1, t2));
//    while(stk.size()) {
//        pair<TreeNode*,TreeNode*> cur = stk.top(); stk.pop();
//        cur.first->val = cur.first->val + cur.second->val;
//        if(cur.second->left) {
//            if(!cur.first->left) cur.first->left = new TreeNode(0); //如果左子树不存在，新建值为0的节点
//            stk.push(make_pair(cur.first->left, cur.second->left));
//        }
//        if(cur.second->right) {
//            if(!cur.first->right ) cur.first->right = new TreeNode(0); //如果右子树不存在，新建值为0的节点
//            stk.push(make_pair(cur.first->right, cur.second->right));
//        }
//    }
//    return t1;

////    队列迭代
    if(!t1) return t2;
    if(!t2) return t1;
    queue<pair<TreeNode*, TreeNode*>> q;
    q.push(make_pair(t1, t2));
    while(q.size()) {
        pair<TreeNode*,TreeNode*> cur = q.front();
        q.pop();
        cur.first->val = cur.first->val + cur.second->val;
        if(cur.second->left) {
            if(!cur.first->left){
                cur.first->left = new TreeNode(0);
            }
            q.push(make_pair(cur.first->left, cur.second->left));
        }
        if(cur.second->right) {
            if(!cur.first->right ){
                cur.first->right = new TreeNode(0);
            }
            q.push(make_pair(cur.first->right, cur.second->right));
        }
    }
    return t1;
}
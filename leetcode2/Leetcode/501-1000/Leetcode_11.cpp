#include "../leetcode.h"
//501. 二叉搜索树中的众数
/*
给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

    结点左子树中所含结点的值小于等于当前结点的值
    结点右子树中所含结点的值大于等于当前结点的值
    左子树和右子树都是二叉搜索树

例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2

返回[2].

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
 */
vector<int> Leetcode::findMode(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;
    // BST 的中序遍历 是 顺序排列的。

    stack < TreeNode * > st;
    TreeNode *tmp = root;

    // ma 出现最多的 次数， last 上一次出现的值。 now 当前数已经出现过的次数。
    int ma = 0, last = -1, now = 0;

    // 迭代写法。 没有使用递归。手写栈模拟系统栈 ，实现递归程序。
    while (!st.empty() || tmp) {
        while (tmp) {
            st.push(tmp);
            tmp = tmp->left;
        }

        TreeNode *t = st.top();
        st.pop();

        if (last == t->val) now++;
        else now = 1;

        if (now > ma) {
            ans.clear();
            ans.push_back(t->val);
            ma = now;
        } else if (now == ma) {
            ans.push_back(t->val);
        }

        last = t->val;
        tmp = t->right;
    }

    return ans;
}
//530. 二叉搜索树的最小绝对差
/*
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。



示例：

输入：

   1
    \
     3
    /
   2

输出：
1

解释：
最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 提示：
    树中至少有 2 个节点。
 */
int Leetcode::getMinimumDifference(TreeNode* root) {//2020-10-12
//    执行用时：24 ms, 在所有 C++ 提交中击败了92.95% 的用户
//    内存消耗：24.7 MB, 在所有 C++ 提交中击败了45.14% 的用户
/*思路：
 * 1。二叉搜索数->前序遍历
 * 2。非负
 * 3。至少2个节点
 */
    int ans = INT_MAX, last = 0;
    bool isFirst = true;
    if (!root)
        return 0;
    stack<TreeNode *> st;
    TreeNode *tmp = root;
    while (tmp != nullptr || !st.empty()) {
        while (tmp) {
            st.push(tmp);
            tmp = tmp->left;
        }
        TreeNode *t = st.top();
        st.pop();
        tmp = t->right;
        if (isFirst) {
            last = t->val;
            isFirst = false;
            continue;
        }
        ans = min(ans, t->val - last);
        last = t->val;
    }
    return ans;
}
void T530_dfs(TreeNode* root, int& pre, int& ans) {
    if (root == nullptr) {
        return;
    }
    T530_dfs(root->left, pre, ans);
    if (pre == -1) {//中序遍历第一个
        pre = root->val;
    } else {
        ans = min(ans, root->val - pre);
        pre = root->val;
    }
    T530_dfs(root->right, pre, ans);
}
int Leetcode::getMinimumDifference_1(TreeNode* root) {//抄
////    执行用时：28 ms, 在所有 C++ 提交中击败了82.12% 的用户
////    内存消耗：24.4 MB, 在所有 C++ 提交中击败了98.62% 的用户
////    dfs
//    int ans = INT_MAX, pre = -1;
//    T530_dfs(root, pre, ans);
//    return ans;

//    执行用时：36 ms, 在所有 C++ 提交中击败了37.95% 的用户
//    内存消耗：24.6 MB, 在所有 C++ 提交中击败了58.30% 的用户
//    中序遍历——莫里斯遍历
    TreeNode *cur;
    cur = root;
    TreeNode *pre;
    int pre_val = INT_MAX;
    int min_val = INT_MAX;
    while (cur) {
        if (!cur->left) {
            min_val = min(min_val, abs(cur->val - pre_val));
            pre_val = cur->val;
            cur = cur->right;
            continue;
        }
        pre = cur->left;
        while (pre->right && pre->right != cur)
            pre = pre->right;
        if (!pre->right) {
            pre->right = cur;
            cur = cur->left;
        } else if (pre->right == cur) {
            pre->right = nullptr;
            min_val = min(min_val, abs(cur->val - pre_val));
            pre_val = cur->val;
            cur = cur->right;
        }
    }
    return min_val;
}
//538. 把二叉搜索树转换为累加树
/*
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
例如：
输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13
 */
int T538_num = 0;
TreeNode* Leetcode::convertBST(TreeNode* root) {//2020-09-21
//    二叉搜索树 根节点大于左子树 小于右子树 中序遍历 从小到大

//    执行用时：64 ms, 在所有 C++ 提交中击败了82.84% 的用户
//    内存消耗：32.7 MB, 在所有 C++ 提交中击败了42.44%
    if(root){
        //右
        convertBST(root->right);
        //中
        root->val+=T538_num;
        T538_num=root->val;
        //左
        convertBST(root->left);
        return root;
    }
    return nullptr;
}
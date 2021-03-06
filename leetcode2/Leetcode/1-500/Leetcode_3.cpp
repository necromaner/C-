#include "../leetcode.h"
//101. 对称二叉树
/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3

进阶：
你可以运用递归和迭代两种方法解决这个问题吗？
 */
bool check(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}

bool Leetcode::isSymmetric(TreeNode* root) {
    return check(root, root);
}
//104. 二叉树的最大深度
/*
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，
    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
 */

int Leetcode::maxDepth(TreeNode* root) {
    if(!root)
        return 0;
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    return max(left,right)+1;
}
int Leetcode::maxDepth1(TreeNode* root) {
    return !root ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
//106. 从中序与后序遍历序列构造二叉树
/*
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]

返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
 */
TreeNode* Leetcode::buildTree(vector<int>& inorder, vector<int>& postorder) {//2020-09-25
//    执行用时：44 ms, 在所有 C++ 提交中击败了40.57% 的用户
//    内存消耗：64.2 MB, 在所有 C++ 提交中击败了12.29% 的用户
    //后序遍历最后一位代表根结点
    if(postorder.empty())
        return nullptr;
    int size=inorder.size();
    int head=postorder[postorder.size() - 1];
    auto root = new TreeNode(head);//根节点
    int sizeLeft=0;
    for (int i = 0; i < size; ++i) {//中序遍历中寻找到根结点
        if(inorder[i]==head)
            sizeLeft=i;
    }
    int sizeRight= size - sizeLeft - 1;
    vector<int> inorderleft(inorder.begin(), inorder.begin() + sizeLeft);
    vector<int> inorderright(inorder.end()-sizeRight,inorder.end());
    vector<int> postorderleft(postorder.begin(), postorder.begin() + sizeLeft);
    vector<int> postorderright(postorder.begin() + sizeLeft, postorder.begin() + sizeLeft + sizeRight);
    root->left=buildTree(inorderleft,postorderleft);
    root->right=buildTree(inorderright,postorderright);
    return root;
}
//113. 路径总和 II
/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。
示例:
给定如下二叉树，以及目标和 sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:
[
   [5,4,11,2],
   [5,8,4,5]
]
 */
vector<vector<int>> Leetcode::pathSum(TreeNode* root, int sum) {//2020-09-27
    if (root == nullptr)
        return {};
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode *top = s.top();
        s.pop();
        printf("%d ", top->val);//在前面
        if (top->right) s.push(top->right);
        if (top->left) s.push(top->left);
    }
}
//116. 填充每个节点的下一个右侧节点指针
/*
给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。

示例：
输入：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}
输出：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。

提示：
    你只能使用常量级额外空间。
    使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 */
void T116_1(Node* root,int high,vector<Node*>& vec) {
    if (root == nullptr)
        return;
    if (high >= vec.size()) {//新的一行
        vec.push_back(root);
    } else {
        root->next = vec[high];
        vec[high] = root;
    }
    T116_1(root->right, high + 1, vec);
    T116_1(root->left, high + 1, vec);
}
Node* connect_116_1(Node* root) {//抄
////    执行用时：20 ms, 在所有 C++ 提交中击败了99.63% 的用户
////    内存消耗：16.9 MB, 在所有 C++ 提交中击败了21.99% 的用户
////    方法一：层次遍历
//    if (!root)
//        return root;
//    queue<Node *> Q;// 初始化队列同时将第一层节点加入队列中，即根节点
//    Q.push(root);
//    while (!Q.empty()) {// 外层的 while 循环迭代的是层数
//        int size = Q.size();// 记录当前队列大小
//        for (int i = 0; i < size; i++) {// 遍历这一层的所有节点
//            Node *node = Q.front();// 从队首取出元素
//            Q.pop();
//            if (i < size - 1) // 连接
//                node->next = Q.front();
//            if (node->left) // 拓展下一层节点
//                Q.push(node->left);
//            if (node->right)
//                Q.push(node->right);
//        }
//    }
//    return root;// 返回根节点

//    执行用时：20 ms, 在所有 C++ 提交中击败了99.63% 的用户
//    内存消耗：16.7 MB, 在所有 C++ 提交中击败了59.61% 的用户
//    方法二：使用已建立的 next指针
    if (!root)
        return root;
    Node *leftmost = root;// 从根节点开始
    while (leftmost->left) {
        Node *head = leftmost;// 遍历这一层节点组织成的链表，为下一层的节点更新 next 指针
        while (head) {
            head->left->next = head->right;// CONNECTION 1
            if (head->next) // CONNECTION 2
                head->right->next = head->next->left;
            head = head->next;// 指针向后移动
        }
        leftmost = leftmost->left;// 去下一层的最左的节点
    }
    return root;
}
Node* Leetcode::connect_116(Node* root) {//2020-10-15
////    执行用时：40 ms, 在所有 C++ 提交中击败了28.24% 的用户
////    内存消耗：16.6 MB, 在所有 C++ 提交中击败了61.80% 的用户
//    vector<Node *> vec;
//    T116_1(root, 0, vec);
//    return root;

//    执行用时：20 ms, 在所有 C++ 提交中击败了99.63% 的用户
//    内存消耗：17.1 MB, 在所有 C++ 提交中击败了8.38% 的用户
    if (!root)
        return root;
    queue<Node *> aa;
    Node *aa_top;
    aa.push(root);

    int num = 1;
    int max = 2;
    while (!aa.empty()) {
        aa_top = aa.front();
        aa.pop();
        if (!aa.empty() && num < max) {
            num++;
            aa_top->next = aa.front();
        } else {
            num = 1;
            max *= 2;
        }
        if (aa_top->left)
            aa.push(aa_top->left);
        if (aa_top->right)
            aa.push(aa_top->right);
    }
    return root;
}
//117. 填充每个节点的下一个右侧节点指针 II
/*
给定一个二叉树
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。

进阶：
    你只能使用常量级额外空间。
    使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

示例：
输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。

提示：
    树中的节点数小于 6000
    -100 <= node.val <= 100
 */
void T117_aa(Node* root,int high,vector<Node*>& vec) {
    if (root == nullptr)
        return;
    if (high >= vec.size()) {//新的一行
        vec.push_back(root);
    } else {
        root->next = vec[high];
        vec[high] = root;
    }
    T117_aa(root->right, high + 1, vec);
    T117_aa(root->left, high + 1, vec);
}
Node* Leetcode::connect(Node* root) {//2020-09-28
//    执行用时：20 ms, 在所有 C++ 提交中击败了72.92% 的用户
//    内存消耗：17.1 MB, 在所有 C++ 提交中击败了77.21% 的用户
    vector<Node *> vec;
    T117_aa(root, 0, vec);
    return root;
}
void handle(Node* &last, Node* &p, Node* &nextStart) {
    if (last) {
        last->next = p;
    }
    if (!nextStart) {
        nextStart = p;
    }
    last = p;
}

Node* Leetcode::connect1(Node* root) {//抄
////    方法一：层次遍历
////    执行用时：24 ms, 在所有 C++ 提交中击败了47.82% 的用户
////    内存消耗：17.3 MB, 在所有 C++ 提交中击败了36.16% 的用户
//    if (!root) {
//        return nullptr;
//    }
//    queue<Node *> q;
//    q.push(root);
//    while (!q.empty()) {
//        int n = q.size();
//        Node *last = nullptr;
//        for (int i = 1; i <= n; ++i) {
//            Node *f = q.front();
//            q.pop();
//            if (f->left) {
//                q.push(f->left);
//            }
//            if (f->right) {
//                q.push(f->right);
//            }
//            if (i != 1) {
//                last->next = f;
//            }
//            last = f;
//        }
//    }
//    return root;

////    方法二：使用已建立的 next\rm nextnext 指针
////    执行用时：20 ms, 在所有 C++ 提交中击败了72.92% 的用户
////    内存消耗：17 MB, 在所有 C++ 提交中击败了90.21% 的用户
//    if (!root) {
//        return nullptr;
//    }
//    Node *start = root;
//    while (start) {
//        Node *last = nullptr, *nextStart = nullptr;
//        for (Node *p = start; p != nullptr; p = p->next) {
//            if (p->left) {
//                handle(last, p->left, nextStart);
//            }
//            if (p->right) {
//                handle(last, p->right, nextStart);
//            }
//        }
//        start = nextStart;
//    }
//    return root;
////    方法二：使用已建立的 next\rm nextnext 指针
//    执行用时：16 ms, 在所有 C++ 提交中击败了91.68% 的用户
//    内存消耗：17.4 MB, 在所有 C++ 提交中击败了23.73% 的用户
        if (root == nullptr)
            return root;
        queue<Node *> queue;
        queue.push(root);
        while (!queue.empty()) {
            //每一层的数量
            int levelCount = queue.size();
            //前一个节点
            Node *pre = nullptr;
            for (int i = 0; i < levelCount; i++) {
                //出队
                Node *node = queue.front();
                queue.pop();
                //如果pre为空就表示node节点是这一行的第一个，
                //没有前一个节点指向他，否则就让前一个节点指向他
                if (pre != nullptr) {
                    pre->next = node;
                }
                //然后再让当前节点成为前一个节点
                pre = node;
                //左右子节点如果不为空就入队
                if (node->left != nullptr)
                    queue.push(node->left);
                if (node->right != nullptr)
                    queue.push(node->right);
            }
        }
        return root;

}
//120. 三角形最小路径和
/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：
如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 */
int Leetcode::minimumTotal(vector<vector<int>> &triangle) {
//执行用时 :24 ms, 在所有 cpp 提交中击败了5.05% 的用户
//内存消耗 :33.2 MB, 在所有 cpp 提交中击败了5.13%的用户
    vector<vector<int>> xx=triangle;//最短路径三角形
    int aa;
    if (triangle.size() < 2) {
        return xx[0][0];
    }
    xx[1][1] = triangle[0][0] + triangle[1][1];
    for (int i = 1; i < triangle.size(); i++) {
        xx[i][0] = xx[i - 1][0] + triangle[i][0];
        xx[i][1] = xx[i - 1][0] + triangle[i][1];
        if (triangle.size() > 2)
            minimumTotal1(triangle,xx, aa, i, 1);
    }
    return *min_element(xx[xx.size()-1].begin(), xx[xx.size()-1].end());
}
void Leetcode::minimumTotal1(vector<vector<int>> triangle,vector<vector<int>> &xx, int &aa, int i, int j) {
    for (int k = 1; k < triangle[i].size() - 1; k++) {
        aa = xx[i - 1][k] + triangle[i][k];  //  前一个数
        if (aa <= xx[i][k]) {
            xx[i][k] = aa;
        }
        xx[i][k + 1] = xx[i - 1][k] + triangle[i][k + 1];//后一个数
    }
}
//129. 求根到叶子节点数字之和
/*
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
例如，从根到叶子节点路径 1->2->3 代表数字 123。
计算从根到叶子节点生成的所有数字之和。
说明: 叶子节点是指没有子节点的节点。

示例 1:
输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.

示例 2:
输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.
 */
int t129_1(int num,TreeNode* root) {//2020-10-29
////    执行用时：4 ms, 在所有 C++ 提交中击败了81.75% 的用户
////    内存消耗：12.4 MB, 在所有 C++ 提交中击败了24.59% 的用户
//    if (!root) {
//        return 0;
//    }
//    int num1 = 0;
//    if (root->left)
//        num1 += t129_1(num * 10 + root->val, root->left);
//    if (root->right)
//        num1 += t129_1(num * 10 + root->val, root->right);
//    if (!root->left && !root->right) {
//        return num * 10 + root->val;
//    }
//    return num1;

//    执行用时：8 ms, 在所有 C++ 提交中击败了35.09% 的用户
//    内存消耗：12.4 MB, 在所有 C++ 提交中击败了27.42% 的用户
//    参考
    if (!root)return 0;
    int num1 = num * 10 + root->val;
    if (!root->left && !root->right)return num1;
    return t129_1(num1, root->left)+t129_1(num1, root->right);
}
int Leetcode::sumNumbers(TreeNode* root) {//2020-10-30
//    递归
//    return t129_1(0,root);

////    执行用时：4 ms, 在所有 C++ 提交中击败了81.70% 的用户
////    内存消耗：12.7 MB, 在所有 C++ 提交中击败了13.51% 的用户
////    迭代 参考
//    if (!root)return 0;
//    stack<TreeNode *> st;
//    stack<int> num;
//    int sum = 0;
//    st.push(root);
//    num.push(root->val);
//    while (!st.empty()) {
//        TreeNode *node = st.top();
//        int num1 = num.top();
//        st.pop();
//        num.pop();
//        TreeNode *left = node->left;
//        TreeNode *right = node->right;
//        if (!left && !right) {
//            sum += num1;
//        } else {
//            if (left) {
//                st.push(left);
//                num.push(num1 * 10 + left->val);
//            }
//            if (right) {
//                st.push(right);
//                num.push(num1 * 10 + right->val);
//            }
//        }
//    }
//    return sum;

//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：12.6 MB, 在所有 C++ 提交中击败了17.02% 的用户
//    迭代减少变量
    if (!root)return 0;
    stack<TreeNode *> st;
    int sum = 0;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top();
        st.pop();
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        if (!left && !right)
            sum += node->val;
        else {
            if (left) {
                left->val = node->val * 10 + left->val;
                st.push(left);
            }
            if (right) {
                right->val = node->val * 10 + right->val;
                st.push(right);
            }
        }
    }
    return sum;
}
int sumNumbers_1(TreeNode* root) {//抄
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：13 MB, 在所有 C++ 提交中击败了10.10% 的用户
    if (root == nullptr) {
        return 0;
    }
    int sum = 0;
    queue<TreeNode*> nodeQueue;
    queue<int> numQueue;
    nodeQueue.push(root);
    numQueue.push(root->val);
    while (!nodeQueue.empty()) {
        TreeNode* node = nodeQueue.front();
        int num = numQueue.front();
        nodeQueue.pop();
        numQueue.pop();
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        if (left == nullptr && right == nullptr) {
            sum += num;
        } else {
            if (left != nullptr) {
                nodeQueue.push(left);
                numQueue.push(num * 10 + left->val);
            }
            if (right != nullptr) {
                nodeQueue.push(right);
                numQueue.push(num * 10 + right->val);
            }
        }
    }
    return sum;
}
//140. 单词拆分 II
/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

    分隔时可以重复使用字典中的单词。
    你可以假设字典中没有重复的单词。

示例 1：

输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]

示例 2：

输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。

示例 3：

输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]
 */
void t140_1(const string& s, int index,vector<string> &ans,vector<string> add,unordered_set<string> wordSet){
    int size=s.size();
    if(index>=size){
        string ans1;
        for(auto ss:add){
            ans1+=ss+" ";
        }
        ans1.pop_back();
        ans.push_back(ans1);
        return;
    }
    for (int i = 1; i < size-index+1; ++i) {
        string word = s.substr(index, i);
        if(wordSet.find(word)!=wordSet.end()){
            add.push_back(word);
            t140_1(s,index+i,ans,add,wordSet);
            add.pop_back();
        }
    }
}
vector<string> Leetcode::wordBreak(string s, vector<string>& wordDict) {//2020-11-01
    //超时
    vector<string> ans,add;
    unordered_set<string> wordSet = unordered_set(wordDict.begin(), wordDict.end());
    t140_1(s,0,ans,add,wordSet);
    return ans;
}
vector<string> t140_3(unordered_map<string,vector<string> >& m,vector<string>& wordDict,string s){
    if(m.count(s)) return m[s];
    if(s.empty()) return {""};
    vector<string> res;
    for(auto word:wordDict){
        if(s.substr(0,word.size())!=word) continue;
        vector<string> tmp=t140_3(m,wordDict,s.substr(word.size()));
        for(auto itm:tmp){
            res.push_back(word+(itm.empty()?"":" "+itm));
        }
    }
    m[s]=res;
    return res;
}
unordered_map<int, vector<string>> t140_2_2;
unordered_set<string> t140_2_1;
void t140_2(const string& s, int index) {
    if (!t140_2_2.count(index)) {
        if (index == s.size()) {
            t140_2_2[index] = {""};
            return;
        }
        t140_2_2[index] = {};
        for (int i = index + 1; i <= s.size(); ++i) {
            string word = s.substr(index, i - index);
            if (t140_2_1.count(word)) {
                t140_2(s, i);
                for (const string& succ: t140_2_2[i]) {
                    t140_2_2[index].push_back(succ.empty() ? word : word + " " + succ);
                }
            }
        }
    }
}
vector<string> wordBreak_1(string s, vector<string>& wordDict) {//抄
//    执行用时：16 ms, 在所有 C++ 提交中击败了80.46% 的用户
//    内存消耗：12.9 MB, 在所有 C++ 提交中击败了27.48% 的用户
    t140_2_1 = unordered_set(wordDict.begin(), wordDict.end());
    t140_2(s, 0);
    return t140_2_2[0];

//    执行用时：28 ms, 在所有 C++ 提交中击败了60.15% 的用户
//    内存消耗：10.3 MB, 在所有 C++ 提交中击败了52.16% 的用户
    unordered_map<string,vector<string> > m;
    return t140_3(m,wordDict,s);
}
//141. 环形链表
/*
给定一个链表，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
如果链表中存在环，则返回 true 。 否则，返回 false 。

进阶：
你能用 O(1)（即，常量）内存解决此问题吗？

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：
输入：head = [1], pos = -1
输出：false
解释：链表中没有环。

提示：
    链表中节点的数目范围是 [0, 104]
    -105 <= Node.val <= 105
    pos 为 -1 或者链表中的一个 有效索引 。
 */
bool Leetcode::hasCycle(ListNode *head) {//2020-10-09
////    执行用时：44 ms, 在所有 C++ 提交中击败了5.82% 的用户
////    内存消耗：9.8 MB, 在所有 C++ 提交中击败了9.28% 的用户
//    if (head == nullptr)
//        return false;
//    auto head1 = head;
//    set<ListNode *> ss;
//    while (head1->next != nullptr) {
//        auto pos = ss.find(head1);
//        if (pos != ss.end()) {
//            return true;
//        } else {
//            ss.insert(head1);
//            head1 = head1->next;
//        }
//    }
//    return false;
//    执行用时：56 ms, 在所有 C++ 提交中击败了5.82% 的用户
//    内存消耗：9.9 MB, 在所有 C++ 提交中击败了7.01% 的用户
        auto head1 = head;
        set<ListNode *> ss;
        while (head1 != nullptr) {
            auto pos = ss.find(head1);
            if (pos != ss.end()) {
                return true;
            } else {
                ss.insert(head1);
                head1 = head1->next;
            }
        }
        return false;
}
bool Leetcode::hasCycle_1(ListNode *head) {//抄
////    执行用时：24 ms, 在所有 C++ 提交中击败了12.74% 的用户
////    内存消耗：9.7 MB, 在所有 C++ 提交中击败了12.25% 的用户
////    方法一：哈希表
//    unordered_set<ListNode*> seen;
//    while (head != nullptr) {
//        if (seen.count(head)) {
//            return true;
//        }
//        seen.insert(head);
//        head = head->next;
//    }
//    return false;

//    执行用时：12 ms, 在所有 C++ 提交中击败了65.52% 的用户
//    内存消耗：7.5 MB, 在所有 C++ 提交中击败了47.87% 的用户
//    方法二：快慢指针
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
}
//142. 环形链表 II
/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
说明：不允许修改给定的链表。

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：
输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：
输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

进阶：
你是否可以不用额外空间解决此题？
 */
ListNode *Leetcode::detectCycle(ListNode *head) {//2020-10-10
////    执行用时：40 ms, 在所有 C++ 提交中击败了7.05% 的用户
////    内存消耗：9.9 MB, 在所有 C++ 提交中击败了6.94% 的用户
//        auto head1 = head;
//        set<ListNode *> ss;
//        while (head1 != nullptr) {
//            auto pos = ss.find(head1);
//            if (pos != ss.end()) {
//                return head1;
//            } else {
//                ss.insert(head1);
//                head1 = head1->next;
//            }
//        }
//        return nullptr;
//    执行用时：8 ms, 在所有 C++ 提交中击败了95.94% 的用户
//    内存消耗：7.3 MB, 在所有 C++ 提交中击败了90.01%
//    参考
/*
 * l1入环后走一圈的距离等于l2入环后走2圈的距离，所以必定在第一圈相遇（l1与l2对应的位置恒固定）
 * l1与l2第一次相遇后再走非环长度就到环的末尾
 *
 * 设非环长度为a 相遇走过长度为b 剩余长度为c
 * 由题意得:
 * l1走过长度为:a+b
 * l2走过长度为:a+n(b+c)+b
 * l2的速度为l1的两倍
 * b+c为一个环
 * 解:
 * 因为l2的速度为l1的两倍,所以l2走过长度也为2(a+b)
 * 所以由l2走过的路程得到 a+n(b+c)+b=2(a+b) => a=nb-b+nc
 * 因为b+c为一个环,所以b+c=0 => b=-c
 * 所以a=nb-b+nc => a=-nc+c+nc => a=c
 * 因为l1与l2在b相遇，那么想获得起点位置就需要再走c的长度
 * 因为a=c,所以需要l3从起点开始，与l1同事往后走，走过a的距离后l1与l3相遇
 * 所以获得了开始的位置
 */
        ListNode *l1 = head, *l2 = head;
        while (l2 != nullptr) {//l2为快指针 先遇到nullptr
            if (l2->next == nullptr)//l2为快指针，所以会出现下一个指向为空的情况
                return nullptr;
            l1 = l1->next;//l1为慢指针
            l2 = l2->next->next;//l2为快指针
            if (l1 == l2) {//第一次相遇(确定有环)
                ListNode *l3 = head;//l3为慢指针
                while (l1 != l3) {//循环非环的长度，l3第一次入环l1必走到第一个位置
                    l1 = l1->next;
                    l3 = l3->next;
                }
                return l3;
            }
        }
        return nullptr;
}
ListNode *Leetcode::detectCycle_1(ListNode *head){//抄
//    执行用时：8 ms, 在所有 C++ 提交中击败了95.94% 的用户
//    内存消耗：7.4 MB, 在所有 C++ 提交中击败了70.21% 的用户
    ListNode *slow = head, *fast = head;
    while (fast != nullptr) {
        slow = slow->next;
        if (fast->next == nullptr) {
            return nullptr;
        }
        fast = fast->next->next;
        if (fast == slow) {
            ListNode *ptr = head;
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return nullptr;
}
//143. 重排链表
/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:
给定链表 1->2->3->4, 重新排列为 1->4->2->3.

示例 2:
给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 */
void Leetcode::reorderList(ListNode* head) {//2020-10-20
////    执行用时：64 ms, 在所有 C++ 提交中击败了34.59% 的用户
////    内存消耗：18.5 MB, 在所有 C++ 提交中击败了7.11% 的用户
//        if (!head)
//            return;
//        stack<ListNode *> stack1;
//        ListNode *head1 = head;
//        while (head1) {
//            stack1.push(head1);
//            head1 = head1->next;
//        }
//        int size = stack1.size();
//        for (int i = 0; i < size / 2; ++i) {
//            head1 = head->next;
//            head->next = stack1.top();
//            head->next->next = head1;
//            head = head->next->next;
//            stack1.pop();
//        }
//        head->next = nullptr;

    if (!head)
        return;
    stack<ListNode *> stack1;
    ListNode *head1 = head;
    ListNode *head2 = head->next;
    while (head2) {
        stack1.push(head1);
        head1 = head1->next;
    }
    int size = stack1.size();
    for (int i = 0; i < size / 2; ++i) {
        head1 = head->next;
        head->next = stack1.top();
        head->next->next = head1;
        head = head->next->next;
        stack1.pop();
    }
    head->next = nullptr;
}
void reorderList_1(ListNode* head) {//抄
////    执行用时：72 ms, 在所有 C++ 提交中击败了27.00% 的用户
////    内存消耗：18.9 MB, 在所有 C++ 提交中击败了5.05% 的用户
////    方法一：线性表
//    if (head == nullptr) {
//        return;
//    }
//    vector<ListNode *> vec;
//    ListNode *node = head;
//    while (node != nullptr) {
//        vec.emplace_back(node);
//        node = node->next;
//    }
//    int i = 0, j = vec.size() - 1;
//    while (i < j) {
//        vec[i]->next = vec[j];
//        i++;
//        if (i == j) {
//            break;
//        }
//        vec[j]->next = vec[i];
//        j--;
//    }
//    vec[i]->next = nullptr;

////    执行用时：800 ms, 在所有 C++ 提交中击败了5.08% 的用户
////    内存消耗：17.9 MB, 在所有 C++ 提交中击败了10.77% 的用户
////    递归
//    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)return;
//    ListNode *temp = head;
//    while (temp->next->next != nullptr)
//        temp = temp->next;
//    temp->next->next = head->next;
//    head->next = temp->next;
//    temp->next = nullptr;
//    reorderList_1(head->next->next);

//    执行用时：72 ms, 在所有 C++ 提交中击败了27.00% 的用户
//    内存消耗：17.7 MB, 在所有 C++ 提交中击败了12.76% 的用户
    ListNode* p=head,*q=head,*r,*s=head;
    if(!head)            //head为空，则直接退出
        return ;
    //1.快慢指针获取中间节点 p慢指针 q快指针 最终p为前半链表末尾 q为后半链表开始
    while(q->next){      //寻找中间结点
        q=q->next;       //p走一步
        p=p->next;
        if(q->next)
            q=q->next;     //q走两步
    }
    q=p->next;           //p所指结点为中间结点，q为后半段链表的首结点
    p->next=nullptr;     //p为前半段链表

    //2.链表逆序 r为暂时存放q的下一个值
    while(q){            //将链表后半段逆置
        r=q->next;
        q->next=p->next;
        p->next=q;
        q=r;
    }
    q=p->next;            //q指向后半段的第一个数据结点
    p->next=nullptr;
    //插入
    while(q){             //将链表后半段的结点插入到指定位置
        r=q->next;        //r指向后半段的下一个结点
        q->next=s->next;  //将q所指结点插入到s所指结点（head结点）之后
        s->next=q;
        s=q->next;        //s指向前半段的下一个插入点
        q=r;
    }
}
//144. 二叉树的前序遍历
/*
给定一个二叉树，返回它的 前序 遍历。
 示例:
输入: [1,null,2,3]
   1
    \
     2
    /
   3
输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 */
void TreeNode_DLR(TreeNode* root,vector<int>& ans){
    if (root == nullptr)
        return;
    ans.push_back(root->val);
    TreeNode_DLR(root->left,ans);
    TreeNode_DLR(root->right,ans);
}
vector<int> Leetcode::preorderTraversal(TreeNode* root) {//2020-10-27
////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：8.6 MB, 在所有 C++ 提交中击败了17.23% 的用户
////    递归
//    vector<int> ans;
//    TreeNode_DLR(root,ans);
//    return ans;

////    执行用时：4 ms, 在所有 C++ 提交中击败了48.52% 的用户
////    内存消耗：10.2 MB, 在所有 C++ 提交中击败了6.56% 的用户
////    递归
//    if (root == nullptr)
//        return {};
//    vector<int> ans, left, right;
//    ans.push_back(root->val);
//    left = preorderTraversal(root->left);
//    ans.insert(ans.end(),left.begin(),left.end());
//    right = preorderTraversal(root->right);
//    ans.insert(ans.end(),right.begin(),right.end());
//    return ans;

//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：8.4 MB, 在所有 C++ 提交中击败了46.67% 的用户
//    迭代
    if (root == nullptr)
        return {};
    vector<int> ans;
    stack<TreeNode *> stack1;
    stack1.push(root);
    while (!stack1.empty()) {
        TreeNode *tree = stack1.top();
        stack1.pop();
        ans.push_back(tree->val);
        if (tree->right)
            stack1.push(tree->right);
        if (tree->left)
            stack1.push(tree->left);
    }
    return ans;
}
//145. 二叉树的后序遍历
/*
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [3,2,1]

进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 */
void TreeNode_LRD(TreeNode* root,vector<int>& ans) {//后序遍历递归算法-递归
    if (root == nullptr)
        return;
    TreeNode_LRD(root->left,ans);
    TreeNode_LRD(root->right,ans);
    ans.push_back(root->val);
}
vector<int> Leetcode::postorderTraversal(TreeNode* root) {//递归 2020-09-24
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：8.5 MB, 在所有 C++ 提交中击败了42.25% 的用户
        vector<int>ans;
        TreeNode_LRD(root,ans);
        return  ans;
}
vector<int> Leetcode::postorderTraversal1(TreeNode* root) {//迭代
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：8.3 MB, 在所有 C++ 提交中击败了83.41% 的用户
        vector<int> ans;
        if (root == NULL) return ans;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *top = s.top();
            s.pop();
            ans.push_back(top->val);
            if (top->left) s.push(top->left);
            if (top->right) s.push(top->right);
        }

        ::reverse(ans.begin(), ans.end());//颠倒
        return ans;
}


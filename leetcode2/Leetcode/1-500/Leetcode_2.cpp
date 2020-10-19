#include "../leetcode.h"
//64. 最小路径和
/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。

示例:
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
 */
/*
 * 算出每个点的最短路径
 * 每个点的最短路径等于左边或者上边最短路径加自身
 *
 */
int Leetcode::minPathSum(vector<vector<int>>& grid) {
//    执行用时：12 ms, 在所有 C++ 提交中击败了44.86% 的用户
//    内存消耗：9.2 MB, 在所有 C++ 提交中击败了100.00% 的用户
    int W = grid[0].size();
    int H = grid.size();
    vector<vector<int>> answer(H);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0) {
                if (j == 0) {//左边第一个
//                    cout<<grid[i][j]<<"\t";
                    answer[i].push_back(grid[i][j]);
                } else {//第一行
//                    cout<<answer[i][j-1]+grid[i][j]<<"\t";
                    answer[i].push_back(answer[i][j - 1] + grid[i][j]);
                }
            } else if (j == 0) {//第一列
//                cout<<answer[i-1][j]+grid[i][j]<<"\t";
                answer[i].push_back(answer[i - 1][j] + grid[i][j]);
            } else {
//                cout<<min(answer[i][j-1],answer[i-1][j])+grid[i][j]<<"\t";
                answer[i].push_back(min(answer[i][j - 1], answer[i - 1][j]) + grid[i][j]);
            }
        }
//        cout<<endl;
    }
    return answer[H - 1][W - 1];
}
int Leetcode::minPathSum1(vector<vector<int>>& grid) {
//    执行用时：4 ms, 在所有 C++ 提交中击败了99.22% 的用户
//    内存消耗：8.3 MB, 在所有 C++ 提交中击败了100.00%
        int W = grid[0].size();
        int H = grid.size();
        int answer[H][W];
        answer[0][0] = grid[0][0];//左边第一个
        for (int k = 1; k < W; ++k)answer[0][k] = answer[0][k - 1] + grid[0][k];//第一行
        for (int l = 1; l < H; ++l) answer[l][0] = answer[l - 1][0] + grid[l][0];//第一列
        for (int i = 1; i < H; ++i)
            for (int j = 1; j < W; ++j)
                answer[i][j] = min(answer[i][j - 1], answer[i - 1][j]) + grid[i][j];
        return answer[H - 1][W - 1];
}
//70. 爬楼梯
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。

示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2:
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
 */
int Leetcode::climbStairs1(int n) {//超时
    if (n <= 1)
        return 1;
    if (n <= 2)
        return n;
    else
        return climbStairs1(n - 1) + climbStairs1(n - 2);
}
int Leetcode::climbStairs2(int n) {
    int a = 1;//前2个
    long b = 1;//前1个
    while (n>0) {
        b += a;
        a = b - a;
        n--;
    }
    return a;
}
int Leetcode::climbStairs3(int n) {
    if (n <= 1) return 1;
    vector<int> dp(n);
    dp[0] = 1; dp[1] = 2;
    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp.back();
}
//78. 子集
/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。

示例:
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */
//执行用时 :4 ms, 在所有 cpp 提交中击败了99.85% 的用户
//内存消耗 :9.1 MB, 在所有 cpp 提交中击败了67.75%的用户
vector<vector<int>> Leetcode::subsets(vector<int> &nums) {//nums.begin()+k
    vector<vector<int>> answer;
    vector<int> answer1;
    for (int k = 0; k <= nums.size(); k++) {            //控制输出个数
        subsets1(answer, answer1, nums, k, 0);
    }
    return answer;
}
void Leetcode::subsets1(vector<vector<int>> &answer, vector<int> &answer1, vector<int> &nums, int k, int st) {
    if (k == 0) {
        answer.push_back(answer1);
        return;
    }
    for (int i = st; i < nums.size(); i++) {
        answer1.push_back(nums[i]);
        subsets1(answer, answer1, nums, k - 1, i + 1);
        answer1.pop_back();//删除数组元素
    }
}
//83. 删除排序链表中的重复元素
/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
输入: 1->1->2
输出: 1->2
示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
 */
ListNode* Leetcode::deleteDuplicates(ListNode* head) {
    ListNode* listNow=head;
    while (listNow!= nullptr&&listNow->next!= nullptr){
        if(listNow->val==listNow->next->val){
            listNow->next=listNow->next->next;
        } else
            listNow=listNow->next;
    }
    return head;
}
ListNode* Leetcode::deleteDuplicates1(ListNode* head) {
    if(head == nullptr)
        return nullptr;
    ListNode* listNow=head;
    while (listNow&&listNow->next){
        if(listNow->val==listNow->next->val){
            ListNode* next = listNow->next;
            listNow->next=next->next;
            delete next;
        } else
            listNow=listNow->next;
    }
    return head;
}
//94. 二叉树的中序遍历 2020-09-14
/*
给定一个二叉树，返回它的中序 遍历。//左根右

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 */
void TT94(TreeNode* root,vector<int>& answer) {//递归
    if (!root) {
        return;
    }
    TT94(root->left, answer);
    answer.push_back(root->val);
    TT94(root->right, answer);
}
vector<int> Leetcode::inorderTraversal(TreeNode* root) {
    vector<int> answer;
    TT94(root,answer);
    return answer;
}
vector<int> Leetcode::inorderTraversal1(TreeNode* root) {//迭代 2020-09-24
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：8.5 MB, 在所有 C++ 提交中击败了6.58% 的用户
    vector<int> ans;
    if (root == nullptr)
        return{};
    stack<TreeNode *> st;
    TreeNode *tmp = root;
    while (!st.empty() || tmp) {
        while (tmp) {
            st.push(tmp);
            tmp = tmp->left;
        }
        TreeNode *t = st.top();
        st.pop();
        ans.push_back(t->val);
        tmp = t->right;
    }
    return ans;
}
//95. 不同的二叉搜索树 II
/*
给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

示例：
输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
提示：
    0 <= n <= 8
 */
/*
 * 跟节点大于左子树所有，小于右子树所有->唯一
 * 1-i 左子树
 * i-n 右子树
 */
vector<TreeNode*> Leetcode::generateTrees(int n) {
    if(!n){
        return {};//不包含元素
    }
    return generateTrees(1,n);
}
vector<TreeNode*> Leetcode::generateTrees(int begin,int end) {
    if (begin > end)
        return {nullptr};//包含一个空元素
    vector<TreeNode *> allTrees;
    for (int i = begin; i <= end; ++i) {
        vector<TreeNode *> left = generateTrees(begin, i - 1);
        vector<TreeNode *> right = generateTrees(i + 1, end);
        for (auto &left : left)
            for (auto &right : right)
                allTrees.emplace_back(new TreeNode(i, left, right));
    }
    return allTrees;
}
//96. 不同的二叉搜索树
/*
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:
输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */
int Leetcode::numTrees(int n) {

    if(n<=0)return 1;
    vector<int> aa(n+1,0);
    aa[0]=1;
    for (int i = 1; i < n+1; ++i) {
        //更快
        for (int j = 0; j < i; ++j) {
            aa[i]+=aa[j]*aa[i-1-j];
        }
        //慢
//        int size=i/2;
//        if(i%2!=0)
//            size++;
//        for (int j = 0; j < size; ++j) {
//            int bb=aa[j]*aa[i-1-j];
//            if(j==size-1&&i%2!=0)
//                aa[i] += bb;
//            else
//                aa[i]+=bb*2;
//        }
    }
    return aa[n];
}
int Leetcode::numTrees1(int n) {//递归
    if (n == 0 || n == 1) return 1;
    int num = 0;
    int size=n/2;
    if(n%2!=0)
        size++;
    for (int i = 0; i < size; ++i) {
        int aa=numTrees1(i) * numTrees1(n - i - 1);
        if(i==size-1&&n%2!=0)
            num += aa;
        else
            num+=aa*2;
    }
    return num;
}
//100. 相同的树
/*
给定两个二叉树，编写一个函数来检验它们是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:
输入:       1         1
          / \       / \
         2   3     2   3
        [1,2,3],   [1,2,3]
输出: true
示例 2:
输入:      1          1
          /           \
         2             2
        [1,2],     [1,null,2]
输出: false
示例 3:
输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]
输出: false
 */
bool Leetcode::isSameTree(TreeNode* p, TreeNode* q) {//递归
    if(p!= nullptr&&q!= nullptr){//都存在
        if(p->val!=q->val)
            return false;
        else
            return isSameTree(p->right,q->right)&&isSameTree(p->left,q->left);
    }else{
        return p == nullptr && q == nullptr;
    }
}



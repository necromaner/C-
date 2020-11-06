#include "../leetcode.h"
//763. 划分字母区间
/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

示例 1：
输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

提示：
    S的长度在[1, 500]之间。
    S只包含小写字母 'a' 到 'z' 。
 */
vector<int> Leetcode::partitionLabels(string S) {//2020-10-22
////    超出时间限制
//    int size = S.size(), head = 0, end = 0;
//    if (size == 0)
//        return {};
//    vector<int> ans;
//    vector<vector<int>> aaa(26, vector<int>(2, -1));
//    for (int i = 0; i < size; ++i) {
//        int aa = S[i] - 'a';
//        if (aaa[aa][0] == -1)
//            aaa[aa][0] = i;
//        else
//            aaa[aa][1] = i;
//    }
//    end = aaa[S[0] - 'a'][1];
//    while (head < size) {
//        if (end == -1) {
//            aaa[S[head] - 'a'][0] = -1;
//            ans.push_back(1);
//        } else {
//            bool isOK = true;
//            for (int i = 0; i < 26; ++i) {
//                int now = aaa[i][0];
//                if (now == -1)
//                    continue;
//                else if (now <= end) {
//                    aaa[i][0] = -1;
//                    int nowEnd = aaa[i][1];
//                    end = max(end, aaa[i][1]);
//                    isOK = false;
//                }
//            }
//            if (isOK) {
//                ans.push_back(end - head + 1);
//                head = end + 1;
//                if (head < size)
//                    end = aaa[S[head] - 'a'][1];
//            }
//        }
//    }
//    return ans;

//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.8 MB, 在所有 C++ 提交中击败了39.44% 的用户
//    参考
    int size = S.size(), head = 0, end = 0;
    vector<int> ans;
    int aaa[26];
    for (int i = 0; i < size; ++i)
        aaa[S[i] - 'a'] = i;
    while (head < size) {
        end = aaa[S[head] - 'a'];
        for (int i = head + 1; i < end; ++i)
            end = max(end, aaa[S[i] - 'a']);
        ans.push_back(end - head + 1);
        head = end + 1;
    }
    return ans;
}
vector<int> partitionLabels_1(string S){
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.8 MB, 在所有 C++ 提交中击败了33.15% 的用户
    int last[26];
    int length = S.size();
    for (int i = 0; i < length; i++) {
        last[S[i] - 'a'] = i;
    }
    vector<int> partition;
    int start = 0, end = 0;
    for (int i = 0; i < length; i++) {
        end = max(end, last[S[i] - 'a']);
        if (i == end) {
            partition.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return partition;

////    执行用时：8 ms, 在所有 C++ 提交中击败了73.76% 的用户
////    内存消耗：7 MB, 在所有 C++ 提交中击败了14.76% 的用户
//    unordered_map<char, int> umap; // key:字符，value：字符出现的最后位置
//    for (int i = 0; i < S.size(); i++) { // 统计每一个字符最后出现的位置
//        umap[S[i]] = i;
//    }
//    vector<int> result;
//    int left = 0;
//    int right = 0;
//    for (int i = 0; i < S.size(); i++) {
//        right = max(right, umap[S[i]]); // 找到字符出现的最远边界
//        if (i == right) {
//            result.push_back(right - left + 1);
//            left = i + 1;
//        }
//    }
//    return result;
}
//783. 二叉搜索树节点最小距离
/*
给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。

示例：
输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树节点对象(TreeNode object)，而不是数组。
给定的树 [4,2,6,1,3,null,null] 可表示为下图:
          4
        /   \
      2      6
     / \
    1   3
最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。

注意：
    二叉树的大小范围在 2 到 100。
    二叉树总是有效的，每个节点的值都是整数，且不重复。
 */
int Leetcode::minDiffInBST(TreeNode* root) {//2020-10-12
//    执行用时：4 ms, 在所有 C++ 提交中击败了78.52% 的用户
//    内存消耗：9.5 MB, 在所有 C++ 提交中击败了54.27% 的用户
    int ans = INT_MAX, last = 0;
    bool isFirst = true;
    if (root == nullptr)
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
        if (ans > t->val - last) {
            ans = t->val - last;
        }
        last = t->val;
    }
    return ans;
}
int Leetcode::minDiffInBST_1(TreeNode* root){

}
//785. 判断二分图
/*
给定一个无向图graph，当这个图为二分图时返回true。
如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。
graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个在0到graph.length-1之间的整数。这图中没有自环和平行边： graph[i] 中不存在i，并且graph[i]中没有重复的值。

示例 1:
输入: [[1,3], [0,2], [1,3], [0,2]]
输出: true
解释:
无向图如下:
0----1
|    |
|    |
3----2
我们可以将节点分成两组: {0, 2} 和 {1, 3}。
示例 2:
输入: [[1,2,3], [0,2], [0,1,3], [0,2]]
输出: false
解释:
无向图如下:
0----1
| \  |
|  \ |
3----2
我们不能将节点分割成两个独立的子集。

注意:
    graph 的长度范围为 [1, 100]。
    graph[i] 中的元素的范围为 [0, graph.length - 1]。
    graph[i] 不会包含 i 或者有重复的值。
    图是无向的: 如果j 在 graph[i]里边, 那么 i 也会在 graph[j]里边。
 */
/*
整个图里面有编号为0 ~ n-1的结点，graph[i] 表示第i个节点跟哪些节点相连。 示例 1: 输入: [[1,3], [0,2], [1,3], [0,2]] graph[0] = { 1, 3 }, 0号节点跟 1、3结点相连
 0.遍历所有
 1.给编号上色
 2.遍历编号里的
 */
bool Leetcode::isBipartite(vector<vector<int>>& graph) {
    int size = graph.size();
    vector<int> visited(size, 0);
    for (int i = 0; i < size; ++i) {
        if (visited[i] != 0)continue;//染过色
        else visited[i] = 1;//染色
        priority_queue<int> queue;//存放相连节点
        queue.push(i);
        while (queue.size()) {//遍历相邻节点
            int cur = queue.top();//遍历该节点
            queue.pop();
            int neighborColor = -visited[cur];     // 它的相邻顶点应该有的颜色
            for (int j = 0; j < graph[cur].size(); ++j) {
                int neighbor = graph[cur][j];//
                if (!visited[neighbor]) {//未染过色
                    visited[neighbor] = neighborColor;//染色
                    queue.push(neighbor);  //入栈
                } else if (visited[neighbor] != neighborColor) {
                    return false;
                }
            }
        }
    }
    return true;
}


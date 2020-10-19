#include "../leetcode.h"

//968. 监控二叉树
/*
给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。



示例 1：

输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。

示例 2：

输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。


提示：

给定树的节点数的范围是 [1, 1000]。
每个节点的值都是 0。
 */
struct Status {
    int a, b, c;
};
Status T968_dfs(TreeNode* root) {//2020-09-22 抄
//    状态 a：root必须放置摄像头的情况下，覆盖整棵树需要的摄像头数目。
//    状态 b：覆盖整棵树需要的摄像头数目，无论 root是否放置摄像头。
//    状态 c：覆盖两棵子树需要的摄像头数目，无论节点 root本身是否被监控到。

    if (!root) {
        return {INT_MAX / 2, 0, 0};
    }
    auto [la, lb, lc] = T968_dfs(root->left);
    auto [ra, rb, rc] = T968_dfs(root->right);
    int a = lc + rc + 1;
    int b = min(a, min(la + rb, ra + lb));
    int c = min(a, lb + rb);
    return {a, b, c};
}
int Leetcode::minCameraCover(TreeNode* root) {
    auto [a, b, c] = T968_dfs(root);
    return b;
}
//977. 有序数组的平方
/*
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

示例 1：
输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]

示例 2：
输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]

提示：
    1 <= A.length <= 10000
    -10000 <= A[i] <= 10000
    A 已按非递减顺序排序。
 */
vector<int> Leetcode::sortedSquares(vector<int>& A) {//2020-10-16
//    执行用时：116 ms, 在所有 C++ 提交中击败了42.50% 的用户
//    内存消耗：24.6 MB, 在所有 C++ 提交中击败了41.27% 的用户
        int n = A.size();
        for (int i = 0; i < n; i++) {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end());
        return A;
}
vector<int> sortedSquares_1(vector<int>& A) {//抄
//    执行用时：60 ms, 在所有 C++ 提交中击败了83.76% 的用户
//    内存消耗：25.6 MB, 在所有 C++ 提交中击败了5.02% 的用户
//    方法二：双指针-中间开始
    int n = A.size();
    int negative = -1;//最后一个小于0位置
    for (int i = 0; i < n; ++i)//寻找最后一个小于0位置
        if(A[i] >= 0){
            negative = i-1;
            break;
        }
//        if (A[i] < 0)
//            negative = i;
//        else
//            break;
    vector<int> ans;
    int i = negative, j = negative + 1;//i最小的负数 j最小的正数
    while (i >= 0 || j < n) {
        if (i < 0) {//全为正数
            ans.push_back(A[j] * A[j]);
            ++j;
        } else if (j == n) {//全为负数
            ans.push_back(A[i] * A[i]);
            --i;
        } else if (A[i] * A[i] < A[j] * A[j]) {//前面平方大于后面
            ans.push_back(A[i] * A[i]);
            --i;
        } else {//后面平方大于前面
            ans.push_back(A[j] * A[j]);
            ++j;
        }
    }
    return ans;

////    执行用时：64 ms, 在所有 C++ 提交中击败了72.87% 的用户
////    内存消耗：25.4 MB, 在所有 C++ 提交中击败了14.06% 的用户
////    双指针-两侧开始
//    vector<int> ans;
//    for (int i = 0, j = A.size() - 1; i <= j; i++) {
//        while (i < j && abs(A[i]) < abs(A[j])) {
//            ans.push_back(A[j] * A[j]);
//            j--;
//        }
//        ans.push_back(A[i] * A[i]);
//    }
//    reverse(ans.begin(), ans.end());
//    return ans;
}
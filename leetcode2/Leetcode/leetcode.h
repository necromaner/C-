//
// Created by necromaner on 2020/7/22.
//

#ifndef LEETCODE2_LEETCODE_H
#define LEETCODE2_LEETCODE_H

#include "../Other/MyStack.h"
#include "../Other/TreeNode.h"
#include "../Other/ListNode.h"
#include "../Other/Node.h"
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm> //reverse
#include <stack>//栈
#include <queue>

#include<numeric> //int sum =accumulate vector求和 accumulate(nums.begin(), nums.end(), 0);
using namespace std;




class Leetcode {
private:
public:
    ////-----------------------------   1- 500-----------------------------////
    //-------------------------------   1-  50-------------------------------// 1
    vector<int> twoSum(vector<int>& nums, int target);                       //1. 两数之和
    vector<int> twoSum_2(vector<int>& nums, int target);
    vector<int> twoSum_1(vector<int>& nums, int target);
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);                     //2. 两数相加
    ListNode* addTwoNumbers_1(ListNode* l1, ListNode* l2);
    int lengthOfLongestSubstring(string s);                                  //3. 无重复字符的最长子串
    int lengthOfLongestSubstring_1(string s);
    int T3_aaa(string s,set<char> *aa,int p);
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);   //4. 寻找两个正序数组的中位数
    int T4_aaa(vector<int>& nums1, vector<int>& nums2,int num);
    string longestPalindrome(string s);                                      //5. 最长回文子串
    string convert(string s, int numRows);                                   //6. Z 字形变换
    int reverse(int x);                                                      //7. 整数反转
    int reverse1(int x);
    int reverse2(int x);
    int myAtoi(string str);                                                  //8. 字符串转换整数 (atoi)
    int myAtoi_1(string str);
    bool isPalindrome(int x);                                                //9. 回文数
    bool isPalindrome_1(int x);
    bool isMatch(string s, string p);                                        //10. 正则表达式匹配
    bool isMatch_1(string s, string p);
    int maxArea(vector<int>& height);                                        //11. 盛最多水的容器
    string intToRoman(int num);                                              //12. 整数转罗马数字
    string intToRoman_1(int num);
    int romanToInt(string s);                                                //13. 罗马数字转整数
    int romanToInt_1(string s);
    string longestCommonPrefix(vector<string>& strs);                        //14. 最长公共前缀
    string longestCommonPrefix_1(vector<string>& strs);
    vector<vector<int>> threeSum(vector<int> &nums);                         //15. 三数之和
    vector<vector<int>> threeSum_1(vector<int> &nums);
    void threeSum1(vector<int> &nums,vector<vector<int>> &answer,vector<int> &answer1,int i,int j,int k);
    vector<vector<int>> threeSum_2(vector<int> &nums);
    int threeSumClosest(vector<int>& nums, int target);                      //16. 最接近的三数之和
    int threeSumClosest_1(vector<int>& nums, int target);
    vector<string> letterCombinations(string digits);                        //17. 电话号码的字母组合
    vector<string> letterCombinations_1(string digits);
    vector<vector<int>> fourSum(vector<int>& nums, int target);              //18. 四数之和
    vector<vector<int>> fourSum_1(vector<int>& nums, int target);
    ListNode* removeNthFromEnd(ListNode* head, int n);                       //19. 删除链表的倒数第N个节点
    ListNode* removeNthFromEnd_1(ListNode* head, int n);
    bool isValid(string s);                                                  //20. 有效的括号
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);                     //21. 合并两个有序链表
    vector<string> generateParenthesis(int n);                               //22. 括号生成
    ListNode* swapPairs(ListNode* head);                                     //24. 两两交换链表中的节点
    ListNode* swapPairs_1(ListNode* head);
    int removeDuplicates(vector<int> &nums);                                 //26. 删除排序数组中的重复项
    int removeElement(vector<int> &nums, int val);                           //27. 移除元素
    vector<int> searchRange(vector<int> &nums, int target);                  //34. 在排序数组中查找元素的第一个和最后一个位置
    int searchInsert(vector<int>& nums, int target);                         //35. 搜索插入位置
    int searchInsert_1(vector<int>& nums, int target);                       //35. 搜索插入位置
    bool T37_line[9][9];//存储每行存在数字
    bool T37_column[9][9];//存储每列存在数字
    bool T37_block[3][3][9];//存储每个小方块存在数字
    bool T37_valid;//结束标识符
    vector<pair<int, int>> T37_spaces;//存储没有数据坐标
    void T37_dfs(vector<vector<char>>& board, int pos);
    void solveSudoku(vector<vector<char>>& board);                           //37. 解数独
    string countAndSay(int n);                                               //38. 报数
    void countAndSay1(string &answer);                                       //38. 报数
    //-------------------------------  51- 100-------------------------------// 2
    int minPathSum(vector<vector<int>>& grid);                               //64. 最小路径和
    int minPathSum1(vector<vector<int>>& grid);                              //64. 最小路径和
    int climbStairs1(int n);                                                 //70. 爬楼梯
    int climbStairs2(int n);                                                 //70. 爬楼梯
    int climbStairs3(int n);                                                 //70. 爬楼梯
    vector<vector<int>> subsets(vector<int> &nums);                          //78. 子集
    void subsets1(vector<vector<int>> &answer, vector<int> &answer1, vector<int> &nums, int k, int st);//78. 子集
    ListNode* deleteDuplicates(ListNode* head);                              //83. 删除排序链表中的重复元素
    ListNode* deleteDuplicates1(ListNode* head);
    vector<int> inorderTraversal(TreeNode* root);                            //94. 二叉树的中序遍历
    vector<int> inorderTraversal1(TreeNode* root);
    vector<TreeNode*> generateTrees(int n);                                  //95. 不同的二叉搜索树 II
    vector<TreeNode*> generateTrees(int begin,int end);
    int numTrees(int n);                                                     //96. 不同的二叉搜索树
    int numTrees1(int n);
    bool isSameTree(TreeNode* p, TreeNode* q);                               //100. 相同的树
    //------------------------------- 101- 150-------------------------------// 3
    bool isSymmetric(TreeNode* root);                                        //101. 对称二叉树
    int maxDepth(TreeNode* root);                                            //104. 二叉树的最大深度
    int maxDepth1(TreeNode* root);
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);       //106. 从中序与后序遍历序列构造二叉树
    vector<vector<int>> pathSum(TreeNode* root, int sum);                    //113. 路径总和 II
    Node* connect_116(Node* root);                                           //116. 填充每个节点的下一个右侧节点指针 II
    Node* connect(Node* root);                                               //117. 填充每个节点的下一个右侧节点指针 II
    Node* connect1(Node* root);
    int minimumTotal(vector<vector<int>> &triangle);                         //120. 三角形最小路径和
    void minimumTotal1(vector<vector<int>> triangle,vector<vector<int>> &xx, int &aa, int i, int j);//120. 三角形最小路径和
    bool hasCycle(ListNode *head);                                           //141. 环形链表
    bool hasCycle_1(ListNode *head);
    ListNode *detectCycle(ListNode *head);                                   //142. 环形链表 II
    ListNode *detectCycle_1(ListNode *head);
    vector<int> postorderTraversal(TreeNode* root);                          //145. 二叉树的后序遍历
    vector<int> postorderTraversal1(TreeNode* root);
    //------------------------------- 151- 200-------------------------------// 4
    int findMin(vector<int>& nums);                                          //154. 寻找旋转排序数组中的最小值 II
    vector<int> twoSum1(vector<int>& numbers, int target);                   //167. 两数之和 II - 输入有序数组
    vector<int> twoSum2(vector<int>& numbers, int target);                   //167. 两数之和 II - 输入有序数组
    //------------------------------- 201- 250-------------------------------// 5
    MyStack *T225;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);//235. 二叉搜索树的最近公共祖先
    //------------------------------- 251- 300-------------------------------// 6
    void moveZeroes(vector<int>& nums);                                      //283. 移动零
    void gameOfLife(vector<vector<int>>& board);                             //289. 生命游戏
    //------------------------------- 301- 350-------------------------------// 7
    //------------------------------- 351- 400-------------------------------// 8
    //------------------------------- 401- 450-------------------------------// 9
    bool canPartition(vector<int>& nums);                                    //416. 分割等和子集
    bool canPartition_1(vector<int>& nums);
    //------------------------------- 451- 500-------------------------------// 10
    ////----------------------------- 501-1000-----------------------------////
    //------------------------------- 501- 550-------------------------------// 11
    vector<int> findMode(TreeNode* root);                                    //501. 二叉搜索树中的众数
    int T538_num = 0;
    int getMinimumDifference(TreeNode* root);                                //530. 二叉搜索树的最小绝对差
    int getMinimumDifference_1(TreeNode* root);
    TreeNode* convertBST(TreeNode* root);                                    //538. 把二叉搜索树转换为累加树
    //------------------------------- 551- 600-------------------------------// 12
    //------------------------------- 601- 650-------------------------------// 13
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);                        //617. 合并二叉树
    TreeNode* mergeTrees_1(TreeNode* t1, TreeNode* t2);
    //------------------------------- 651- 700-------------------------------// 14
    //------------------------------- 701- 750-------------------------------// 15
    TreeNode* insertIntoBST(TreeNode* root, int val);                        //701. 二叉搜索树中的插入操作
    //------------------------------- 751- 800-------------------------------// 16
    int minDiffInBST(TreeNode* root);                                        //783. 二叉搜索树节点最小距离
    int minDiffInBST_1(TreeNode* root);
    bool isBipartite(vector<vector<int>>& graph);                            //785. 判断二分图
    //------------------------------- 801- 850-------------------------------// 17
    //------------------------------- 851- 900-------------------------------// 18
    //------------------------------- 901- 950-------------------------------// 19
    //------------------------------- 951-1000-------------------------------// 20
    int minCameraCover(TreeNode* root);                                      //968. 监控二叉树
    vector<int> sortedSquares(vector<int>& A);                               //977. 有序数组的平方
    ////-----------------------------1001-1500-----------------------------////
    //-------------------------------1001-1050-------------------------------// 21
    vector<string> commonChars(vector<string>& A);                           //1002. 查找常用字符
    bool divisorGame(int N);                                                 //1025. 除数博弈
    //-------------------------------1051-1100-------------------------------// 22
    //-------------------------------1101-1150-------------------------------// 23
    //-------------------------------1151-1200-------------------------------// 24
    //-------------------------------1201-1250-------------------------------// 25
    //-------------------------------1251-1300-------------------------------// 26
    //-------------------------------1301-1350-------------------------------// 27
    //-------------------------------1351-1400-------------------------------// 28
    //-------------------------------1401-1450-------------------------------// 29
    //-------------------------------1451-1500-------------------------------// 30
    ////-----------------------------1501-2000-----------------------------////
    //-------------------------------1501-1550-------------------------------// 31

};

#endif                                                                       //LEETCODE2_LEETCODE_H

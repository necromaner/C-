#include "CTCI.h"
//面试题 01.01. 判定字符是否唯一
/*
实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

示例 1：
输入: s = "leetcode"
输出: false
示例 2：
输入: s = "abc"
输出: true
限制：
    0 <= len(s) <= 100
    如果你不使用额外的数据结构，会很加分。
 */
bool CTCI::isUnique(string astr) {//2020-10-27
////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：6.3 MB, 在所有 C++ 提交中击败了5.28% 的用户
//    vector<bool> aa(256,false);
//    for(auto c:astr)
//        if(aa[c])
//            return false;
//        else
//            aa[c]=true;
//    return true;

////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：6.1 MB, 在所有 C++ 提交中击败了37.94% 的用户
//    int size=astr.size();
//    for (int i = 0; i < size-1; ++i) {
//        char aa=astr[i];
//        for (int j = i+1; j < size; ++j)
//            if(aa==astr[j])
//                return false;
//    }
//    return true;

//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.2 MB, 在所有 C++ 提交中击败了5.85% 的用户
    unordered_set<char> set;
    for (auto c:astr)
        if (set.find(c) != set.end())
            return false;
        else
            set.insert(c);
    return true;
}
bool isUnique_1(string astr){//抄
////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：6.2 MB, 在所有 C++ 提交中击败了12.98% 的用户
////    map
//    unordered_map<char, int> strs;
//    for(int i = 0; i < astr.size(); i ++){
//        if(strs[astr[i]]) return false;
//        strs[astr[i]] ++;
//    }
//    return true;

////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：6.2 MB, 在所有 C++ 提交中击败了16.89% 的用户
////    set
//    unordered_set<char> strs;
//    for(int i = 0; i < astr.size(); i ++){
//        strs.insert(astr[i]);
//    }
//    return astr.size() == strs.size();

//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.2 MB, 在所有 C++ 提交中击败了11.44% 的用户
//    排序
    sort(astr.begin(), astr.end());
    for(int i = 1; i < astr.size(); i ++){
        if(astr[i] == astr[i - 1]) return false;
    }
    return true;

}
//面试题 01.02. 判定是否互为字符重排
/*
给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

示例 1：
输入: s1 = "abc", s2 = "bca"
输出: true
示例 2：
输入: s1 = "abc", s2 = "bad"
输出: false
说明：
    0 <= len(s1) <= 100
    0 <= len(s2) <= 100
 */
bool CTCI::CheckPermutation(string s1, string s2) {//2020-10-27
////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：6.2 MB, 在所有 C++ 提交中击败了16.32% 的用户
//    int size = s1.size();
//    if (size != s2.size())
//        return false;
//    vector<int> aa(256, 0);
//    for (int i = 0; i < size; ++i) {
//        aa[s1[i]]++;
//        aa[s2[i]]--;
//    }
//    for (auto j:aa)
//        if (j != 0)
//            return false;
//    return true;

//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.2 MB, 在所有 C++ 提交中击败了29.28% 的用户
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1==s2;
}
//面试题 01.03. URL化
/*
URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）

示例1:
 输入："Mr John Smith    ", 13
 输出："Mr%20John%20Smith"
示例2:
 输入："               ", 5
 输出："%20%20%20%20%20"
提示：
    字符串长度在[0, 500000]范围内。
 */
string CTCI::replaceSpaces(string S, int length) {//2020-10-27
//    执行用时：36 ms, 在所有 C++ 提交中击败了99.68% 的用户
//    内存消耗：25.4 MB, 在所有 C++ 提交中击败了5.66% 的用户
    string ans;
    for (int i = 0; i < length; ++i) {
        if(S[i]==' ')
            ans+="%20";
        else
            ans+=S[i];
    }
    return ans;
}
string replaceSpaces_1(string S, int length) {//抄
////    执行用时：44 ms, 在所有 C++ 提交中击败了98.45% 的用户
////    内存消耗：20.3 MB, 在所有 C++ 提交中击败了80.05% 的用户
//    if (S.empty()) return S;
//    int cnt = 0;
//    for (int i = 0; i < length; ++i) {
//        if (S[i] == ' ') ++cnt;
//    }
//    int newLen = length + cnt * 2, j = newLen - 1;
//    for (int i = length - 1; i >= 0 && i != j; --i) {
//        if (S[i] == ' ') {
//            S[j--] = '0';
//            S[j--] = '2';
//            S[j--] = '%';
//        } else {
//            S[j--] = S[i];
//        }
//    }
//    S[newLen] = '\0';
//    return S;

//    执行用时：40 ms, 在所有 C++ 提交中击败了99.30% 的用户
//    内存消耗：21.8 MB, 在所有 C++ 提交中击败了68.25% 的用户
    int i = length - 1;
    int j = S.size() - 1;
    while(i >= 0) {
        if (S[i] == ' ') {
            S[j--] = '0';
            S[j--] = '2';
            S[j--] = '%';
            i--;
        } else {
            S[j--] = S[i--];
        }
    }
    return S.substr(j+1);
}
//面试题 01.04. 回文排列
/*
给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
回文串不一定是字典当中的单词。

示例1：
输入："tactcoa"
输出：true（排列有"tacocat"、"atcocta"，等等）
 */
bool CTCI::canPermutePalindrome(string s) {//2020-10-27
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.4 MB, 在所有 C++ 提交中击败了15.91% 的用户
    vector<bool> aa(256, false);
    bool isOne = true;
    for (auto c:s)
        aa[c] = !aa[c];
    for (auto i:aa) {
        if (i) {
            if (isOne) {
                isOne = false;
            } else {
                return false;
            }
        }
    }
    return true;
////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：6.4 MB, 在所有 C++ 提交中击败了15.91% 的用户
//    vector<int> aa(128, 0);
//    bool isOne = true;
//    for (auto c:s)
//        aa[c] ++;
//    for (auto i:aa) {
//        if (i%2==1) {
//            if (isOne) {
//                isOne = false;
//            } else {
//                return false;
//            }
//        }
//    }
//    return true;
}
bool canPermutePalindrome_1(string s) {//抄
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.4 MB, 在所有 C++ 提交中击败了8.39% 的用户
/*
偶数次出现次数对应的bit为0，奇数次则为1
最后只需要统计bitset中1的个数是否是0或1即可。
建议大家学习一下bitset，用起来很方便。
*/
    bitset<128> bits;
    for (char c : s) {
        bits.flip(c);
    }
    return bits.none() || bits.count() == 1;

////    执行用时：4 ms, 在所有 C++ 提交中击败了39.88% 的用户
////    内存消耗：6.2 MB, 在所有 C++ 提交中击败了39.98% 的用户
//    vector<int> hash(256, 0);
//    for (auto c : s) {
//        ++hash[c];
//    }
//    int cnt = 0;
//    for (int i = 0; i < hash.size(); ++i) {
//        if (hash[i] % 2 == 1) ++cnt;
//    }
//    return cnt <= 1;
}
//面试题 01.05. 一次编辑
/*
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

示例 1:
输入:
first = "pale"
second = "ple"
输出: True
示例 2:
输入:
first = "pales"
second = "pal"
输出: False
 */
bool CTCI::oneEditAway(string first, string second) {
    int size1 = first.size(), size2 = second.size();
    if (abs(size1 - size2) > 1)
        return false;
    if (size2 > size1) {//保证first为最长的
        string bb = first;
        first = second;
        second = bb;
    }
    return false;
}
//面试题 01.06. 字符串压缩
/*
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:
 输入："aabcccccaaa"
 输出："a2b1c5a3"
示例2:
 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
提示：
    字符串长度在[0, 50000]范围内。
 */
string CTCI::compressString(string S) {
    return "";
}
//面试题 01.07. 旋转矩阵
/*
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
不占用额外内存空间能否做到？

示例 1:
给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

示例 2:
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],
原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
 */
void CTCI::rotate(vector<vector<int>>& matrix) {

}
//面试题 01.08. 零矩阵
/*
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

示例 1：
输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2：
输入：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
 */
void CTCI::setZeroes(vector<vector<int>>& matrix) {

}
//面试题 01.09. 字符串轮转
/*
字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。

 示例1:
 输入：s1 = "waterbottle", s2 = "erbottlewat"
 输出：True
示例2:
 输入：s1 = "aa", s2 = "aba"
 输出：False

提示：
    字符串长度在[0, 100000]范围内。
说明:
    你能只调用一次检查子串的方法吗？
 */
bool CTCI::isFlipedString(string s1, string s2) {
    return false;
}

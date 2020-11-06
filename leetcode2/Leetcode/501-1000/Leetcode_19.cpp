#include "../leetcode.h"

//925. 长按键入
/*
你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

示例 1：
输入：name = "alex", typed = "aaleex"
输出：true
解释：'alex' 中的 'a' 和 'e' 被长按。

示例 2：
输入：name = "saeed", typed = "ssaaedd"
输出：false
解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。

示例 3：
输入：name = "leelee", typed = "lleeelee"
输出：true

示例 4：
输入：name = "laiden", typed = "laiden"
输出：true
解释：长按名字中的字符并不是必要的。

提示：
    name.length <= 1000
    typed.length <= 1000
    name 和 typed 的字符都是小写字母。
 */
bool Leetcode::isLongPressedName(string name, string typed) {//2020-10-21
////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：6.3 MB, 在所有 C++ 提交中击败了43.10% 的用户
//        int size1 = name.size() - 1, size2 = typed.size() - 1;
//        char last = '0';
//        while (size1 >= 0 || size2 >= 0) {
//            if (size1 >= 0 && size2 < 0)
//                return false;
//            else if (size1 >= 0 && name[size1] == typed[size2]) {
//                last = name[size1];
//                size1--;
//                size2--;
//            } else if (last == typed[size2]) {
//                size2--;
//            } else
//                return false;
//        }
//        return true;

//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.4 MB, 在所有 C++ 提交中击败了14.23%
//    参考
        int size1 = name.size() - 1, size2 = typed.size() - 1;
        while (size2 >= 0) {
            if (size1 >= 0 && name[size1] == typed[size2]) {
                size1--;
                size2--;
            } else if (size2 < typed.size() - 1 && typed[size2] == typed[size2 + 1])
                size2--;
            else
                return false;
        }
        return size1 == -1;
}
bool isLongPressedName_1(string name, string typed){
////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：6.3 MB, 在所有 C++ 提交中击败了47.91% 的用户
//    int i = 0, j = 0;//i name的指针 j typed的指针
//    while (j < typed.length()) {
//        if (i < name.length() && name[i] == typed[j]) {
//            i++;
//            j++;
//        } else if (j > 0 && typed[j] == typed[j - 1]) {
//            j++;
//        } else {
//            return false;
//        }
//    }
//    return i == name.length();

//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.6 MB, 在所有 C++ 提交中击败了5.86% 的用户
    int i = 0, j = 0;
    while (i < name.size() && j < typed.size()) {
        if (name[i] == typed[j]) { // 相同则同时向后匹配
            j++; i++;
        } else { // 不相同
            if (j == 0) return false; // 如果是第一位就不相同直接返回false
            while(typed[j] == typed[j - 1]) j++; // j跨越重复项，向后移动
            if (name[i] == typed[j]) { // j跨越重复项之后再次和name[i]匹配
                j++; i++; // 相同则同时向后匹配
            }
            else return false;
        }
    }
    // 说明name没有匹配完，例如 name:"pyplrzzzzdsfa" type:"ppyypllr"
    if (i < name.size()) return false;

    // 说明type没有匹配完，例如 name:"alex" type:"alexxrrrrssda"
    while (j < typed.size()) {
        if (typed[j] == typed[j - 1]) j++;
        else return false;
    }
    return true;
}
//941. 有效的山脉数组
/*
给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。
让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：
    A.length >= 3
    在 0 < i < A.length - 1 条件下，存在 i 使得：
        A[0] < A[1] < ... A[i-1] < A[i]
        A[i] > A[i+1] > ... > A[A.length - 1]

示例 1：
输入：[2,1]
输出：false
示例 2：
输入：[3,5,5]
输出：false
示例 3：
输入：[0,3,2,1]
输出：true

提示：
    0 <= A.length <= 10000
    0 <= A[i] <= 10000
 */
bool Leetcode::validMountainArray(vector<int>& A) {//2020-11-03
////    执行用时：60 ms, 在所有 C++ 提交中击败了81.85% 的用户
////    内存消耗：21.2 MB, 在所有 C++ 提交中击败了5.27% 的用户
//    if (A.size() < 3)
//        return false;
//    int size = A.size(), left = 0, right = size - 1;
//    while (left < right && left < size - 1 && right > 0) {
//        int error = 0;
//        if (A[left] < A[left + 1])
//            left++;
//        else
//            error++;
//        if (A[right] < A[right - 1])
//            right--;
//        else
//            error++;
//        if (error == 2)
//            return false;
//    }
//    return !(left == 0 || left == size - 1);

//    执行用时：52 ms, 在所有 C++ 提交中击败了96.92% 的用户
//    内存消耗：21.1 MB, 在所有 C++ 提交中击败了5.27%
//    参考
    int high = 0, size = A.size() - 1;
    while (high < size && A[high] < A[high + 1]) high++;
    if (high == 0 || high == size) return false;
    while (high < size && A[high] > A[high + 1]) high++;
    return high == size;
}
bool validMountainArray_1(vector<int>& A) {//抄
//    执行用时：56 ms, 在所有 C++ 提交中击败了90.92% 的用户
//    内存消耗：21.1 MB, 在所有 C++ 提交中击败了5.27% 的用户
    int N = A.size(), i = 0;
    while (i + 1 < N && A[i] < A[i + 1])// 递增扫描
        i++;
    if (i == 0 || i == N - 1) // 最高点不能是数组的第一个位置或最后一个位置
        return false;
    while (i + 1 < N && A[i] > A[i + 1]) // 递减扫描
        i++;
    return i == N - 1;

////    执行用时：60 ms, 在所有 C++ 提交中击败了81.85% 的用户
////    内存消耗：21 MB, 在所有 C++ 提交中击败了13.26% 的用户
//    int st = 0;
//    for (int i = 1; i < A.size(); i++) {
//        switch (st) {
//            case 0:
//                if (A[i] <= A[i - 1]) return false;
//                st = 1;
//                break;
//            case 1:
//                if (A[i] == A[i - 1]) return false;
//                if (A[i] < A[i - 1]) {
//                    st = 2;
//                }
//                break;
//            case 2:
//                if (A[i] >= A[i - 1]) return false;
//                break;
//        }
//    }
//    return st == 2;
}


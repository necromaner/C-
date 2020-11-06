#include "../leetcode.h"
//844. 比较含退格的字符串
/*
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
注意：如果对空文本输入退格字符，文本继续为空。

示例 1：
输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。

示例 2：
输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。

示例 3：
输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。

示例 4：
输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。

提示：
    1 <= S.length <= 200
    1 <= T.length <= 200
    S 和 T 只含有小写字母以及字符 '#'。
进阶：
    你可以用 O(N) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
 */
bool Leetcode::backspaceCompare(string S, string T) {//2020-10-19
////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：6.7 MB, 在所有 C++ 提交中击败了5.08% 的用户
////    从前到后
//    stack<char> stS, stT;
//    for (auto c:S) {
//        if (c != '#')
//            stS.push(c);
//        else if (!stS.empty()) {
//            stS.pop();
//        }
//    }
//    for (auto c:T) {
//        if (c != '#')
//            stT.push(c);
//        else if (!stT.empty()) {
//            stT.pop();
//        }
//    }
//    if (stS.size() != stT.size())
//        return false;
//    while (!stS.empty()) {
//        if (stS.top() != stT.top())
//            return false;
//        stS.pop();
//        stT.pop();
//    }
//    return true;

//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.4 MB, 在所有 C++ 提交中击败了40.85% 的用户
//    从后到前
    int endS, endT, delS, delT;
    endS = S.size() - 1;//S尾指针
    endT = T.size() - 1;//T尾指针
    delS = delT = 0;
    while (endS >= 0 || endT >= 0) {
        if (endS >= 0 && S[endS] == '#') {//S累积退格
            delS++;
            endS--;
            continue;
        }
        if (endT >= 0 && T[endT] == '#') {//T累积退格
            delT++;
            endT--;
            continue;
        }
        if (delS > 0) {//S退格
            endS--;
            delS--;
            continue;
        }
        if (delT > 0) {//T退格
            endT--;
            delT--;
            continue;
        }
        if (endS < 0 || endT < 0 || S[endS--] != T[endT--])
            return false;
    }
    return true;
}


string T844_build(string str) {
    string ret;
    for (char ch : str) {
        if (ch != '#') {
            ret.push_back(ch);
        } else if (!ret.empty()) {
            ret.pop_back();
        }
    }
    return ret;
}
bool backspaceCompare_1(string S, string T) {//抄
////    执行用时：4 ms, 在所有 C++ 提交中击败了51.03% 的用户
////    内存消耗：6.5 MB, 在所有 C++ 提交中击败了30.13% 的用户
////    方法一：重构字符串
//    return T844_build(S) == T844_build(T);

//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.4 MB, 在所有 C++ 提交中击败了36.69% 的用户
//    方法二：双指针
    int i = S.length() - 1, j = T.length() - 1;//指针
    int skipS = 0, skipT = 0;//需要退格数量

    while (i >= 0 || j >= 0) {
        while (i >= 0) {//对S进行退格
            if (S[i] == '#') {
                skipS++, i--;
            } else if (skipS > 0) {
                skipS--, i--;
            } else {
                break;
            }
        }
        while (j >= 0) {//对T进行退格
            if (T[j] == '#') {
                skipT++, j--;
            } else if (skipT > 0) {
                skipT--, j--;
            } else {
                break;
            }
        }
        if (i >= 0 && j >= 0) {
            if (S[i] != T[j]) {
                return false;
            }
        } else {
            if (i >= 0 || j >= 0) {
                return false;
            }
        }
        i--, j--;
    }
    return true;

////    执行用时：4 ms, 在所有 C++ 提交中击败了51.03% 的用户
////    内存消耗：6.4 MB, 在所有 C++ 提交中击败了35.40% 的用户
////    栈的原理
//    string stack1 = "", stack2 = "";
//    for (auto s : S)
//        if (s == '#' && stack1 != "")
//            stack1.pop_back();
//        else if (s != '#')
//            stack1.push_back(s);
//    for (auto t : T)
//        if (t == '#' && stack2 != "")
//            stack2.pop_back();
//        else if (t != '#')
//            stack2.push_back(t);
//    return stack1 == stack2;
}
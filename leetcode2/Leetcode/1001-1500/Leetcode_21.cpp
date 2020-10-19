#include "../leetcode.h"
//1002. 查找常用字符
/*
给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
你可以按任意顺序返回答案。

示例 1：
输入：["bella","label","roller"]
输出：["e","l","l"]
示例 2：
输入：["cool","lock","cook"]
输出：["c","o"]

提示：
    1 <= A.length <= 100
    1 <= A[i].length <= 100
    A[i][j] 是小写字母
 */
vector<string> commonChars_1(vector<string>& A){//抄
////    执行用时：8 ms, 在所有 C++ 提交中击败了99.26% 的用户
////    内存消耗：8.9 MB, 在所有 C++ 提交中击败了66.82% 的用户
//    vector<int> minfreq(26, INT_MAX);
//    vector<int> freq(26);
//    for (const string& word: A) {
//        fill(freq.begin(), freq.end(), 0);
//        for (char ch: word) {
//            ++freq[ch - 'a'];
//        }
//        for (int i = 0; i < 26; ++i) {
//            minfreq[i] = min(minfreq[i], freq[i]);
//        }
//    }
//
//    vector<string> ans;
//    for (int i = 0; i < 26; ++i) {
//        for (int j = 0; j < minfreq[i]; ++j) {
//            ans.emplace_back(1, i + 'a');
//        }
//    }
//    return ans;

//    执行用时：8 ms, 在所有 C++ 提交中击败了99.26% 的用户
//    内存消耗：9 MB, 在所有 C++ 提交中击败了63.88% 的用户
    vector<string> result;
    if (A.size() == 0) return result;
    int hash[26] = {0}; // 用来统计所有字符串里字符出现的最小频率
    for (int i = 0; i < A[0].size(); i++) { // 用第一个字符串给hash初始化
        hash[A[0][i] - 'a']++;
    }

    int hashOtherStr[26] = {0}; // 统计除第一个字符串外字符的出现频率
    for (int i = 1; i < A.size(); i++) {
        memset(hashOtherStr, 0, 26 * sizeof(int));
        for (int j = 0; j < A[i].size(); j++) {
            hashOtherStr[A[i][j] - 'a']++;
        }
        // 更新hash，保证hash里统计26个字符在所有字符串里出现的最小次数
        for (int k = 0; k < 26; k++) {
            hash[k] = min(hash[k], hashOtherStr[k]);
        }
    }
    // 将hash统计的字符次数，转成输出形式
    for (int i = 0; i < 26; i++) {
        while (hash[i] != 0) { // 注意这里是while，多个重复的字符
            string s(1, i + 'a'); // char -> string
            result.push_back(s);
            hash[i]--;
        }
    }

    return result;
}
vector<string> Leetcode::commonChars(vector<string>& A) {//2020-10-14
////    执行用时：12 ms, 在所有 C++ 提交中击败了91.96% 的用户
////    内存消耗：9.8 MB, 在所有 C++ 提交中击败了24.83% 的用户
//        vector<int> ans(26, 100);
//        vector<string> ans1;
//        for (auto ss:A) {
//            if (ss.empty())
//                return {};
//            vector<int> now(26, 0);
//            for (auto c:ss) {
//                now[c - 'a']++;
//            }
//            for (int i = 0; i < 26; ++i) {
//                ans[i] = min(ans[i], now[i]);
//            }
//        }
//        for (int j = 0; j < 26; ++j) {
//            for (int i = 0; i < ans[j]; ++i) {
//                ans1.emplace_back(1, j + 'a');
//            }
//        }
//        return ans1;

//    执行用时：12 ms, 在所有 C++ 提交中击败了91.96% 的用户
//    内存消耗：9.3 MB, 在所有 C++ 提交中击败了43.57% 的用户
    vector<int> ans(26, 100);
    vector<int> now(26, 0);
    vector<string> ans1;
    for (auto ss:A) {
        if (ss.empty())
            return {};
        fill(now.begin(),now.end(),0);
        for (auto c:ss) {
            now[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            ans[i] = min(ans[i], now[i]);
        }
    }
    for (int j = 0; j < 26; ++j) {
        for (int i = 0; i < ans[j]; ++i) {
            ans1.emplace_back(1, j + 'a');
        }
    }
    return ans1;

}
//1025. 除数博弈
/*
爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。
最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：
    选出任一 x，满足 0 < x < N 且 N % x == 0 。
    用 N - x 替换黑板上的数字 N 。
如果玩家无法执行这些操作，就会输掉游戏。
只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 false。假设两个玩家都以最佳状态参与游戏。

示例 1：
输入：2
输出：true
解释：爱丽丝选择 1，鲍勃无法进行操作。
示例 2：
输入：3
输出：false
解释：爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。

提示：
    1 <= N <= 1000
 */
bool Leetcode::divisorGame(int N) {
    //递归
    if(N==1)
        return false;
    else if(N==2)
        return true;
    return !divisorGame(N-1);

    //分析
    return N % 2 == 0;
}
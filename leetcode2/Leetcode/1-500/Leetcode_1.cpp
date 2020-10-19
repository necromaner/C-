#include "../leetcode.h"
#include <unordered_map>
#include <map>
#include <set>
//1. 两数之和
/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
 */
vector<int> Leetcode::twoSum(vector<int> &nums, int target){//2020-09-21
//    执行用时：24 ms, 在所有 C++ 提交中击败了53.89% 的用户
//    内存消耗：9.7 MB, 在所有 C++ 提交中击败了20.40% 的用户
        unordered_map<int,int> map;
        int size=nums.size();
        for (int i = 0; i < size; ++i) {
            auto aa=map.find(target-nums[i]);
            if(aa!=map.end())//是否找到
                return {aa->second,i};
            else
                map[nums[i]]=i;
        }
        return {};
}
vector<int> Leetcode::twoSum_2(vector<int> &nums, int target) {//旧
//    执行用时：204 ms, 在所有 C++ 提交中击败了44.71% 的用户
//    内存消耗：7.2 MB, 在所有 C++ 提交中击败了100.00% 的用户
        int size = nums.size();
        for (int i = 0; i < size - 1; i++) {
            int nums1 = target - nums[i];
            for (int j = i + 1; j < size; j++) {
                if (nums1 == nums[j])
                    return {i, j};
            }
        }
        return {};
}
vector<int> Leetcode::twoSum_1(vector<int> &nums, int target) {//抄
// 映射 	                底层实现 	是否有序 	数值是否可以重复 	能否更改数值 	查询效率 	增删效率
//std::map 	            红黑树 	    key有序 	    key不可重复 	    key不可修改 	O(logn) 	O(logn)
//std::multimap 	    红黑树 	    key有序   	key可重复 	    key不可修改 	O(logn) 	O(logn)
//std::unordered_map 	哈希表 	    key无序   	key不可重复 	    key不可修改 	O(1) 	    O(1)
//
//    执行用时：12 ms, 在所有 C++ 提交中击败了89.13% 的用户
//    内存消耗：10.1 MB, 在所有 C++ 提交中击败了12.47% 的用户
//    std::unordered_map<int, int> map;
//    int size = nums.size();
//    for (int i = 0; i < size; ++i) {
//        auto iter = map.find(target - nums[i]);
//        if (iter != map.end()) {
//            return {iter->second, i};
//        }
//        map.insert(pair<int, int>(nums[i], i));
//    }
//    return {};

////    暴力法
//    int i,j;
//    for(i=0;i<nums.size()-1;i++) {
//        for (j = i + 1; j < nums.size(); j++) {
//            if (nums[i] + nums[j] == target) {
//                return {i, j};
//            }
//        }
//    }
//    return {i,j};
////    两遍哈希表
//    map<int, int> a;//建立hash表存放数组元素
//    vector<int> b(2, -1);//存放结果
//    for (int i = 0; i < nums.size(); i++)//将数组存放在map中
//        a.insert(map<int, int>::value_type(nums[i], i));
//    for (int i = 0; i < nums.size(); i++) {
//        if (a.count(target - nums[i]) > 0 && (a[target - nums[i]] != i)){//判断是否找到目标元素且目标元素不能是本身
//            b[0] = i;
//            b[1] = a[target - nums[i]];
//            break;
//        }
//    }
//    return b;

////    一遍哈希表
//    map<int, int> a;//提供一对一的hash
//    vector<int> b(2, -1);//用来承载结果，初始化一个大小为2，值为-1的容器b
//    for (int i = 0; i < nums.size(); i++) {
//        if (a.count(target - nums[i]) > 0) {
//            b[0] = a[target - nums[i]];
//            b[1] = i;
//            break;
//        }
//        a[nums[i]] = i;//反过来放入map中，用来获取结果下标
//    }
//    return b;

////    排序+双指针法
//    执行用时：20 ms, 在所有 C++ 提交中击败了62.96% 的用户
//    内存消耗：9.1 MB, 在所有 C++ 提交中击败了25.33% 的用户
    vector<int> ans;
    vector<int> temp;
    temp = nums;
    int n = temp.size();
    sort(temp.begin(), temp.end());//数组的元素进行排序
    int i = 0, j = n - 1;
    while (i < j) {//找到目标值
        if (temp[i] + temp[j] > target)//确定较小值
            j--;
        else if (temp[i] + temp[j] < target)//确定较大值
            i++;
        else
            break;
    }
    if (i < j) {//找到目标值对应坐标
        for (int k = 0; k < n; k++) {
            if (i < n && nums[k] == temp[i]) {//找到较小值坐标
                ans.push_back(k);
                i = n;//寻找到指向最后
            } else if (j < n && nums[k] == temp[j]) {//找到较大值坐标
                ans.push_back(k);
                j = n;
            }
            if (i == n && j == n)//两个值都找到
                return ans;
        }
    }
    return ans;
}
//2. 两数相加
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
 */
ListNode *Leetcode::addTwoNumbers(ListNode *l1, ListNode *l2){//2020-09-21
//    执行用时：24 ms, 在所有 C++ 提交中击败了98.66% 的用户
//    内存消耗：9 MB, 在所有 C++ 提交中击败了86.04% 的用户
        auto *l3=new ListNode(0);
        ListNode *p1=l1,*p2=l2,*p3=l3;
        int aa=0;
        while (true){
            int n1=0,n2=0,n3;
            if(p1!= nullptr){//第一个数值
                n1=p1->val;
                p1=p1->next;
            }
            if (p2!= nullptr){//第二个数值
                n2=p2->val;
                p2=p2->next;
            }
            n3=(n1+n2)%10+aa;//sum+进位
            aa=(n1+n2)/10;
            if(n3>=10){
                n3%=10;
                aa++;
            }
            p3->val=n3;

            if(p1== nullptr&&p2== nullptr&&aa==0)
                break;
            p3->next=new ListNode(0);
            p3=p3->next;
        }
        return l3;
}
ListNode *Leetcode::addTwoNumbers_1(ListNode *l1, ListNode *l2) {//旧
//    执行用时：32 ms, 在所有 C++ 提交中击败了80.78% 的用户
//    内存消耗：9.4 MB, 在所有 C++ 提交中击败了100.00% 的用户
    int carry = 0;
    ListNode *p = l1, *q = l2, *curr = new ListNode(0);
    ListNode *dummyhead = curr;
    while (true) {
        int x = (p != nullptr) ? p->val : 0;
        int y = (q != nullptr) ? q->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        curr->val = sum % 10;
        if (p != nullptr) p = p->next;
        if (q != nullptr) q = q->next;
        if (p || q) {
            curr->next = new ListNode(0);
            curr = curr->next;
        } else {
            if (carry) {
                curr->next = new ListNode(0);
                curr = curr->next;
            }
            break;
        }
    }
    if (carry > 0) { curr->val = carry; }
    return dummyhead;
}
//3. 无重复字符的最长子串
/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 */
int Leetcode::T3_aaa(string s,set<char> *aa,int p){
    if(s.size()<=p)
        return aa->size();
    auto bb=aa->find(s[p]);
    if(bb != aa->end()) {
        return aa->size();
    } else {
        aa->insert(s[p]);
        T3_aaa(s,aa,p+1);
    }
    return aa->size();
}
int Leetcode::lengthOfLongestSubstring(string s) {//2020-09-21
//    执行用时：  60 ms, 在所有 C++ 提交中击败了40.50% 的用户
//    内存消耗：10.7 MB, 在所有 C++ 提交中击败了28.85% 的用户
        unordered_set<char> set;
        int size = s.size();
        int max1 = 0;
        for (int i = 0; i < size; ++i) {
            int nowMax;
            for (int j = i + (int) set.size(); j < size; ++j) {
                auto bb = set.find(s[j]);
                if (bb != set.end()) {//存在
                    break;
                } else {//插入
                    set.insert(s[j]);
                }
            }
            nowMax = set.size();
            max1 = max(max1, nowMax);
    //            if(max1<nowMax)
    //                max1=nowMax;
            set.erase(s[i]);//删除
        }
        return max1;
//    ////超时
//        set<char> set;
//        int max=0;
//        for (int i = 0; i < s.size(); ++i) {
//            int nowMax=T3_aaa(s,&set,i);
//            if(max<nowMax)
//                max=nowMax;
//            set.clear();
//        }
//        return max;
}
int Leetcode::lengthOfLongestSubstring_1(string s){//抄
//    执行用时：8 ms, 在所有 C++ 提交中击败了98.09% 的用户
//    内存消耗：7.5 MB, 在所有 C++ 提交中击败了72.68% 的用户
/*
    1.滑动窗口，保证每个窗口里字母都是唯一的
    2.使用 vector<int> m 来记录一个字母如果后面出现重复时，i 应该调整到的新位置21. 所以每次更新的时候都会保存 j + 1 ，即字母后面的位置
    3.j 表示子串的最后一个字母，计算子串长度为 j - i + 1
*/
        vector<int> m(128, 0);//ASCII到目前为止共定义了128个字符 位置代表对应字符，数字代表最后出现位置+1
        int ans = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            i = max(i, m[s[j]]);
            m[s[j]] = j + 1;
            ans = max(ans, j - i + 1);
//            cout<<
        }
        return ans;
}
//4. 寻找两个正序数组的中位数
/*
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。

示例 1:
nums1 = [1, 3]
nums2 = [2]
则中位数是 2.0

示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
则中位数是 (2 + 3)/2 = 2.5
 */
int Leetcode::T4_aaa(vector<int>& nums1, vector<int>& nums2,int num) {
        //找两个数组中第num小的数
        int s1 = nums1.size();
        int s2 = nums2.size();
        int index1 = 0, index2 = 0;//当前指向位置
        while (true) {
            if (index1 == s1) {//到达边界
                return nums2[index2 + num - 1];
            }
            if (index2 == s2) {//到达边界
                return nums1[index1 + num - 1];
            }
            if (num == 1) {
                return min(nums1[index1], nums2[index2]);
            }
            // 正常情况
            int newIndex1 = min(index1 + num / 2 - 1, s1 - 1);//新指向位置 不超出临界范围
            int newIndex2 = min(index2 + num / 2 - 1, s2 - 1);//新指向位置 不超出临界范围

            if (nums1[newIndex1] <= nums2[newIndex2]) {
                num -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            } else {
                num -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
}
double Leetcode::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {//2020-09-22 抄

//    执行用时：52 ms, 在所有 C++ 提交中击败了31.84% 的用户
//    内存消耗：86.8 MB, 在所有 C++ 提交中击败了52.78% 的用户
/*
nums1长度+nums2长度为奇数 为第(nums1.size()+nums2.size())/2位置的数
nums1长度+nums2长度为偶数 为第(nums1.size()+nums2.size())/2和后面位置的数之和的一半
 */
////     方法一：二分查找
/*

 给定两个有序数组，要求找到两个有序数组的中位数，最直观的思路有以下两种：

    使用归并的方式，合并两个有序数组，得到一个大的有序数组。大的有序数组的中间位置的元素，即为中位数。

    不需要合并两个有序数组，只要找到中位数的位置即可。由于两个数组的长度已知，因此中位数对应的两个数组的下标之和也是已知的。维护两个指针，初始时分别指向两个数组的下标 000 的位置，每次将指向较小值的指针后移一位（如果一个指针已经到达数组末尾，则只需要移动另一个数组的指针），直到到达中位数的位置。

假设两个有序数组的长度分别为 mmm 和 nnn，上述两种思路的复杂度如何？

第一种思路的时间复杂度是 O(m+n)O(m+n)O(m+n)，空间复杂度是 O(m+n)O(m+n)O(m+n)。第二种思路虽然可以将空间复杂度降到 O(1)O(1)O(1)，但是时间复杂度仍是 O(m+n)O(m+n)O(m+n)。题目要求时间复杂度是 O(log⁡(m+n))O(\log(m+n))O(log(m+n))，因此上述两种思路都不满足题目要求的时间复杂度。

如何把时间复杂度降低到 O(log⁡(m+n))O(\log(m+n))O(log(m+n)) 呢？如果对时间复杂度的要求有 log⁡\loglog，通常都需要用到二分查找，这道题也可以通过二分查找实现。

根据中位数的定义，当 m+nm+nm+n 是奇数时，中位数是两个有序数组中的第 (m+n)/2(m+n)/2(m+n)/2 个元素，当 m+nm+nm+n 是偶数时，中位数是两个有序数组中的第 (m+n)/2(m+n)/2(m+n)/2 个元素和第 (m+n)/2+1(m+n)/2+1(m+n)/2+1 个元素的平均值。因此，这道题可以转化成寻找两个有序数组中的第 kkk 小的数，其中 kkk 为 (m+n)/2(m+n)/2(m+n)/2 或 (m+n)/2+1(m+n)/2+1(m+n)/2+1。

假设两个有序数组分别是 A\text{A}A 和 B\text{B}B。要找到第 kkk 个元素，我们可以比较 A[k/2−1]\text{A}[k/2-1]A[k/2−1] 和 B[k/2−1]\text{B}[k/2-1]B[k/2−1]，其中 /// 表示整数除法。由于 A[k/2−1]\text{A}[k/2-1]A[k/2−1] 和 B[k/2−1]\text{B}[k/2-1]B[k/2−1] 的前面分别有 A[0 .. k/2−2]\text{A}[0\,..\,k/2-2]A[0..k/2−2] 和 B[0 .. k/2−2]\text{B}[0\,..\,k/2-2]B[0..k/2−2]，即 k/2−1k/2-1k/2−1 个元素，对于 A[k/2−1]\text{A}[k/2-1]A[k/2−1] 和 B[k/2−1]\text{B}[k/2-1]B[k/2−1] 中的较小值，最多只会有 (k/2−1)+(k/2−1)≤k−2(k/2-1)+(k/2-1) \leq k-2(k/2−1)+(k/2−1)≤k−2 个元素比它小，那么它就不能是第 kkk 小的数了。

因此我们可以归纳出三种情况：

    如果 A[k/2−1]<B[k/2−1]\text{A}[k/2-1] < \text{B}[k/2-1]A[k/2−1]<B[k/2−1]，则比 A[k/2−1]\text{A}[k/2-1]A[k/2−1] 小的数最多只有 A\text{A}A 的前 k/2−1k/2-1k/2−1 个数和 B\text{B}B 的前 k/2−1k/2-1k/2−1 个数，即比 A[k/2−1]\text{A}[k/2-1]A[k/2−1] 小的数最多只有 k−2k-2k−2 个，因此 A[k/2−1]\text{A}[k/2-1]A[k/2−1] 不可能是第 kkk 个数，A[0]\text{A}[0]A[0] 到 A[k/2−1]\text{A}[k/2-1]A[k/2−1] 也都不可能是第 kkk 个数，可以全部排除。

    如果 A[k/2−1]>B[k/2−1]\text{A}[k/2-1] > \text{B}[k/2-1]A[k/2−1]>B[k/2−1]，则可以排除 B[0]\text{B}[0]B[0] 到 B[k/2−1]\text{B}[k/2-1]B[k/2−1]。

    如果 A[k/2−1]=B[k/2−1]\text{A}[k/2-1] = \text{B}[k/2-1]A[k/2−1]=B[k/2−1]，则可以归入第一种情况处理。

fig1

可以看到，比较 A[k/2−1]\text{A}[k/2-1]A[k/2−1] 和 B[k/2−1]\text{B}[k/2-1]B[k/2−1] 之后，可以排除 k/2k/2k/2 个不可能是第 kkk 小的数，查找范围缩小了一半。同时，我们将在排除后的新数组上继续进行二分查找，并且根据我们排除数的个数，减少 kkk 的值，这是因为我们排除的数都不大于第 kkk 小的数。

有以下三种情况需要特殊处理：

    如果 A[k/2−1]\text{A}[k/2-1]A[k/2−1] 或者 B[k/2−1]\text{B}[k/2-1]B[k/2−1] 越界，那么我们可以选取对应数组中的最后一个元素。在这种情况下，我们必须根据排除数的个数减少 kkk 的值，而不能直接将 kkk 减去 k/2k/2k/2。

    如果一个数组为空，说明该数组中的所有元素都被排除，我们可以直接返回另一个数组中第 kkk 小的元素。

    如果 k=1k=1k=1，我们只要返回两个数组首元素的最小值即可。

用一个例子说明上述算法。假设两个有序数组如下：

A: 1 3 4 9
B: 1 2 3 4 5 6 7 8 9

两个有序数组的长度分别是 444 和 999，长度之和是 131313，中位数是两个有序数组中的第 777 个元素，因此需要找到第 k=7k=7k=7 个元素。

比较两个有序数组中下标为 k/2−1=2k/2-1=2k/2−1=2 的数，即 A[2]\text{A}[2]A[2] 和 B[2]\text{B}[2]B[2]，如下面所示：

A: 1 3 4 9
       ↑
B: 1 2 3 4 5 6 7 8 9
       ↑

由于 A[2]>B[2]\text{A}[2] > \text{B}[2]A[2]>B[2]，因此排除 B[0]\text{B}[0]B[0] 到 B[2]\text{B}[2]B[2]，即数组 B\text{B}B 的下标偏移（offset）变为 333，同时更新 kkk 的值：k=k−k/2=4k=k-k/2=4k=k−k/2=4。

下一步寻找，比较两个有序数组中下标为 k/2−1=1k/2-1=1k/2−1=1 的数，即 A[1]\text{A}[1]A[1] 和 B[4]\text{B}[4]B[4]，如下面所示，其中方括号部分表示已经被排除的数。

A: 1 3 4 9
     ↑
B: [1 2 3] 4 5 6 7 8 9
             ↑

由于 A[1]<B[4]\text{A}[1] < \text{B}[4]A[1]<B[4]，因此排除 A[0]\text{A}[0]A[0] 到 A[1]\text{A}[1]A[1]，即数组 A\text{A}A 的下标偏移变为 222，同时更新 kkk 的值：k=k−k/2=2k=k-k/2=2k=k−k/2=2。

下一步寻找，比较两个有序数组中下标为 k/2−1=0k/2-1=0k/2−1=0 的数，即比较 A[2]\text{A}[2]A[2] 和 B[3]\text{B}[3]B[3]，如下面所示，其中方括号部分表示已经被排除的数。

A: [1 3] 4 9
         ↑
B: [1 2 3] 4 5 6 7 8 9
           ↑

由于 A[2]=B[3]\text{A}[2]=B[3]A[2]=B[3]，根据之前的规则，排除 A\text{A}A 中的元素，因此排除 A[2]\text{A}[2]A[2]，即数组 A\text{A}A 的下标偏移变为 333，同时更新 kkk 的值： k=k−k/2=1k=k-k/2=1k=k−k/2=1。

由于 kkk 的值变成 111，因此比较两个有序数组中的未排除下标范围内的第一个数，其中较小的数即为第 kkk 个数，由于 A[3]>B[3]\text{A}[3] > \text{B}[3]A[3]>B[3]，因此第 kkk 个数是 B[3]=4\text{B}[3]=4B[3]=4。

A: [1 3 4] 9
           ↑
B: [1 2 3] 4 5 6 7 8 9
           ↑
复杂度分析

    时间复杂度：O(log⁡(m+n))O(\log(m+n))O(log(m+n))，其中 mmm 和 nnn 分别是数组 nums1\text{nums1}nums1 和 nums2\text{nums2}nums2 的长度。初始时有 k=(m+n)/2k=(m+n)/2k=(m+n)/2 或 k=(m+n)/2+1k=(m+n)/2+1k=(m+n)/2+1，每一轮循环可以将查找范围减少一半，因此时间复杂度是 O(log⁡(m+n))O(\log(m+n))O(log(m+n))。

    空间复杂度：O(1)O(1)O(1)。
 */
//        int totalLength = nums1.size() + nums2.size();
//        if (totalLength % 2 == 1) {
//            return T4_aaa(nums1, nums2, (totalLength + 1) / 2);
//        } else {
//            return (T4_aaa(nums1, nums2, totalLength / 2) + T4_aaa(nums1, nums2, totalLength / 2 + 1)) / 2.0;
//        }
////    方法二：划分数组
/*
说明

方法一的时间复杂度已经很优秀了，但本题存在时间复杂度更低的一种方法。这里给出推导过程，勇于挑战自己的读者可以进行尝试。

思路与算法

为了使用划分的方法解决这个问题，需要理解「中位数的作用是什么」。在统计中，中位数被用来：

    将一个集合划分为两个长度相等的子集，其中一个子集中的元素总是大于另一个子集中的元素。

如果理解了中位数的划分作用，就很接近答案了。

首先，在任意位置 iii 将 A\text{A}A 划分成两个部分：

           left_A            |          right_A
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]

由于 A\text{A}A 中有 mmm 个元素， 所以有 m+1m+1m+1 种划分的方法（i∈[0,m]i \in [0, m]i∈[0,m]）。

    len(left_A)=i,len(right_A)=m−i\text{len}(\text{left\_A}) = i, \text{len}(\text{right\_A}) = m - ilen(left_A)=i,len(right_A)=m−i.

    注意：当 i=0i = 0i=0 时，left_A\text{left\_A}left_A 为空集， 而当 i=mi = mi=m 时, right_A\text{right\_A}right_A 为空集。

采用同样的方式，在任意位置 jjj 将 B\text{B}B 划分成两个部分：

           left_B            |          right_B
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]

将 left_A\text{left\_A}left_A 和 left_B\text{left\_B}left_B 放入一个集合，并将 right_A\text{right\_A}right_A 和 right_B\text{right\_B}right_B 放入另一个集合。 再把这两个新的集合分别命名为 left_part\text{left\_part}left_part 和 right_part\text{right\_part}right_part：

          left_part          |         right_part
    A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
    B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]

当 A\text{A}A 和 B\text{B}B 的总长度是偶数时，如果可以确认：

    len(left_part)=len(right_part)\text{len}(\text{left\_part}) = \text{len}(\text{right\_part})len(left_part)=len(right_part)
    max⁡(left_part)≤min⁡(right_part)\max(\text{left\_part}) \leq \min(\text{right\_part})max(left_part)≤min(right_part)

那么，{A,B}\{\text{A}, \text{B}\}{A,B} 中的所有元素已经被划分为相同长度的两个部分，且前一部分中的元素总是小于或等于后一部分中的元素。中位数就是前一部分的最大值和后一部分的最小值的平均值：

median=max(left_part)+min(right_part)2\text{median} = \frac{\text{max}(\text{left}\_\text{part}) + \text{min}(\text{right}\_\text{part})}{2} median=2max(left_part)+min(right_part)​

当 A\text{A}A 和 B\text{B}B 的总长度是奇数时，如果可以确认：

    len(left_part)=len(right_part)+1\text{len}(\text{left\_part}) = \text{len}(\text{right\_part})+1len(left_part)=len(right_part)+1
    max⁡(left_part)≤min⁡(right_part)\max(\text{left\_part}) \leq \min(\text{right\_part})max(left_part)≤min(right_part)

那么，{A,B}\{\text{A}, \text{B}\}{A,B} 中的所有元素已经被划分为两个部分，前一部分比后一部分多一个元素，且前一部分中的元素总是小于或等于后一部分中的元素。中位数就是前一部分的最大值：

median=max(left_part)\text{median} = \text{max}(\text{left}\_\text{part}) median=max(left_part)

第一个条件对于总长度是偶数和奇数的情况有所不同，但是可以将两种情况合并。第二个条件对于总长度是偶数和奇数的情况是一样的。

要确保这两个条件，只需要保证：

    i+j=m−i+n−ji + j = m - i + n - ji+j=m−i+n−j（当 m+nm+nm+n 为偶数）或 i+j=m−i+n−j+1i + j = m - i + n - j + 1i+j=m−i+n−j+1（当 m+nm+nm+n 为奇数）。等号左侧为前一部分的元素个数，等号右侧为后一部分的元素个数。将 iii 和 jjj 全部移到等号左侧，我们就可以得到 i+j=m+n+12i+j = \frac{m + n + 1}{2}i+j=2m+n+1​。这里的分数结果只保留整数部分。

    0≤i≤m0 \leq i \leq m0≤i≤m，0≤j≤n0 \leq j \leq n0≤j≤n。如果我们规定 A\text{A}A 的长度小于等于 B\text{B}B 的长度，即 m≤nm \leq nm≤n。这样对于任意的 i∈[0,m]i \in [0, m]i∈[0,m]，都有 j=m+n+12−i∈[0,n]j = \frac{m + n + 1}{2} - i \in [0, n]j=2m+n+1​−i∈[0,n]，那么我们在 [0,m][0, m][0,m] 的范围内枚举 iii 并得到 jjj，就不需要额外的性质了。

        如果 A\text{A}A 的长度较大，那么我们只要交换 A\text{A}A 和 B\text{B}B 即可。

        如果 m>nm > nm>n ，那么得出的 jjj 有可能是负数。

    B[j−1]≤A[i]\text{B}[j-1] \leq \text{A}[i]B[j−1]≤A[i] 以及 A[i−1]≤B[j]\text{A}[i-1] \leq \text{B}[j]A[i−1]≤B[j]，即前一部分的最大值小于等于后一部分的最小值。

为了简化分析，假设 A[i−1],B[j−1],A[i],B[j]\text{A}[i-1], \text{B}[j-1], \text{A}[i], \text{B}[j]A[i−1],B[j−1],A[i],B[j] 总是存在。对于 i=0i=0i=0、i=mi=mi=m、j=0j=0j=0、j=nj=nj=n 这样的临界条件，我们只需要规定 A[−1]=B[−1]=−∞A[-1]=B[-1]=-\inftyA[−1]=B[−1]=−∞，A[m]=B[n]=∞A[m]=B[n]=\inftyA[m]=B[n]=∞ 即可。这也是比较直观的：当一个数组不出现在前一部分时，对应的值为负无穷，就不会对前一部分的最大值产生影响；当一个数组不出现在后一部分时，对应的值为正无穷，就不会对后一部分的最小值产生影响。

所以我们需要做的是：

    在 [0,m][0, m][0,m] 中找到 iii，使得：

    B[j−1]≤A[i]\qquad \text{B}[j-1] \leq \text{A}[i]B[j−1]≤A[i] 且 A[i−1]≤B[j]\text{A}[i-1] \leq \text{B}[j]A[i−1]≤B[j]，其中 j=m+n+12−ij = \frac{m + n + 1}{2} - ij=2m+n+1​−i

我们证明它等价于：

    在 [0,m][0, m][0,m] 中找到最大的 iii，使得：

    A[i−1]≤B[j]\qquad \text{A}[i-1] \leq \text{B}[j]A[i−1]≤B[j]，其中 j=m+n+12−ij = \frac{m + n + 1}{2} - ij=2m+n+1​−i

这是因为：

    当 iii 从 0∼m0 \sim m0∼m 递增时，A[i−1]\text{A}[i-1]A[i−1] 递增，B[j]\text{B}[j]B[j] 递减，所以一定存在一个最大的 iii 满足 A[i−1]≤B[j]A[i-1] \leq B[j]A[i−1]≤B[j]；

    如果 iii 是最大的，那么说明 i+1i+1i+1 不满足。将 i+1i+1i+1 带入可以得到 A[i]>B[j−1]A[i] > B[j-1]A[i]>B[j−1]，也就是 B[j−1]<A[i]B[j - 1] < A[i]B[j−1]<A[i]，就和我们进行等价变换前 iii 的性质一致了（甚至还要更强）。

因此我们可以对 iii 在 [0,m][0, m][0,m] 的区间上进行二分搜索，找到最大的满足 A[i−1]≤B[j]A[i-1] \leq B[j]A[i−1]≤B[j] 的 iii 值，就得到了划分的方法。此时，划分前一部分元素中的最大值，以及划分后一部分元素中的最小值，才可能作为就是这两个数组的中位数。
 复杂度分析

    时间复杂度：O(log⁡min⁡(m,n)))O(\log\min(m,n)))O(logmin(m,n)))，其中 mmm 和 nnn 分别是数组 nums1\text{nums1}nums1 和 nums2\text{nums2}nums2 的长度。查找的区间是 [0,m][0, m][0,m]，而该区间的长度在每次循环之后都会减少为原来的一半。所以，只需要执行 log⁡m\log mlogm 次循环。由于每次循环中的操作次数是常数，所以时间复杂度为 O(log⁡m)O(\log m)O(logm)。由于我们可能需要交换 nums1\text{nums1}nums1 和 nums2\text{nums2}nums2 使得 m≤nm \leq nm≤n，因此时间复杂度是 O(log⁡min⁡(m,n)))O(\log\min(m,n)))O(logmin(m,n)))。

    空间复杂度：O(1)O(1)O(1)。
 */
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m, ansi = -1;
    // median1：前一部分的最大值
    // median2：后一部分的最小值
    int median1 = 0, median2 = 0;

    while (left <= right) {
        // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
        // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;

        // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
        int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
        int nums_i = (i == m ? INT_MAX : nums1[i]);
        int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
        int nums_j = (j == n ? INT_MAX : nums2[j]);

        if (nums_im1 <= nums_j) {
            ansi = i;
            median1 = max(nums_im1, nums_jm1);
            median2 = min(nums_i, nums_j);
            left = i + 1;
        }
        else {
            right = i - 1;
        }
    }

    return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
}
//5. 最长回文子串
/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：

输入: "cbbd"
输出: "bb"
 */
string Leetcode::longestPalindrome(string s) {//2020-09-25 抄
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    string ans;
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i + l < n; ++i) {
            int j = i + l;
            cout<<l<<" "<<i<<" "<<i+l<<" "<<dp[i][j]<<" "<<s[i]<<" "<<s[j]<<" "<<endl;
            if (l == 0) {
                dp[i][j] = 1;
            } else if (l == 1) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            if (dp[i][j] && l + 1 > ans.size()) {
                ans = s.substr(i, l + 1);
            }
            cout<<l<<" "<<i<<" "<<i+l<<" "<<dp[i][j]<<" "<<s[i]<<" "<<s[j]<<" "<<endl<<endl;
        }
        cout<<endl;
    }
    return ans;
}
//6. Z 字形变换
/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);

示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"

示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
 */
string Leetcode::convert(string s, int numRows) {//2020-09-24 参考
//    执行用时：16 ms, 在所有 C++ 提交中击败了84.58% 的用户
//    内存消耗：10.2 MB, 在所有 C++ 提交中击败了54.44% 的用户
        if (numRows == 1)
            return s;
        vector<string> rows(min(numRows, int(s.size())));
        int nowNum = 0;//当前行数
        bool Down = false;
        for (char c:s) {
            rows[nowNum] += c;
            if (nowNum == 0 || nowNum == numRows - 1) {//变换方向
                Down = !Down;
            }
            nowNum += Down ? 1 : -1;
        }
        string ans;
        for (const string& ss:rows)
            ans += ss;
        return ans;
}
//7. 整数反转
/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:
输入: 123
输出: 321

示例 2:
输入: -123
输出: -321

示例 3:
输入: 120
输出: 21

注意:
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
 */
int Leetcode::reverse1(int x) {//旧
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：5.9 MB, 在所有 C++ 提交中击败了100.00% 的用户
    if (x / 10 == 0) return x; //绝对值小于10，直接返回
    long y = 0;
    while (x) {
        y *= 10;
        if (y > 2147483647 || y < -2147483648)
            return 0;
        y += x % 10; //取出x的个位
        x /= 10;     //去掉x的个位
    }
    return y;
}
int Leetcode::reverse(int x) {//2020-09-28
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：5.7 MB, 在所有 C++ 提交中击败了62.65% 的用户
    if (x / 10 == 0)
        return x;
    long long aaa = 0;
    while (x) {
        aaa = aaa * 10 + x % 10;
        if (aaa > INT_MAX || aaa < INT_MIN)
            return 0;
        x /= 10;
    }
    return (int) aaa;
}
int Leetcode::reverse2(int x) {//抄
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：5.7 MB, 在所有 C++ 提交中击败了94.37% 的用户
        int max = 0x7fffffff, min = 0x80000000;//int的最大值最小值
        long rs = 0;//用long类型判断溢出
        for (; x; rs = rs * 10 + x % 10, x /= 10);//逆序，正负通吃，不用单独考虑负值
        return rs > max || rs < min ? 0 : (int) rs;//超了最大值低于最小值就返回0
}
//8. 字符串转换整数 (atoi)
/*
请你来实现一个 atoi 函数，使其能将字符串转换成整数。
首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：
    如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
    假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
    该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。
在任何情况下，若函数不能进行有效的转换时，请返回 0 。
提示：
    本题中的空白字符只包括空格字符 ' ' 。
    假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

示例 1:
输入: "42"
输出: 42
示例 2:
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
示例 3:
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
示例 4:
输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
示例 5:
输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
     因此返回 INT_MIN (−231) 。
 */
int Leetcode::myAtoi(string str) {
////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：6.1 MB, 在所有 C++ 提交中击败了66.99% 的用户
//        int Ssize = str.size();
//        if (Ssize == 0)
//            return 0;
//        long answer = 0;
//        bool zheng = true;
//        bool isbegin = false;
//        for (int i = 0; i < Ssize; ++i) {
//            if (str[i] >= '0' && str[i] <= '9') {
//                answer = answer * 10 + str[i] - 48;
//                if (zheng && answer >= INT_MAX)
//                    return INT_MAX;
//                else if (!zheng && -answer <= INT_MIN)
//                    return INT_MIN;
//                isbegin = true;
//            } else if (str[i] == '-') {
//                if (!isbegin) {
//                    zheng = false;
//                    isbegin = true;
//                } else
//                    break;
//            } else if (str[i] == '+') {
//                if (!isbegin) {
//                    isbegin = true;
//                } else
//                    break;
//            } else if (str[i] == ' ') {
//                if (isbegin)
//                    break;
//            } else
//                break;
//        }
//        return zheng ? (int) answer : (int) -answer;

//    执行用时：4 ms, 在所有 C++ 提交中击败了81.07% 的用户
//    内存消耗：6 MB, 在所有 C++ 提交中击败了84.58% 的用户
        int Ssize = str.size();
        if (Ssize == 0)
            return 0;
        int begin = 0;
        //1.删除开头空格
        while (begin < Ssize && isspace(str[begin])) {
            begin++;
        }
        if (Ssize == begin) {//去掉前导空格以后到了末尾了
            return 0;
        }
        //2.判断符号
        bool negative = false;
        if (str[begin] == '-') {//遇到负号
            negative = true;
            begin++;
        } else if (str[begin] == '+') {// 遇到正号
            begin++;
        } else if (str[begin] > '9' || str[begin] < '0') {// 其他符号
            return 0;
        }
        //3.录入数字
        int ans = 0;
        while (begin < Ssize && (str[begin] >= '0' && str[begin] <= '9')) {
            int end = str[begin] - '0';
            if (ans > (INT_MAX - end) / 10)
                return negative ? INT_MIN : INT_MAX;
            else
                ans = ans * 10 + end;
            begin++;
        }
        return negative ? -ans : ans;
}
class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
            //                      ' '         +/-         number        other
            {"start"    , {"start"  , "signed"  , "in_number"   , "end"}},
            {"signed"   , {"end"    , "end"     , "in_number"   , "end"}},
            {"in_number", {"end"    , "end"     , "in_number"   , "end"}},
            {"end"      , {"end"    , "end"     , "end"         , "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;//空格
        if (c == '+' or c == '-') return 1;//符号
        if (isdigit(c)) return 2;//数字
        return 3;//其他
    }
public:
    int sign = 1;//符号
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};
int myAtoi_1(string str) {//抄
//    执行用时：20 ms, 在所有 C++ 提交中击败了11.47% 的用户
//    内存消耗：9.7 MB, 在所有 C++ 提交中击败了9.59% 的用户
 /*
字符串处理的题目往往涉及复杂的流程以及条件情况，如果直接上手写程序，一不小心就会写出极其臃肿的代码。
因此，为了有条理地分析每个输入字符的处理方法，我们可以使用自动机这个概念：
我们的程序在每个时刻有一个状态 s，每次从序列中输入一个字符 c，并根据字符 c 转移到下一个状态 s'。这样，我们只需要建立一个覆盖所有情况的从 s 与 c 映射到 s' 的表格即可解决题目中的问题。
*/
    Automaton automaton;
    for (char c : str)
        automaton.get(c);
    return automaton.sign * automaton.ans;
}
//9. 回文数
/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:
输入: 121
输出: true

示例 2:
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3:
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

进阶:
你能不将整数转为字符串来解决这个问题吗？

//执行用时 :12 ms, 在所有 cpp 提交中击败了88.65% 的用户
//内存消耗 :8.1 MB, 在所有 cpp 提交中击败了82.64%的用户
*/
bool Leetcode::isPalindrome_1(int x) {//旧
//    执行用时：12 ms, 在所有 C++ 提交中击败了83.14% 的用户
//    内存消耗：5.7 MB, 在所有 C++ 提交中击败了66.99% 的用户
        int x1 = x;
        if (x1 < 10 && x1 >= 0) return true;
        if (x1 < 0 || x1 > 2147447412) return false;
        int j = 0;
        while (x1 > 0) {
            j = j * 10 + x1 % 10;
            x1 /= 10;
        }
        return x == j;
}
int T9_getlen(int x){
    int length = 0;
    while(x!=0){
        x = x/10;
        length++;
    }
    return length;
}
bool Leetcode::isPalindrome(int x) {
//    执行用时：20 ms, 在所有 C++ 提交中击败了46.01% 的用户
//    内存消耗：6 MB, 在所有 C++ 提交中击败了12.40%
        if (x < 0 || x > 2147447412)
            return false;
        string s = to_string(x);
        int ss = s.size();
        for (int i = 0; i < ss / 2; ++i)
            if (s[i] != s[ss - i - 1])
                return false;
        return true;

////    执行用时：20 ms, 在所有 C++ 提交中击败了46.01% 的用户
////    内存消耗：5.8 MB, 在所有 C++ 提交中击败了49.45% 的用户
//    if (x < 0) return false;
//    int len = T9_getlen(x);
//    int temp = 0;
//    for (int i = 0; i < len / 2; i++) {
//        int t = x % 10;
//        temp = temp * 10 + t;
//        x = x / 10;
//    }
//    if (len % 2 == 1) x /= 10; //奇数的话，去掉中间的数字。
//    if (temp == x) return true;
//    return false;
}
//10. 正则表达式匹配
/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素

所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

    s 可能为空，且只包含从 a-z 的小写字母。
    p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
 */
bool Leetcode::isMatch_1(string s, string p) {
    cout<<"题目"<<s<<" "<<p<<endl;
    int pNow = 0;
    int size_p = p.size();
    bool isNext = false;//上一个为*
    char last;
    for (char c:s) {
        if (isNext) {//前一个为*
            if (last == c) {
                cout<<"前一个为*"<<"相同"<<endl;
                continue;
            } else {
                cout<<"前一个为*"<<"不相同"<<endl;
                isNext = false;
            }
        }
        char now = p[pNow];
        if (now == '*')//*前必跟字符
            return false;
        if (pNow < size_p && p[pNow + 1] == '*') {
            isNext = true;
            pNow++;
        }
        if (now == '.') {
            last = c;
        } else {
            if (now != c) {
                return false;
            } else if (now == c && isNext) {
                last = c;
            }
        }
        pNow++;
    }
    return true;
}
bool Leetcode::isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
//    https://baijiahao.baidu.com/s?id=1651645857687261494&wfr=spider&for=pc
    auto matches = [&](int i, int j) {//Lambda函数 [ capture list ] (parameters) -> return-type { method definition}
        if (i == 0) {//第一个
            return false;
        }
        if (p[j - 1] == '.') {
            return true;
        }
        return s[i - 1] == p[j - 1];
    };

    vector<vector<int>> f(m + 1, vector<int>(n + 1));
    f[0][0] = true;
    for (int i = 0; i <= m; ++i) {//遍历字符s
        for (int j = 1; j <= n; ++j) {//遍历字符p
            if (p[j - 1] == '*') {
                f[i][j] |= f[i][j - 2];
                if (matches(i, j - 1)) {
                    f[i][j] |= f[i - 1][j];
                }
            } else {
                if (matches(i, j)) {
                    f[i][j] |= f[i - 1][j - 1];
                }
            }
        }
    }
    return f[m][n];
}
//11. 盛最多水的容器
/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。

图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
示例：
输入：[1,8,6,2,5,4,8,3,7]
输出：49
 */
int Leetcode::maxArea(vector<int>& height) {
//    //超时
//        int size=height.size();
//        int ans=0;
//        for (int i = 0; i < size-1; ++i) {
//            for (int j = i+1; j < size; ++j) {
//                int max=(j-i)*min(height[i],height[j]);
//                if(ans<max)
//                    ans=max;
//            }
//        }
//        return ans;
    //双指针
//    执行用时：16 ms, 在所有 C++ 提交中击败了83.33% 的用户
//    内存消耗：7.5 MB, 在所有 C++ 提交中击败了9.83% 的用户
        int left = 0, right = height.size() - 1, ans = 0;
        while (left < right) {
            ans = max(ans, (min(height[left], height[right]) * (right - left)));
            if (height[left] > height[right])
                right--;
            else
                left++;
        }
        return ans;
}
//12. 整数转罗马数字
/*
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
    I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
    X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
    C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:
输入: 3
输出: "III"
示例 2:
输入: 4
输出: "IV"
示例 3:
输入: 9
输出: "IX"
示例 4:
输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:
输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.校准
 */
string Leetcode::intToRoman(int num) {//2020-09-30
    return intToRoman_1(num);
}
string Leetcode::intToRoman_1(int num) {//抄
////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：6.2 MB, 在所有 C++ 提交中击败了54.75% 的用户
////    暴力匹配
//    char* c[4][10] = {
//            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
//            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
//            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
//            {"","M","MM","MMM"}
//    };
//    string roman;
//    roman.append(c[3][num / 1000]);
//    roman.append(c[2][num / 100 % 10]);
//    roman.append(c[1][num / 10 % 10]);
//    roman.append(c[0][num % 10]);
//    return roman;

////    执行用时：8 ms, 在所有 C++ 提交中击败了91.10% 的用户
////    内存消耗：6.1 MB, 在所有 C++ 提交中击败了69.85% 的用户
////  贪心法
//    int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//    char* s[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
//    string ans;
//    for (int i = 0; i < 13; ++i) {
//        while (num >= val[i]) {
//            num -= val[i];
//            ans += s[i];
//        }
//    }
//    return ans;

//    执行用时：8 ms, 在所有 C++ 提交中击败了91.10% 的用户
//    内存消耗：6.2 MB, 在所有 C++ 提交中击败了53.74% 的用户
    char *ret = nullptr;
    if (num <= 0 || num > 3999) return ret;
    ret = (char *) malloc(sizeof(char) * 16);
    if (ret == nullptr) {
        printf("申请内存出错");
        exit(0);
    }
    ret[15] = 0; // memset(ret, 0, 16);

    char Rome[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    char i = 14, j = 0, m = 0;

    while (num) {
        m = num % 10;
        num /= 10;
        while (1) {
            if (m == 9) {
                ret[i--] = Rome[j + 2];
                m = 1;
            }
            else if (m == 8) {
                ret[i--] = Rome[j];
                m--;
            }
            else if (m == 7) {
                ret[i--] = Rome[j];
                m--;
            }
            else if (m == 6) {
                ret[i--] = Rome[j];
                m--;
            }
            else if (m == 5) {
                ret[i--] = Rome[j + 1];
                break;
            }
            else if (m == 4) {
                ret[i--] = Rome[j + 1];
                m = 1;
            }
            else if (m == 3) {
                ret[i--] = Rome[j];
                m--;
            }
            else if (m == 2) {
                ret[i--] = Rome[j];
                m--;
            }
            else if (m == 1) {
                ret[i--] = Rome[j];
                break;
            }
            else break;
        }
        j += 2;
    }
    return (ret + i + 1);
}
//13. 罗马数字转整数
/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:
输入: "III"
输出: 3

示例 2:
输入: "IV"
输出: 4

示例 3:
输入: "IX"
输出: 9

示例 4:
输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.

示例 5:
输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
 */
int Leetcode::romanToInt(string s) {
//    执行用时：8 ms, 在所有 C++ 提交中击败了93.86% 的用户
//    内存消耗：6.4 MB, 在所有 C++ 提交中击败了63.60% 的用户
        char Rome[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

        vector<int> ans(4, 0);
        int ss = s.size();
        for (int i = 0; i < ss; ++i) {

            int now;
            for (now = 0; now < 7; ++now) {
                if (s[i] == Rome[now])
                    break;
            }
            int av = now / 2;
            if (now % 2 == 0) {//偶数
                if (now >= 6 || i == ss - 1) {
                    ans[av] += 1;
                } else if (s[i + 1] == Rome[now + 1]) {
                    ans[av] += 4;
                    i++;
                } else if (s[i + 1] == Rome[now + 2]) {
                    ans[av] += 9;
                    i++;
                } else {
                    ans[av] += 1;
                }
            } else {
                ans[av] += 5;
            }
        }
        return ans[3] * 1000 + ans[2] * 100 + ans[1] * 10 + ans[0];
}
int Leetcode::romanToInt_1(string s) {//旧
//    执行用时 :8 ms, 在所有 cpp 提交中击败了98.32% 的用户
//    内存消耗 :8.3 MB, 在所有 cpp 提交中击败了94.54%的用户
    int answer = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == 'I') {
            if (s[i + 1] == 'I' || s[i + 1] == 0) {//1
                answer += 1;
            } else if (s[i + 1] == 'V') {//5
                answer += 4;
            } else if (s[i + 1] == 'X') {//10
                answer += 9;
            }
        } else if (s[i] == 'V') {
            if (s[i - 1] != 'I') {
                answer += 5;
            }
        }
        if (s[i] == 'X') {
            if (s[i + 1] == 'L') {//50
                answer += 40;
            } else if (s[i + 1] == 'C') {//100
                answer += 90;
            } else if (s[i - 1] != 'I') {
                answer += 10;
            }
        } else if (s[i] == 'L') {
            if (s[i - 1] != 'X') {
                answer += 50;
            }
        }
        if (s[i] == 'C') {
            if (s[i + 1] == 'D') {//50
                answer += 400;
            } else if (s[i + 1] == 'M') {//100
                answer += 900;
            } else if (s[i - 1] != 'X') {
                answer += 100;
            }
        } else if (s[i] == 'D') {
            if (s[i - 1] != 'C') {
                answer += 500;
            }
        }
        if (s[i] == 'M') {
            if (s[i - 1] != 'C') {
                answer += 1000;
            }
        }
    }
    return answer;
}
//14. 最长公共前缀
/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

说明:
所有输入只包含小写字母 a-z 。
 */
string Leetcode::longestCommonPrefix(vector<string> &strs) {//2020-09-30
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.6 MB, 在所有 C++ 提交中击败了73.59% 的用户
    if (strs.empty())
        return "";
    else if (strs.size() == 1)
        return strs[0];
    int end = 0;
    while (true) {
        char c = strs[0][end];
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].size() <= end || c != strs[i][end])
                return strs[0].substr(0, end);
        }
        end++;
    }
}
string Leetcode::longestCommonPrefix_1(vector<string> &strs) {//旧
    //执行用时 :8 ms, 在所有 cpp 提交中击败了71.48% 的用户
    //内存消耗 :8.8 MB, 在所有 cpp 提交中击败了78.58%的用户
    if (strs.empty())
        return "";
    int size = strs.size();
    if (size == 1)
        return strs[0];
    int minsize = strs[0].size();
    int minsize1;
    for (int i = 1; i < size; ++i) {
        minsize1 = strs[i].size();
        if (minsize > minsize1)
            minsize = minsize1;
    }
    if (minsize == 0)
        return "";
    int j;
    for (j = 0; j < minsize; ++j) {
        char first = strs[0].at(j);
        for (int i = 1; i < size; ++i) {
            if (first != strs[i].at(j))
                return strs[0].substr(0, j);
        }
    }
    return strs[0].substr(0, j);
}
//15. 三数之和
/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
[-1, 0, 1],
[-1, -1, 2]
]
*/
vector<vector<int>> Leetcode::threeSum(vector<int> &nums) {//2020-10-09
////    超时
//    vector<vector<int>> ans;
//    int numsS = nums.size();
//    if (numsS < 3)
//        return ans;
//    for (int i = 0; i < numsS - 2; ++i) {
//        if (i > 0 && nums[i] == nums[i - 1]) {
//            continue;
//        }
//        for (int j = i + 1; j < numsS - 1; ++j) {
//            if (j > i + 1 && nums[j] == nums[j - 1]) {
//                continue;
//            }
//            for (int k = numsS-1; k > j; --k) {
//                if (nums[i] + nums[j] + nums[k] == 0) {
//                    ans.push_back({nums[i], nums[j], nums[k]});
//                    break;
//                }
//            }
//        }
//    }
//    return ans;

////    执行用时：84 ms, 在所有 C++ 提交中击败了96.50% 的用户
////    内存消耗：19.6 MB, 在所有 C++ 提交中击败了51.90% 的用户
////    参考
//    vector<vector<int>> ans;
//    int numsS = nums.size();
//    if (numsS < 3)
//        return ans;
//    sort(nums.begin(), nums.end());//排序（头，尾，排序方式）
//    for (int i = 0; i < numsS - 2; ++i) {
//        if (nums[i] > 0)//第一位数必须小于等于0
//            break;
//        if (i > 0 && nums[i] == nums[i - 1]) {//跳过重复项
//            continue;
//        }
//        int target = -nums[i];
//        int k = numsS - 1;//最大数指针，
//        for (int j = i + 1; j < numsS - 1; ++j) {
//            if (j > i + 1 && nums[j] == nums[j - 1]) {//跳过重复项
//                continue;
//            }
//            while (k > j && (long)nums[j] + (long)nums[k] > (long)target)
//                k--;
//            if (k <= j)
//                break;
//            if (nums[j] + nums[k] == target) {
//                ans.push_back({-target, nums[j], nums[k]});
//            }
//        }
//    }
//    return ans;
    return threeSum_2(nums);
}
vector<vector<int>> Leetcode::threeSum_2(vector<int> &nums){//抄
////    执行用时：84 ms, 在所有 C++ 提交中击败了96.50% 的用户
////    内存消耗：19.7 MB, 在所有 C++ 提交中击败了42.24% 的用户
//    int n = nums.size();
//    sort(nums.begin(), nums.end());
//    vector<vector<int>> ans;
//    // 枚举 a
//    for (int first = 0; first < n; ++first) {
//        // 需要和上一次枚举的数不相同
//        if (first > 0 && nums[first] == nums[first - 1]) {
//            continue;
//        }
//        // c 对应的指针初始指向数组的最右端
//        int third = n - 1;
//        int target = -nums[first];
//        // 枚举 b
//        for (int second = first + 1; second < n; ++second) {
//            // 需要和上一次枚举的数不相同
//            if (second > first + 1 && nums[second] == nums[second - 1]) {
//                continue;
//            }
//            // 需要保证 b 的指针在 c 的指针的左侧
//            while (second < third && nums[second] + nums[third] > target) {
//                --third;
//            }
//            // 如果指针重合，随着 b 后续的增加
//            // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
//            if (second == third) {
//                break;
//            }
//            if (nums[second] + nums[third] == target) {
//                ans.push_back({nums[first], nums[second], nums[third]});
//            }
//        }
//    }
//    return ans;

//    执行用时：44 ms, 在所有 C++ 提交中击败了99.99% 的用户
//    内存消耗：20 MB, 在所有 C++ 提交中击败了29.97% 的用户
    vector<vector<int>> res;
    if (nums.size() < 3) {
        return res;
    }
    int maxNum = 0;//最大数字
    int minNum = 0;//最小数字
    for (const int d : nums) {//寻找最小最大
        maxNum = maxNum < d ? d : maxNum;
        minNum = minNum > d ? d : minNum;
    }
    const int tb_size = maxNum - minNum + 1;//最大到最小差值+1
    vector<char> rec(tb_size, 0);//开辟可行范围长度的数组
    for (const int d : nums) {
        if (++rec[d - minNum] > 3) {
            rec[d - minNum] = 3;
        }
    }
    if (rec[-minNum] == 2) {
        rec[-minNum] = 1;
    }
    vector<int> v;
    for (int i = 0; i < tb_size; ++i)
        if (rec[i] > 0) {
            v.push_back(i + minNum);
        }
    const int vsz = v.size();//rec大于0个数
    for (int i = 0; i < vsz; ++i) {
        const int vmin = v[i];
        if (vmin > 0) {
            break;
        }
        for (int j = i; j < vsz; ++j) {
            const int vmid = v[j];
            const int target = -vmin - vmid;
            if (target < vmid) {
                break;
            }
            if (target > maxNum || rec[target - minNum] == 0) {//比最大数大或者
                continue;
            }
            if (rec[vmid - minNum] > 1 || (vmin < vmid && vmid < target)) {
                res.push_back({vmin, vmid, target});
            }
        }
    }
    return res;
}
vector<vector<int>> Leetcode::threeSum_1(vector<int> &nums) {//旧
    sort(nums.begin(), nums.end());//排序（头，尾，排序方式）
    vector<vector<int>> answer;
    vector<int> answer1;
    if (nums.size() < 3) {
        return answer;
    }
    /*
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]);
        else {
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]);
                else {
                    for (int k = j + 1; k < nums.size(); k++) {
                        if (k > j + 1 && nums[k] == nums[k - 1]);
                        else {
                            if (nums[i] + nums[j] + nums[k] == 0) {
                                answer1 = {nums[i], nums[j], nums[k]};
                                answer.push_back(answer1);
                            }
                        }
                    }
                }
            }
        }
    }*/
    for (int i = 0; i < nums.size(); i++) {
        int j = i + 1;
        int k = nums.size() - 1;
        cout << j << " " << k << endl;
        while (j != k) {
            if (nums[j] == nums[i] + nums[k]) {
                answer1 = {nums[i], nums[j], nums[k]};
                answer.push_back(answer1);
            } else if (nums[j] < nums[i] + nums[k]) {//0 -1 2
                cout << "k--" << j << " " << k << endl;
                k--;
            } else {
                cout << "j++" << j << " " << k << endl;
                j++;
            }
        }
    }
    return answer;
}
void Leetcode::threeSum1(vector<int> &nums, vector<vector<int>> &answer, vector<int> &answer1, int i, int j, int k) {
    for (int m = 0; m < nums.size() - 3; m++) {
        while (j != k) {
            if (nums[j] == nums[i] + nums[k]) {
                answer1 = {nums[i], nums[j], nums[k]};
                answer.push_back(answer1);
            } else if (nums[j] < nums[i] + nums[k]) {//0 -1 2
                k--;
            } else {
                j++;
            }
        }
    }

}
//16. 最接近的三数之和
/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

示例：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。

提示：
    3 <= nums.length <= 10^3
    -10^3 <= nums[i] <= 10^3
    -10^4 <= target <= 10^4
 */
int Leetcode::threeSumClosest(vector<int>& nums, int target) {//2020-10-09
////    执行用时：448 ms, 在所有 C++ 提交中击败了6.72% 的用户
////    内存消耗：9.8 MB, 在所有 C++ 提交中击败了67.65% 的用户
//        sort(nums.begin(), nums.end());
//        int ans = nums[0] + nums[1] + nums[2];
//        int min = abs(ans - target);
//        int numsS = nums.size();
//        for (int i = 0; i < numsS - 2; ++i) {
//            if (i > 1 && nums[i] == nums[i - 1])
//                continue;
//            for (int j = i + 1; j < numsS - 1; ++j) {
//                if (j > i + 1 && nums[j] == nums[j - 1])
//                    continue;
//                for (int k = j + 1; k < numsS; ++k) {
//                    if (k > j + 1 && nums[k] == nums[k - 1])
//                        continue;
//                    int minNow = abs(nums[i] + nums[j] + nums[k] - target);
//                    if (min > minNow) {
//                        min = minNow;
//                        ans = nums[i] + nums[j] + nums[k];
//                    }
//                    if (nums[i] + nums[j] + nums[k] > target)
//                        break;
//                }
//                if (nums[i] + nums[j] > target)
//                    break;
//            }
//            if (nums[i] > target)
//                break;
//        }
//        return ans;

//    执行用时：16 ms, 在所有 C++ 提交中击败了81.35% 的用户
//    内存消耗：9.8 MB, 在所有 C++ 提交中击败了76.71% 的用户
//    参考
    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1] + nums[2];
    int numsS = nums.size();
    for (int i = 0; i < numsS - 2; ++i) {
        int left = i + 1, right = numsS - 1;
        while (left < right) {
            int sum = nums[left] + nums[right] + nums[i];
            if (abs(ans - target) > abs(sum - target))
                ans = sum;
            if (sum > target)
                right--;
            else if (sum < target)
                left++;
            else
                return target;
        }
    }
    return ans;
}
int Leetcode::threeSumClosest_1(vector<int>& nums, int target) {//抄
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int best = 1e7;

    // 根据差值的绝对值来更新答案
    auto update = [&](int cur) {
        if (abs(cur - target) < abs(best - target)) {
            best = cur;
        }
    };

    // 枚举 a
    for (int i = 0; i < n; ++i) {
        // 保证和上一次枚举的元素不相等
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        // 使用双指针枚举 b 和 c
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            // 如果和为 target 直接返回答案
            if (sum == target) {
                return target;
            }
            update(sum);
            if (sum > target) {
                // 如果和大于 target，移动 c 对应的指针
                int k0 = k - 1;
                // 移动到下一个不相等的元素
                while (j < k0 && nums[k0] == nums[k]) {
                    --k0;
                }
                k = k0;
            } else {
                // 如果和小于 target，移动 b 对应的指针
                int j0 = j + 1;
                // 移动到下一个不相等的元素
                while (j0 < k && nums[j0] == nums[j]) {
                    ++j0;
                }
                j = j0;
            }
        }
    }
    return best;
}
//17. 电话号码的字母组合
/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 */
vector<string> Leetcode::letterCombinations(string digits) {//2020-10-11
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.5 MB, 在所有 C++ 提交中击败了58.44% 的用户
    if(digits.empty())
        return {};
        char aa[9][4] = {
                {'a', 'b', 'c'},
                {'d', 'e', 'f'},
                {'g', 'h', 'i'},
                {'j', 'k', 'l'},
                {'m', 'n', 'o'},
                {'p', 'q', 'r', 's'},
                {'t', 'u', 'v'},
                {'w', 'x', 'y', 'z'}
        };
        int size = 1;
        for (char c:digits) {
            if (c == '7' || c == '9')
                size *= 4;
            else
                size *= 3;
        }
        int ss = size;
        vector<string> ans(size, "");
        for (char c:digits) {
            if (c == '7' || c == '9') {
                ss /= 4;
            } else {
                ss /= 3;
            }
            int head = 0;
            for (int j = 0; j < size;) {//循环答案
                if (c == '7' || c == '9') {
                    if (head >= 4)
                        head = 0;
                } else {
                    if (head >= 3)
                        head = 0;
                }
                for (int i = 0; i < ss; ++i) {//连续重复个数
                    ans[j] += aa[c - '2'][head];
                    j++;
                }
                head++;
            }

        }
        return ans;
}
void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
    if (index == digits.length()) {
        combinations.push_back(combination);
    } else {
        char digit = digits[index];
        const string &letters = phoneMap.at(digit);
        for (const char &letter: letters) {
            combination.push_back(letter);
            backtrack(combinations, phoneMap, digits, index + 1, combination);
            combination.pop_back();
        }
    }
}
vector<string> Leetcode::letterCombinations_1(string digits) {//抄
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.7 MB, 在所有 C++ 提交中击败了32.00% 的用户
    vector<string> combinations;
    if (digits.empty()) {
        return combinations;
    }
    unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    string combination;
    backtrack(combinations, phoneMap, digits, 0, combination);
    return combinations;
}
//18. 四数之和
/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
注意：
答案中不可以包含重复的四元组。

示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
 */
vector<vector<int>> Leetcode::fourSum(vector<int>& nums, int target) {//2020-10-12
////    执行用时：116 ms, 在所有 C++ 提交中击败了33.72% 的用户
////    内存消耗：13 MB, 在所有 C++ 提交中击败了12.37% 的用户
//    vector<vector<int>> ans;
//    int size = nums.size();
//    if (size < 4)
//        return ans;
//    sort(nums.begin(), nums.end());
//    for (int i = 0; i < size - 3; ++i) {
//        if (i > 0 && nums[i] == nums[i - 1])
//            continue;
//        for (int j = i + 1; j < size - 2; ++j) {
//            if (j > i + 1 && nums[j] == nums[j - 1])
//                continue;
//            int m = size - 1;
//            for (int k = j + 1; k < size - 1; ++k) {
//                if (k > j + 1 && nums[k] == nums[k - 1])
//                    continue;
//                while (nums[i] + nums[j] + nums[k] + nums[m] > target && k < m)
//                    m--;
//                if (k >= m)
//                    break;
//                if (nums[i] + nums[j] + nums[k] + nums[m] == target)
//                    ans.push_back({nums[i], nums[j], nums[k], nums[m]});
//            }
//        }
//    }
//    return ans;

//    执行用时：20 ms, 在所有 C++ 提交中击败了84.47% 的用户
//    内存消耗：12.9 MB, 在所有 C++ 提交中击败了16.59% 的用户
    //参考
    vector<vector<int>> ans;
    int size = nums.size();
    if (size < 4)
        return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1])continue;
        if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)break;
        if (nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target)continue;
        for (int j = i + 1; j < size - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1])continue;
            if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)break;
            if (nums[i] + nums[j] + nums[size - 2] + nums[size - 1] < target)continue;
            int m = size - 1;
            for (int k = j + 1; k < size - 1; ++k) {
                if (k > j + 1 && nums[k] == nums[k - 1])continue;
                while (nums[i] + nums[j] + nums[k] + nums[m] > target && k < m)m--;
                if (k >= m)break;
                if (nums[i] + nums[j] + nums[k] + nums[m] == target)
                    ans.push_back({nums[i], nums[j], nums[k], nums[m]});
            }
        }
    }
    return ans;
}
vector<vector<int>> Leetcode::fourSum_1(vector<int>& nums, int target) {//抄
//    执行用时：12 ms, 在所有 C++ 提交中击败了95.81% 的用户
//    内存消耗：12.7 MB, 在所有 C++ 提交中击败了41.07% 的用户
//    双指针
    vector<vector<int>> quadruplets;
    if (nums.size() < 4) {
        return quadruplets;
    }
    sort(nums.begin(), nums.end());
    int length = nums.size();
    for (int i = 0; i < length - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1])continue;
        if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)break;
        if (nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)continue;
        for (int j = i + 1; j < length - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])continue;
            if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)break;
            if (nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target)continue;
            int left = j + 1, right = length - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])left++;
                    left++;
                    while (left < right && nums[right] == nums[right - 1])right--;
                    right--;
                } else if (sum < target)
                    left++;
                 else
                    right--;
            }
        }
    }
    return quadruplets;
}
//19. 删除链表的倒数第N个节点
/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.

说明：
给定的 n 保证是有效的。

进阶：
你能尝试使用一趟扫描实现吗？
 */
void T19_1(ListNode* head,int n,int &now,int &size) {
    if (now == -1) {//上次未到末尾
        if (head->next == nullptr) {//到达末尾
            now = 0;
        } else {
            T19_1(head->next, n, now,++size);
        }
    }
    now++;
    if(now==n&&now==size){
        head=head->next;
    }else if(now-1==n)
        head->next=head->next->next;
}
ListNode* Leetcode::removeNthFromEnd(ListNode* head, int n) {//2020-10-13
////    执行用时：4 ms, 在所有 C++ 提交中击败了94.50% 的用户
////    内存消耗：10.9 MB, 在所有 C++ 提交中击败了5.07%
//    if (!head->next)
//        return head->next;
//    int now = -1;
//    int size = 1;
//    ListNode *newhead = new ListNode(0,head);
//    T19_1(newhead, n, now, size);
//    return newhead->next;
return removeNthFromEnd_1(head,n);
}

int cnt_19 = 0;
ListNode* Leetcode::removeNthFromEnd_1(ListNode* head, int n) {
////    执行用时：4 ms, 在所有 C++ 提交中击败了94.50% 的用户
////    内存消耗：10.9 MB, 在所有 C++ 提交中击败了5.07%
////    快慢指针
///*
//定义虚拟头节点，来保证可以删除头节点
//设置快慢指针，p为快指针，q为慢指针，p和q之间距离为n
//p，q开始一起移动，当p->next为空时，q->next指针就是需要删除的节点
// */
//    ListNode *newHead = new ListNode(-1, head);// 新增头指针 方便操作（如可删除头节点）
//    ListNode *p = newHead;//快指针
//    ListNode *q = newHead;//慢指针
//    for (int i = 0; i < n; i++) {
//        q = q->next;
//    }
//    while (q->next) {
//        q = q->next;
//        p = p->next;
//    }
//    // 删除结点
//    p->next = p->next->next;
//    return newHead->next;

////    执行用时：12 ms, 在所有 C++ 提交中击败了5.60% 的用户
////    内存消耗：10.8 MB, 在所有 C++ 提交中击败了5.07% 的用户
////    两次遍历
///*
//    定义虚拟头节点，来保证可以删除头节点
//    第一次遍历，统计链表长度
//    第二次遍历，向右移动cnt - n位
//    删除下一位的节点
// */
//    ListNode* dummy = new ListNode(-1);
//    dummy->next = head;
//    ListNode* p = dummy;
//    ListNode* q = dummy;
//    int cnt = 0;  //链表长度
//    while(p->next) { //第一次遍历
//        cnt ++;
//        p = p->next;
//    }
//    for(int i = 0; i < cnt - n; i ++)  q = q->next; //第二次遍历
//    q->next = q->next->next; //删除节点
//    return dummy->next;
//    执行用时：12 ms, 在所有 C++ 提交中击败了5.60% 的用户
//    内存消耗：10.9 MB, 在所有 C++ 提交中击败了5.07% 的用户
//    递归
    if(!head) return nullptr;
    head->next = removeNthFromEnd(head->next, n);
    cnt_19 ++;
    if(cnt_19 == n) return head->next;
    return head;
}
//20. 有效的括号
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true

示例 2:
输入: "()[]{}"
输出: true

示例 3:
输入: "(]"
输出: false

示例 4:
输入: "([)]"
输出: false

示例 5:
输入: "{[]}"
输出: true
 */
bool isValid_1(string s) {//旧
//    执行用时：144 ms, 在所有 C++ 提交中击败了49.33% 的用户
//    内存消耗：86.6 MB, 在所有 C++ 提交中击败了5.05% 的用户
    string s1 = "";
    int count = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}' || s[i] == '[' || s[i] == ']')
            s1 = s1 + s[i];
    }
    if (s1.size() < 2) {
        return 0;
    }
    while (s1.size() > 1) {
        for (unsigned i = 0; i < s1.size();) {
            int count1 = 0;
            if (s1[i] == '(') {
                if (s1[i + 1] == ')') {
                    s1.erase(i, 2);
                    count++;
                    count1++;
                }
            }
            if (s1[i] == '{') {
                if (s1[i + 1] == '}') {
                    s1.erase(i, 2);
                    count++;
                    count1++;
                }
            }
            if (s1[i] == '[') {
                if (s1[i + 1] == ']') {
                    s1.erase(i, 2);
                    count++;
                    count1++;
                }
            }
            if (count1 == 0) {
                i++;
            }
        }
        if (count == 0) {
            return 0;
        }
        count = 0;
    }
    if (s1.size() == 0) {
        return 1;
    }
    return 0;
}
bool isValid_2(string s) {//抄
////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：6.5 MB, 在所有 C++ 提交中击败了12.01% 的用户
//    int n = s.size();
//    if (n % 2 == 1) {
//        return false;
//    }
//
//    unordered_map<char, char> pairs = {
//            {')', '('},
//            {']', '['},
//            {'}', '{'}
//    };
//    stack<char> stk;
//    for (char ch: s) {
//        if (pairs.count(ch)) {
//            if (stk.empty() || stk.top() != pairs[ch]) {
//                return false;
//            }
//            stk.pop();
//        } else {
//            stk.push(ch);
//        }
//    }
//    return stk.empty();

//    执行用时：4 ms, 在所有 C++ 提交中击败了49.33% 的用户
//    内存消耗：6.6 MB, 在所有 C++ 提交中击败了7.54% 的用户
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(')');
        else if (s[i] == '{') st.push('}');
        else if (s[i] == '[') st.push(']');
            // 第三种情况 是遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            // 第二种情况 遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
        else if (st.empty() || st.top() != s[i]) return false;
        else st.pop(); // st.top() == s[i]
    }
    // 第一种情况 此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
    return st.empty();
}
bool Leetcode::isValid(string s) {//2020-10-14
////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：6.5 MB, 在所有 C++ 提交中击败了12.35% 的用户
//        stack<char> sta;
//        for (auto c:s)
//            if (c == '{' || c == '[' || c == '(')
//                sta.push(c);
//            else if (!sta.empty() && ((c == '}' && sta.top() == '{') || (c == ']' && sta.top() == '[') || (c == ')' && sta.top() == '(')))
//                sta.pop();
//            else
//                return false;
//        return sta.empty();

//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：6.3 MB, 在所有 C++ 提交中击败了50.31% 的用户
//    参考
    stack<char> sta;
    for (auto c:s)
        if (c == '{')
            sta.push('}');
        else if (c == '[')
            sta.push(']');
        else if (c == '(')
            sta.push(')');
        else if (!sta.empty() && c == sta.top())
            sta.pop();
        else
            return false;
    return sta.empty();
}
//21. 合并两个有序链表
/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
 */
ListNode* Leetcode::mergeTwoLists(ListNode* l1, ListNode* l2) {//2020-10-15 参考
//    执行用时：16 ms, 在所有 C++ 提交中击败了21.90% 的用户
//    内存消耗：14.8 MB, 在所有 C++ 提交中击败了5.15% 的用户
        ListNode *ans = new ListNode(0);
        ListNode *l3 = ans;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                l3->next = l1;
                l1 = l1->next;
            } else {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        l3->next = l1 ? l1 : l2;
        return ans->next;
}
ListNode* mergeTwoLists_1(ListNode* l1, ListNode* l2) {//抄
////    执行用时：12 ms, 在所有 C++ 提交中击败了55.25% 的用户
////    内存消耗：14.8 MB, 在所有 C++ 提交中击败了5.15% 的用户
////    方法一：递归
//    if (l1 == nullptr) {
//        return l2;
//    } else if (l2 == nullptr) {
//        return l1;
//    } else if (l1->val < l2->val) {
//        l1->next = mergeTwoLists_1(l1->next, l2);
//        return l1;
//    } else {
//        l2->next = mergeTwoLists_1(l1, l2->next);
//        return l2;
//    }

//    执行用时：12 ms, 在所有 C++ 提交中击败了55.25% 的用户
//    内存消耗：14.7 MB, 在所有 C++ 提交中击败了5.15% 的用户
//    方法二：迭代
    ListNode* preHead = new ListNode(-1);

    ListNode* prev = preHead;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }

    // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
    prev->next = l1 == nullptr ? l2 : l1;

    return preHead->next;
}
//22. 括号生成
/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
例如，给出 n = 3，生成结果为：

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
 */
void T22_1(vector<string> &ans,string answer,int left,int right) {
    if (left == 0 && right == 0) {
        ans.push_back(answer);
        answer.clear();
        return;
    }
    for (int i = 0; i < left; ++i) {
        answer += "(";
        T22_1(ans, answer, --left, ++right);
        while (right > 0) {
            answer += ")";
            T22_1(ans, answer, left, --right);
        }
    }
}
vector<string> Leetcode::generateParenthesis(int n){
    vector<string> ans;
    T22_1(ans,"",n,0);
    return ans;
}
void dfs(vector<string> &answer, string &answer1, int n, int digit, int leftparenthesis) {
    if (digit == n * 2) {
        answer.push_back(answer1);
        return;
    }
    if (leftparenthesis < n) {
        answer1.push_back('(');
        dfs(answer, answer1, n, digit + 1, leftparenthesis + 1);
        answer1.pop_back();
    }
    if (leftparenthesis * 2 > digit) {
        answer1.push_back(')');
        dfs(answer, answer1, n, digit + 1, leftparenthesis);
        answer1.pop_back();
    }
}
vector<string> generateParenthesis_1(int n) {//旧
    //执行用时 :0 ms, 在所有 cpp 提交中击败了100.00% 的用户
    //内存消耗 :13.8 MB, 在所有 cpp 提交中击败了90.93%的用户
    vector<string> answer;
    string answer1 = "";
    if (n == 0)
        return answer;
    dfs(answer, answer1, n, 0, 0);
    return answer;
}
//24. 两两交换链表中的节点
/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：
输入：head = []
输出：[]
示例 3：
输入：head = [1]
输出：[1]

提示：
    链表中节点的数目在范围 [0, 100] 内
    0 <= Node.val <= 100
 */
ListNode* Leetcode::swapPairs(ListNode* head) {
//    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//    内存消耗：7.6 MB, 在所有 C++ 提交中击败了5.30% 的用户
    if (!head || !head->next)
        return head;
    ListNode *newhead = new ListNode(0);
    newhead->next = head;
    ListNode *ans = newhead;
    ListNode *l1;
    ListNode *l2;
    ListNode *l3;
    while (newhead) {
        if (!newhead->next || !newhead->next->next)
            break;
        l1 = newhead->next;//1
        l2 = l1->next;//2
        l3 = l2->next;//3
        newhead->next = l2;
        l2->next = l1;
        l1->next = l3;
        newhead = l1;
    }
    return ans->next;



}
ListNode* Leetcode::swapPairs_1(ListNode* head){
////    执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
////    内存消耗：7.6 MB, 在所有 C++ 提交中击败了5.30% 的用户
////    递归
//    if (!head || !head->next)
//        return head;
//    ListNode *newhead = head->next;
//    head->next = swapPairs(newhead->next);
//    newhead->next = head;
//    return newhead;

//    执行用时：4 ms, 在所有 C++ 提交中击败了66.38% 的用户
//    内存消耗：7.7 MB, 在所有 C++ 提交中击败了5.30% 的用户
//    迭代
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* temp = dummyHead;
    while (temp->next != nullptr && temp->next->next != nullptr) {
        ListNode* node1 = temp->next;
        ListNode* node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }
    return dummyHead->next;
}
/*
 1 2 3 4
 2-1-3-4
 head=0;
 */
//26. 删除排序数组中的重复项
/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:
给定数组 nums = [1,1,2],
函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
你不需要考虑数组中超出新长度后面的元素。

示例 2:
给定 nums = [0,0,1,1,1,2,2,3,3,4],
函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
你不需要考虑数组中超出新长度后面的元素。

说明:
为什么返回数值是整数，但输出的答案是数组呢?
请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
你可以想象内部操作如下:
// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);
// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
print(nums[i]);
}
*/
//执行用时 :48 ms, 在所有 cpp 提交中击败了35.79% 的用户
//内存消耗 :10 MB, 在所有 cpp 提交中击败了76.56%的用户
int Leetcode::removeDuplicates(vector<int> &nums) {
    int bb = 0;                     //重复出现的个数
    sort(nums.begin(), nums.end());//排序（头，尾，排序方式）
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            ++bb;
        } else
            nums[i - bb] = nums[i];
    }
    nums.erase(nums.end() - bb, nums.end());  //删除后面 重复出现的个数
    return nums.size();
}
//27. 移除元素
/*
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1:
给定 nums = [3,2,2,3], val = 3,
函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
你不需要考虑数组中超出新长度后面的元素。

示例 2:
给定 nums = [0,1,2,2,3,0,4,2], val = 2,
函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
注意这五个元素可为任意顺序。
你不需要考虑数组中超出新长度后面的元素。

说明:
为什么返回数值是整数，但输出的答案是数组呢?
请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:
// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);
// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 */
//执行用时 :4 ms, 在所有 cpp 提交中击败了90.08% 的用户
//内存消耗 :8.6 MB, 在所有 cpp 提交中击败了78.36%的用户
int Leetcode::removeElement(vector<int> &nums, int val) {
    int bb = 0;
    sort(nums.begin(), nums.end());//排序（头，尾，排序方式）
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == val) {
            ++bb;
        } else {
            nums[i - bb] = nums[i];
        }
    }
    nums.erase(nums.end() - bb, nums.end());  //删除后面 重复出现的个数
    return nums.size();
}

//34. 在排序数组中查找元素的第一个和最后一个位置
/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。

示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]

示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
 */
//执行用时 :12 ms, 在所有 cpp 提交中击败了66.92% 的用户
//内存消耗 :10.2 MB, 在所有 cpp 提交中击败了92.34%的用户
vector<int> Leetcode::searchRange(vector<int> &nums, int target) {
    vector<int> answer;
    int d = 0;
    vector<int> error{-1, -1};
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            if (d > 1) {
                answer[1] = i;
            } else {
                answer.push_back(i);
            }
            ++d;
        }
    }
    if (d > 0)
        if (d > 1) {
            return answer;
        } else {
            answer.push_back(answer[0]);
            return answer;
        }
    else
        return error;
}
//35. 搜索插入位置
/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。

示例 1:
输入: [1,3,5,6], 5
输出: 2
示例 2:
输入: [1,3,5,6], 2
输出: 1
示例 3:
输入: [1,3,5,6], 7
输出: 4
示例 4:
输入: [1,3,5,6], 0
输出: 0
 */
int Leetcode::searchInsert(vector<int> &nums, int target) {//二分查找
    int answer = nums.size();
    int head = 0;
    int end = answer - 1;
    int mid;
    while (head <= end) {
        mid = head + ((end - head) >> 1);
        if (target <= nums[mid]) {
            answer = mid;
            end = mid - 1;
        } else {
            head = mid + 1;
        }
    }
    return answer;
}

int Leetcode::searchInsert_1(vector<int> &nums, int target) {
    int n = nums.size();
    if (n == 0) return 0;
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else if (nums[mid] == target) return mid;
        else right = mid;
    }
    if (nums[left] < target) return n;
    return left;
}
//37. 解数独
/*
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：
    数字 1-9 在每一行只能出现一次。
    数字 1-9 在每一列只能出现一次。
    数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。
Note:
    给定的数独序列只包含数字 1-9 和字符 '.' 。
    你可以假设给定的数独只有唯一解。
    给定数独永远是 9x9 形式的。

 */
void Leetcode::T37_dfs(vector<vector<char>>& board, int pos) {//抄//pos:数组位置
    if (pos == T37_spaces.size()) {//遍历到最后
        T37_valid = true;
        return;
    }
    auto[i, j] = T37_spaces[pos];//i j为当前位置数组
    for (int digit = 0; digit < 9 && !T37_valid; ++digit) {//遍历1-9数字
        cout << i << " " << j << " " << digit << endl;
        if (!T37_line[i][digit] && !T37_column[j][digit] && !T37_block[i / 3][j / 3][digit]) {//如果都不存在该数字
            T37_line[i][digit] = T37_column[j][digit] = T37_block[i / 3][j / 3][digit] = true;
            board[i][j] = digit + '0' + 1;
            T37_dfs(board, pos + 1);
            T37_line[i][digit] = T37_column[j][digit] = T37_block[i / 3][j / 3][digit] = false;//没有可填数字或者结束
        }
    }
}
void Leetcode::solveSudoku(vector<vector<char>>& board) {//抄
    memset(T37_line, false, sizeof(T37_line));
    memset(T37_column, false, sizeof(T37_column));
    memset(T37_block, false, sizeof(T37_block));
    T37_valid = false;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {//为"."存入数组中
                T37_spaces.emplace_back(i, j);
            } else {//为数字，存入3个bool中
                int digit = board[i][j] - '0' - 1;
                T37_line[i][digit] = T37_column[j][digit] = T37_block[i / 3][j / 3][digit] = true;
            }
        }
    }
    T37_dfs(board, 0);
}
//38. 报数
/*
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
注意：整数顺序将表示为一个字符串。

示例 1:
输入: 1
输出: "1"

示例 2:
输入: 4
输出: "1211"
 */
//执行用时 :32 ms, 在所有 cpp 提交中击败了6.12% 的用户
//内存消耗 :59 MB, 在所有 cpp 提交中击败了11.10%的用户
string Leetcode::countAndSay(int n) {
    string answer = "1";
    if (n <= 1) {
        return answer;
    }
    for (int i = 1; i < n; i++) {
        countAndSay1(answer);
    }
    return answer;
}

void Leetcode::countAndSay1(string &answer) {
    string answer1 = "";
    char count = '1';
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] == answer[i + 1]) {
            count++;
        } else {
            answer1 = answer1 + count + answer[i];
            count = '1';
        }
    }
    answer = answer1;
}
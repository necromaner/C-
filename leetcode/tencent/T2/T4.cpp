#include "../Output.h"
/*
合并K个排序链表
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6


 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return NULL;
    }
};
int main() {
    problem(__FILE__,"合并K个排序链表\n"
            "合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。");
    Solution solution;
    vector<ListNode*> lists=inPut({{1,4,5},{1,3,4},{2,6}});
    outPut(0,lists);
    
    outPut(1,solution.mergeKLists(lists));
    return 0;
}
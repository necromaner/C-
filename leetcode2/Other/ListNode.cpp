#include "ListNode.h"

ListNode *SetListNode(std::vector<int> list) {
    int size = list.size();
    if (size <= 0)
        return nullptr;
    ListNode *lists = new ListNode(list[0]);
    ListNode *list_now = lists;
    for (int i = 1; i < size; i++) {
        ListNode *list_new = new ListNode(list[i]);
        lists->next = list_new;
        lists = list_new;
    }
    return list_now;
}
std::vector<int> GetListNode(ListNode *list) {
    std::vector<int> answer;
    if (list == nullptr)
        return answer;
    ListNode *lists = list;
    while (lists->next != nullptr) {
        answer.push_back(lists->val);
        lists = lists->next;
    }
    if (lists != nullptr)
        answer.push_back(lists->val);
    return answer;
}
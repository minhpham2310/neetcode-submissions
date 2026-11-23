/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) return list1 ? list1 : list2;
        ListNode* start;
        ListNode* cur;
        ListNode* it;
        if (list1->val < list2->val) {
            start = list1;
            it = list2;
        }
        else{
            start = list2;
            it = list1;
        }
        cur = start;
        while (it){
            ListNode* next = cur->next;
            while (next && next->val <= it->val){
                cur = next;
                next = cur->next;
            }
            cur->next = it;
            cur = next;
            swap(cur,it);
        }
        return start;
    }
};

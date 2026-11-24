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
    bool hasCycle(ListNode* head) {
        ListNode dummy;
        ListNode* dumdum = &dummy;
        ListNode* next;
        while (head != nullptr){
            if (head->next == dumdum)
                return true;
            next = head->next;
            head->next = dumdum;
            head = next;
        }
        return false;
    }
};

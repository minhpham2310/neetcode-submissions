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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prev;
        ListNode* next = head->next;
        ListNode* start = head;
        do {
            prev = head;
            head = next;
            next = head->next;
            head->next = prev;
        } while (next != nullptr);
        if (start)
            start->next = nullptr;
        return head;
    }
};

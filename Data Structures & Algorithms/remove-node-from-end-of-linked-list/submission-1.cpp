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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int lenCount = 0;
        ListNode* iter = head;
        ListNode* nth = iter;
        ListNode* prev = nullptr;
        while (iter){
            iter = iter->next;
            ++lenCount;
            if (lenCount > n){
                prev=nth;
                nth=nth->next;
            }
        }
        if (prev)
            prev->next = nth->next;
        else
            return head->next;
        nth->next = nullptr;
        return head;
    }
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* resultHead = result;
        ListNode* prev;
        bool add1 = false;
        while (l1 || l2){
            int top = 0;
            if (l1){
                top = l1->val;
                l1 = l1->next;
            }
            int bottom = 0;
            if (l2){
                bottom = l2->val;
                l2 = l2->next;
            }
            result->val += add1+top+bottom;
            if (result->val >= 10){
                add1 = true;
                result->val %= 10;
            }
            else {
                add1 = false;
            }
            

            ListNode* next = new ListNode(0);
            prev = result;
            result->next = next;
            result = next;
        }
        if (add1){
            result->val = 1;
            result->next = nullptr;
        }
        else{
            prev->next = nullptr;
        }
        return resultHead;
    }
};

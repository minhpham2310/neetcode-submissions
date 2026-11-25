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
    void reorderList(ListNode* head) {
        if (!head) return;
        // find list length
        int counter = 0;
        ListNode* iterate = head->next;
        ListNode* half = head;
        while (iterate != nullptr){
            if (counter % 2)
                half = half->next;
            ++counter;
            iterate = iterate->next;
        }
        ListNode* tempHelper = half;
        half = half->next;
        tempHelper->next = nullptr;

        //reverse half
        tempHelper = nullptr;
        while (half != nullptr){
            ListNode* next = half->next;
            half->next = tempHelper;
            tempHelper = half;
            half = next;
        }
        half = tempHelper;

        // reorder logic
        ListNode* walk1 = head;
        ListNode* walk2 = half;

        while(walk1 || walk2) {
            ListNode* next1 = walk1->next;
            walk1->next = walk2;
            walk1 = next1;
            swap(walk1, walk2);

        }
    }
};

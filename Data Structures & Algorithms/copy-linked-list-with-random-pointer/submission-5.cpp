/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        unordered_map<Node*, Node*> original_copy;
        Node* iter = head;
        while (iter){
            Node* copy = new Node(iter->val);
            original_copy[iter] = copy;
            iter=iter->next;
        }
        iter = head;
        while (iter){
            Node* copy = original_copy[iter];
            copy->next = original_copy[iter->next];
            copy->random = original_copy[iter->random];
            iter=iter->next;
        }
        return original_copy[head];
    }
};

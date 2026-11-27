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
        unordered_map<Node*, int> listIndex1; //key = rand, val = index
        unordered_map<int, Node*> listIndex2;
        Node* newList = new Node(head->val);
        int i = 1;
        //copy list
        Node* inew = newList;
        Node* iter = head;
        while (iter){
            listIndex1[iter] = i;
            listIndex2[i] = inew;

            if (iter->next){
                Node* next = new Node(iter->next->val);
                inew->next = next;
            }
            else
                inew->next = nullptr;
            
            inew = inew->next;
            iter = iter->next;
            ++i;
        }

        i = 1;
        iter=head;
        inew=newList;

        while(iter){
            if(listIndex1[iter->random]){
                inew->random = listIndex2[listIndex1[iter->random]];
            }
            inew=inew->next;
            iter=iter->next;
            ++i;
        }
        inew = newList;
        return inew;
    }
};

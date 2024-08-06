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

        Node* it = head;
        Node* front = head;
        while (it != NULL) {
            front = it->next;
            Node* clone = new Node(it->val);
            it->next = clone;
            clone->next = front;
            it = front;
        }

        it = head;
        while (it != NULL) {
            if (it->random != NULL) {
                it->next->random = it->random->next;
            }
            it = it->next->next;
        }

        it = head;
        Node* dummy = new Node(0);
        Node* it2 = dummy;
        while (it != NULL) {
            front = it->next->next;
            it2->next = it->next;
            it->next = front;
            it2 = it2->next;
            it = front;
        }

        return dummy->next;
    }
};
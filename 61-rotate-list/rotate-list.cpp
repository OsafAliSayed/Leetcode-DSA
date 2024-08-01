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
    int lengthLL(ListNode* head) {
        ListNode* itr = head;
        int i = 0;
        while (itr != NULL) {
            itr = itr->next;
            i++;
        }
        return i;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode* itr = head;
        int len = lengthLL(head);
        if (len == 0) {
            return head;
        }
        k = k % len;
        if (k == 0) {
            return head;
        }
        int skips = len - k;
        int i = 1;
        while (i < skips) {
            itr = itr->next;
            i++;
        }

        ListNode* newHead = itr->next;
        itr->next = NULL;
        itr = newHead;
        while (itr->next != NULL) {
            itr = itr->next;
        }
        itr->next = head;
        return newHead;
    }
};
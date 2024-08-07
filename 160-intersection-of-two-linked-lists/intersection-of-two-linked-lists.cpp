/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* itr1 = headA;
        ListNode* itr2 = headB;

        while (itr1 != itr2) {
            itr1 = itr1->next;
            itr2 = itr2->next;
            if (itr1 == NULL && itr2 == NULL) {
                return NULL;
            }
            if (itr1 == NULL) {
                itr1 = headB;
            }
            if (itr2 == NULL) {
                itr2 = headA;
            }
        }
        return itr1;
    }
};
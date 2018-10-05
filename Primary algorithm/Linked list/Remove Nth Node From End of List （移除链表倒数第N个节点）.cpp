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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) {
            return NULL;
        }
        ListNode* cur1 = head;
        ListNode* cur2 = head;
        while (n--) {
            cur2 = cur2->next;
        }
        if (cur2 == NULL) {
            return head->next;
        } 
        while(cur2->next != NULL) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        cur1->next = cur1->next->next;
        return head;
    }
};
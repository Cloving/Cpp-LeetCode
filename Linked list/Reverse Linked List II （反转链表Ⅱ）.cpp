/* Reverse Linked List II （反转链表Ⅱ） */

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      if (head == NULL && head->next == NULL) {
        return head;
      }
      ListNode* dummy = new ListNode(-1);
      ListNode* cur = head;
      dummy->next = head;
      int val = n-m, k = m;
      while (--k) {
        cur = cur->next;
        dummy = dummy->next;
      }
      while (val--) {
        ListNode* temp = cur->next;
        cur->next = temp->next;
        temp->next = dummy->next;
        dummy->next = temp;
      }
      return m == 1 ? dummy->next : head;
    }
};
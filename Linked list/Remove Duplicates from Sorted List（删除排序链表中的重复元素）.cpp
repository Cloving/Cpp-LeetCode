/* Remove Duplicates from Sorted List（删除排序链表中的重复元素） */

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
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == NULL || head->next == NULL) {
        return head;
      }
      ListNode* first = head;
      ListNode* second = head->next;
      while (first != NULL && second != NULL) {
        if (first->val == second->val) {
          first->next = second->next;
          second = second->next;
        } else {
          first = first->next;
          second = second->next;
        }
      }
      return head;
    }
};
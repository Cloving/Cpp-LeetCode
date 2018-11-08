/* Reorder List（重排链表） */

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
  void reorderList(ListNode* head) {
    if (!head || !head->next || !head->next->next) {
      return;
    }
    ListNode *slow = head, *fast = head;
    while (fast->next != NULL || fast->next->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode* secondList = slow->next;
    slow->next = NULL;
    ListNode* pre = NULL;
    while (secondList != NULL) {
      ListNode* temp = secondList->next;
      secondList->next = pre;
      pre = secondList;
      secondList = temp;
    }
    while (head != NULL && pre != NULL) {
      ListNode* temp = head->next;
      head->next = pre;
      pre = pre->next;
      head->next->next = temp;
      head = temp;
    }
  }
};

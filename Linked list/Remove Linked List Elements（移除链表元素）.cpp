/* Remove Linked List Elements（移除链表元素） */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 第一种 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        dummy->next = head;
        while (cur->next != NULL) {
          if (cur->next->val == val) {
            cur->next = cur->next->next;
          } else {
            cur = cur->next;
          }
        }
        return dummy->next;
    }
};

/* 第二种 */
class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    if (head == NULL) {
      return NULL;
    }
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
  }
};

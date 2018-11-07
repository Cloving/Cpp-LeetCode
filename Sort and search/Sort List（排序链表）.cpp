/* Sort List（排序链表） */

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
    ListNode* sortList(ListNode* head) {
      if (head == NULL || head->next == NULL) {
        return head;
      }
      ListNode *pre = head, *slow = head, *fast = head;
      while (fast != NULL && fast->next != NULL) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
      pre->next = NULL;
      return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
      if (l1 == NULL) {
        return l2;
      }
      if (l2 == NULL) {
        return l1;
      }
      if (l1->val <= l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
      } else {
        l2->next = merge(l1, l2->next);
        return l2;
      }
    }
};

/* 第二种 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
      if (head == NULL || head->next == NULL) {
        return head;
      }
      ListNode *pre = head, *slow = head, *fast = head;
      while (fast != NULL && fast->next != NULL) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
      pre->next = NULL;
      return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
      ListNode* dummy = new ListNode(-1);
      ListNode* cur = dummy;
      while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
          cur->next = l1;
          l1 = l1->next;
        } else {
          cur->next = l2;
          l2 = l2->next;
        }
        cur = cur->next;
      }
      if (l1 == NULL) {
        cur->next = l2;
      }
      if (l2 == NULL) {
        cur->next = l1;
      }
      return dummy->next;
    }
};



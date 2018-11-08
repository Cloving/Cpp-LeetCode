/* Middle of the Linked List（链表的中间节点） */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 第一种：暴力法 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
      if (head == NULL || head->next == NULL) {
        return head;
      }
      ListNode* cur = head;
      int cnt = 0;
      while (cur != NULL) {
        cnt++;
        cur = cur->next;
      }
      for (int i = 0; i < cnt/2; i++) {
        head = head->next;
      }
      return head;
    }
};

/* 第二种: 快慢指针 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
      if (head == NULL || head->next == NULL) {
        return head;
      }
      ListNode* slow = head;
      ListNode* fast = head;
      while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
      }
      return slow;
    }
};
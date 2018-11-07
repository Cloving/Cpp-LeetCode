/* Insertion Sort List（对链表进行插入排序） */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 实际上是两个链表，返回的链表是新建立的 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      ListNode* dummy = new ListNode(-1);
      ListNode* cur = dummy;
      ListNode* unsortedListHead = head;
      while (unsortedListHead != NULL) {
        ListNode* temp = unsortedListHead->next;
        cur = dummy;
        if (cur->next != NULL && cur->next->val <= unsortedListHead->val) {
          cur = cur->next;
        }
        unsortedListHead->next = cur->next;
        cur->next = unsortedListHead;
        unsortedListHead = temp;
      }
      return dummy->next;
    }
};
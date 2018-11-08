/* Partition List（分隔链表） */

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
  ListNode* partition(ListNode* head, int x) {
    if (!head || !head->next) {
      return head;
    }
    ListNode* preNode = new ListNode(666);
    ListNode* res = preNode;
    preNode->next = head;
    ListNode* cur = head;
    while (cur != NULL && cur->val < x) {
      preNode = preNode->next;
      cur = cur->next;
    }
    if (cur == NULL) {
      return head;
    }
    ListNode* greaterX = cur;
    while(cur->next != NULL) {
      if (cur->next->val < x) {
        ListNode* temp = cur->next;
        cur->next = cur->next->next;
        temp->next = greaterX;
        preNode->next = temp;
        preNode = preNode->next;
      } else {
        cur = cur->next;
      }
    }
    return res->next;
  }
};

/* 第二种 */
class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    if (!head || !head->next) {
      return head;
    }
    ListNode* dummy1 = new ListNode(9208);
    ListNode* lowerX = dummy1;
    ListNode* dummy2 = new ListNode(92);
    ListNode* greaterX = dummy2;
    ListNode* cur = head;
    while (cur != NULL) {
      if (cur->val < x) {
        dummy1->next = cur;
        dummy1 = dummy1->next;
      } else {
        dummy2->next = cur;
        dummy2 = dummy2->next;
      }
      cur = cur->next;
    }
    /* 以下这句必须要有，否则会超出时间限制 */
    dummy2->next = NULL;
    dummy1->next = greaterX->next;
    return lowerX->next;
  }
};
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
    ListNode* oddEvenList(ListNode* head) {
      if (head == NULL || head->next == NULL) {
        return head;
      }
      ListNode* oddNode = head;
      ListNode* evenNode = head->next;
      ListNode* tempNode = head->next;
      while (evenNode != NULL && evenNode->next != NULL) {
        oddNode->next = oddNode->next->next;
        evenNode->next = evenNode->next->next;
        oddNode = oddNode->next;
        evenNode = evenNode->next;
      }
      oddNode->next = tempNode;
      return head;
    }
};

/* 第二种 */
/* 交换节点：除第一次外都要控制四个指针 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      if (head == NULL || head->next == NULL) {
        return head;
      }
      ListNode* pre = head;
      ListNode* cur = head->next;
      while (cur != NULL && cur->next != NULL) {
        ListNode* temp = pre->next;
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = temp;
        pre = pre->next;
        cur = cur->next;
      }
      return head;
    }
};

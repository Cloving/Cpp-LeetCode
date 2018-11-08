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
  ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* pre = dummy;
    while(pre->next && pre->next->next) {
      ListNode* node1 = pre->next;
      ListNode* node2 = pre->next->next;
      ListNode* curSwap_NextNode = node2->next;
      pre->next = node2;
      node1->next = curSwap_NextNode;
      node2->next = node1;
      pre = node2;
    }
    return dummy->next;
  }
};

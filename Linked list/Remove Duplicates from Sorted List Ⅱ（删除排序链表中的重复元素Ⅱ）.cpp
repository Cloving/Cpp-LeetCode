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
        if (!head || !head->next) {
          return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        while (pre->next != NULL) {
          ListNode* cur = pre->next;
          while (cur->next != NULL && cur->val == cur->next->val) {
            cur = cur->next;
          }
          if (pre->next == cur) {
            /* 永久连接 */
            pre = pre->next;
          } else {
            /* 临时连接到下一个 */
            pre->next = cur->next;
          }
        }
        return dummy->next;
    }
};
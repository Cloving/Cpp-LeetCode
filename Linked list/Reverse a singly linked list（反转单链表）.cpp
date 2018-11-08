/* Reverse a singly linked list（反转单链表） */

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
  ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* p = head;
    head = reverseList(p->next);
    p->next->next = p;
    p->next = NULL;
    return head;
  }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* cur = head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        while(cur->next != NULL) {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = dummy->next;
            dummy->next = temp;
        }
        return dummy->next;
    }
};

/* Add Two Numbers（两数相加） */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 第一种: 建立新链表 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* res = new ListNode(-1);
      ListNode* cur = res;
      int carry = 0;
      while (l1 != NULL || l2 != NULL) {
        int temp1 = l1 ? l1->val : 0;
        int temp2 = l2 ? l2->val : 0;
        int sum = temp1 + temp2 + carry;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        carry = sum / 10;
        if (l1 != NULL) {
          l1 = l1->next;
        }
        if (l2 != NULL) {
          l2 = l2->next;
        }
      }
      if (carry == 1) {
        cur->next = new ListNode(carry);
      }
      return res->next;
    }
};

/* 第二种：在原来的链表上修改（不好） */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if (l1 == NULL) {
        return l2;
      }
      if (l2 == NULL) {
        return l1;
      }
      int carry = 0;
      int sum = l1->val + l2->val + carry;
      l1->val = sum % 10;
      carry = sum / 10;
      ListNode* head = l1;
      while (l1->next != NULL && l2->next != NULL) {
        sum = l1->next->val + l2->next->val + carry;
        carry = (sum / 10 > 0) ? 1 : 0;
        l1->next->val = sum % 10;
        l1 = l1->next;
        l2 = l2->next;
      }
      if (l1->next == NULL && l2->next == NULL) {
        if (carry == 1) {
          ListNode* tail = new ListNode(carry);
          l1->next = tail;
        }
      } else if (l1->next == NULL) {
        l1->next = connect(l2->next, carry);
      } else if (l2->next == NULL){
        l2->next = connect(l1->next, carry);      
      }
      return head;
    }
    ListNode* connect(ListNode* hp, int carry) {
      if (carry == 0) {
        return hp;
      }
      ListNode* res = hp;
      while (hp != NULL && carry != 0) {
        hp->val = hp->val + carry;
        if (hp->val >= 10) {
          hp->val = hp->val % 10;
          carry = 1;
        } else {
            break;
        }
        if (hp->next == NULL && carry == 1) {
          ListNode* temp = new ListNode(carry);
          hp->next = temp;
          break;
        }
        hp = hp->next;
      }
      return res;
    }
};
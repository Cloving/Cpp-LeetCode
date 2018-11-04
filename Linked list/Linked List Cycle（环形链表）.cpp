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
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        while (second != NULL && second->next != NULL) {
            if (first == second) {
                return true;
            }
            first = first->next;
            second = second->next->next;
        }
        return false;
    }
};

/* 第二种 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        ListNode* first = head;
        ListNode* second = head;
        while (second != NULL && second->next != NULL) {
            first = first->next;
            second = second->next->next;
            if (first == second) {
                return true;
            }
        }
        return false;
    }
};
/* Intersection of Two Linked Lists（相交链表） */
/* 注意链表是否有环的情况 */
/* 1、都没有环的情况（与题目要求相同） */
/* 2、一个有环一个没环的情况 */
/* 3、都有环的情况（一个链表上环上的点是否在另一个链表上） */

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
           return NULL;
        }
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while (tempA != tempB) {
            if (tempA != NULL && tempB != NULL) {
                tempA = tempA->next;
                tempB = tempB->next;
            } else if (tempA == NULL) {
                tempA = headB;
            } else if (tempB == NULL) {
                tempB = headA;
            }
            
        }
        return tempA;
    }
};

/* 第二种 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        int lenA = 1, lenB = 1;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while (tempA->next != NULL) {
            lenA++;
            tempA = tempA->next;
        }
        while (tempB->next != NULL) {
            lenB++;
            tempB = tempB->next;
        }
        if (tempA != tempB) {
            return NULL;
        }
        if (lenA >= lenB) {
            return getThisNode(headB, headA, lenA - lenB);
        } else {
            return getThisNode(headA, headB, lenB - lenA);
        }
        
    }
    ListNode *getThisNode(ListNode *shortList, ListNode * longList, int diffValue) {
        while (diffValue--) {
            longList = longList->next;
        }
        while (shortList != longList) {
            longList = longList->next;
            shortList = shortList->next;
        }
        return shortList;
    }
};
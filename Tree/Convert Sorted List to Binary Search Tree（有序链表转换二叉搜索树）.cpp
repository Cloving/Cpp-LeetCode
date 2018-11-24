/* Convert Sorted List to Binary Search Tree（有序链表转换二叉搜索树） */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) {
      return head;
    }
    if (!head->next) {
      return new TreeNode(head->val);
    }
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* last = head;
    while (fast->next && fast->next->next) {
      last = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    fast = slow->next;
    last->next = NULL;
    TreeNode* cur = new TreeNode(slow->val);
    /* 这个 if 条件作用是：当链表元素只有两个时，只执行 if 判断后的递归调用，避免重复执行*/
    if (head != slow) {
      cur->left = sortedListToBST(head);
    }
    cur->right = sortedListToBST(fast);
    return cur;
  }
};
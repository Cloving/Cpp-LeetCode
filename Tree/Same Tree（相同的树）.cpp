/* Same Tree（相同的树） */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 递归 */
class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
      return true;
    }
    if (!p&&q || p&&!q || p->val != q->val) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

/* 非递归: 队列实现层序 */
class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
      return true;
    }
    if (!p&&q || p&&!q || p->val != q->val) {
      return false;
    }
    queue<TreeNode*> q1, q2;
    q1.push(p);
    q2.push(q);
    while (!q1.empty() && !q2.empty()) {
      int len1 = q1.size(), len2 = q2.size();
      if (len1 == len2) {
        for (int i = 0; i < len1; ++i) {
          TreeNode* node1 = q1.front();
          TreeNode* node2 = q2.front();
          q1.pop();
          q2.pop();
          if (node1->val != node2->val) {
            return false;
          }
          if (node1->left && node2->left) {
            q1.push(node1->left);
            q2.push(node2->left);
          } else if (!node1->left&&node2->left || node1->left&&!node2->left){
            return false;
          }
          if (node1->right && node2->right) {
            q1.push(node1->right);
            q2.push(node2->right);
          } else if (!node1->right&&node2->right || node1->right&&!node2->right){
            return false;
          }
        }
      } else {
        return false;
      }
    }
    return true;
  }
};

/* 还有先序、中序、后序的递归与非递归方式 */
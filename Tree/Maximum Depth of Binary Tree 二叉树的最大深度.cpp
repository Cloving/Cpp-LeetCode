/* Maximum Depth of Binary Tree 二叉树的最大深度 */

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
  int maxDepth(TreeNode* root) {
    if(root == NULL) {
      return 0;
    }
    return 1+max(maxDepth(root->left), maxDepth(root->right));
  }
};

/* 非递归 */
class Solution {
public:
  int maxDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int res = 0;
    while (!q.empty()) {
      res++;
      int count = q.size();
      for (int i = 0; i < count; ++i) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp->left) {
          q.push(temp->left);
        }
        if (temp->right) {
          q.push(temp->right);
        }
      }
    }
    return res;
  }
};

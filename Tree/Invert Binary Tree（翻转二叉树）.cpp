/* Invert Binary Tree（翻转二叉树） */

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
  TreeNode* invertTree(TreeNode* root) {
    if (!root) {
      return NULL;
    }
    swapTree(root);
    return root;
  }
  void swapTree(TreeNode* root) {
    if (!root || (!root->left && !root->right)) {
      return;
    }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    swapTree(root->left);
    swapTree(root->right);
  }
};

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) {
      return NULL;
    }
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
      TreeNode* node = que.front();
      que.pop();
      TreeNode* temp = node->left;
      node->left = node->right;
      node->right = temp;
      if (node->left) {
        que.push(node->left);
      }
      if (node->right) {
        que.push(node->right);
      }
    }
    return root;
  }
};
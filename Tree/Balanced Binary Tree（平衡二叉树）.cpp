/* Balanced Binary Tree（平衡二叉树） */

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
  bool isBalanced(TreeNode* root) {
    if (!root) {
      return true;
    }
    if (abs(getDepth(root->left) - getDepth(root->right)) > 1) {
      return false;
    };
    return isBalanced(root->left) && isBalanced(root->right);
  }
  int getDepth(TreeNode* node) {
    if (!node) {
      return 0;
    }
    return 1 + max(getDepth(node->left), getDepth(node->right);
  }
};

class Solution {
public:
  bool isBalanced(TreeNode* root) {
    if (checkDepth(root) == -1) {
      return false;
    }
    return true;
  }
  int checkDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int left = checkDepth(root->left);
    if (left == -1) {
      return -1;
    }
    int right = checkDepth(root->right);
    if (right == -1) {
      return -1;
    }
    if (abs(right - left) > 1) {
      return -1;
    }
    return 1 + max(left, right);
  }
};
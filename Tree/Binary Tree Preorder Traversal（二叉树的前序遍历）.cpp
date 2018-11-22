/* Binary Tree Preorder Traversal（二叉树的前序遍历） */

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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
      if (root) {
        res.push_back(root->val);
        preorderTraversal(root->left); 
        preorderTraversal(root->right);
      }
      return res;
    }
};

class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res; 
    if (!root) {
      return res;
    }
    stack<TreeNode*> s{{root}};
    while (!s.empty()) {
      TreeNode* node = s.top();
      s.pop();
      res.push_back(node->val);
      if (node->right) {
        s.push(node->right);
      }
      if (node->left) {
        s.push(node->left);
      }
    }
    return res;
  }
};

class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res; 
    if (!root) {
      return res;
    }
    stack<TreeNode*> s;
    TreeNode* node = root;
    while (!s.empty() || node) {
      if (node) {
        res.push_back(node->val);
        s.push(node);
        node = node->left;
      } else {
        TreeNode* t = s.top();
        s.pop();
        node = t->right;
      }
    }
    return res;
  }
};
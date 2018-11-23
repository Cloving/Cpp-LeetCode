/* Binary Tree Inorder Traversal（二叉树的中序遍历） */

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
  vector<int> inorderTraversal(TreeNode* root) {
    if (root) {
      inorderTraversal(root->left);
      res.push_back(root->val);
      inorderTraversal(root->right);
    }
    return res;
  }
};

class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) {
      return res;
    }
    stack<TreeNode*> s;
    TreeNode* node = root;
    while (!s.empty() || node) {
      if (node) {
        s.push(node);
        node = node->left;
      } else {
        TreeNode* t = s.top();
        s.pop();
        res.push_back(t->val);
        node = t->right;
      }
    }
    return res;
  }
};

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root) {
      return res;
    }
    TreeNode *pre, *cur;
    cur = root;
    while (cur) {
      if (!cur->left) {
        res.push_back(cur->val);
        cur = cur->right;
      } else {
        pre = cur->left;
        while (pre->right && pre->right != cur) {
          pre = pre->next;
        }
        if (!pre->right) {
          pre->right = cur;
          cur = cur->left;
        } else {
          pre->right = NULL;
          res.push_back(cur->val);
          cur = cur->right;
        }
      }
    }
    return res;
  }
};
/* Binary Tree Postorder Traversal（二叉树的后序遍历） */

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
  vector<int> postorderTraversal(TreeNode* root) {
    if (root) {
      postorderTraversal(root->left);
      postorderTraversal(root->right);
      res.push_back(root->val);
    }
    return res;
  }
};

class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) {
      return res;
    }
    stack<TreeNode*> s{{root}};
    while (!s.empty()) {
      TreeNode* node = s.top();
      s.pop();
      res.insert(res.begin(), node->val);
      if (node->left) {
        s.push(node->left);
      }
      if (node->right) {
        s.push(node->right);
      }
    }
    return res;
  }
};


class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) {
      return res;
    }
    stack<TreeNode*> s;
    TreeNode* node = root;
    while (!s.empty() || node) {
      if (node) {
        s.push(node);
        res.insert(res.begin(), node->val);
        node = node->right;
      } else {
        TreeNode* t = s.top();
        s.pop();
        node = t->left;
      }
    }
    return res;
  }
};


class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    stack<TreeNode*> s{{root}};
    TreeNode *head = root;
    while (!s.empty()) {
      TreeNode *t = s.top();
      if ((!t->left && !t->right) || t->left == head || t->right == head) {
        res.push_back(t->val);
        s.pop();
        head = t;
      } else {
        if (t->right) {
          s.push(t->right);
        }
        if (t->left){
          s.push(t->left);
        }
      }
    }
    return res;
  }
};
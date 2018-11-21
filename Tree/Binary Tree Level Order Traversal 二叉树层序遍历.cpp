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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> q;
    if (root) {
      q.push(root);
    }
    while (!q.empty()) {
      vector<int> temp;
      int len = q.size();
      for (int i = 0; i < len; ++i) {
        TreeNode* node = q.front();
        q.pop();
        temp.push_back(node->val);
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      res.push_back(temp);
    }
    return res;
  }
};


class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    orderByLevel(root, 0, res);
    return res;
  }
  void orderByLevel(TreeNode* root, int level, vector<vector<int>>& res) {
    if (!root) {
      return;
    }
    if (res.size() == level) {
      res.push_back({});
    }
    res[level].push_back(root->val);
    if (root->left) {
      orderByLevel(root->left, level+1, res);
    }
    if (root->right) {
      orderByLevel(root->right, level+1, res);
    }
  }
};


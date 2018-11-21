/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 递归： 
 * 不能在递归函数中使用res.insert(res.begin(), {})
 * 因为插入空数组res列表的长度不会增加，之后插入元素时会指向空指针
 * 只有res.push_back({})可以
 */
class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    levelOrder(root, 0, res);
    return vector<vector<int>> (res.rbegin(), res.rend());
  }
  void levelOrder(TreeNode* root, int level, vector<vector<int>>& res) {
    if (!root) {
      return;
    }
    if (res.size() == level) {
      res.push_back({});
    }
    res[level].push_back(root->val);
    if (root->left) {
      levelOrder(root->left, level+1, res);
    }
    if (root->right) {
      levelOrder(root->right, level+1, res);
    }
  }
};

/* 非递归 */
class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
      return res;
    }
    queue<TreeNode*> q;
    q.push(root);
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
      res.insert(res.begin(), temp);
    }
    return res;
  }
};
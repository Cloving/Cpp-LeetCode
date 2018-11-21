/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 非递归 */
class Solution {
public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    if (!root) {
      return res;
    }
    queue<TreeNode* > q;
    q.push(root);
    while (!q.empty()) {
      int len = q.size();
      long averageValue = 0;
      for (int i = 0; i < len; ++i) {
        TreeNode* node = q.front();
        q.pop();
        averageValue += node->val;
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      res.push_back((double) averageValue / len);
    }
    return res;
  }
};

/* 递归 */
class Solution {
public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<int> cnt;
    vector<double> res;
    average(root, 0, res, cnt);
    for (int i = 0; i < cnt.size(); ++i) {
      res[i] /= cnt[i];
    }
    return res;
  }
  void average(TreeNode* root, int level, vector<double>& res, vector<int>& cnt) {
    if (!root) {
      return;
    }
    if (res.size() == level) {
      res.push_back(0);
      cnt.push_back(0);
    }
    res[level] += root->val;
    ++cnt[level];
    if (root->left) {
      average(root->left, level+1, res, cnt);
    }
    if (root->right) {
      average(root->right, level+1, res, cnt);
    }
  }
};
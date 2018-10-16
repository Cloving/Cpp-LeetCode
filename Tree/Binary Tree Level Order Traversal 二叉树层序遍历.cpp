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
        
        if (!root) {
            return res;
        }
        queue<TreeNode* > q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int count = q.size();
            for (int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                temp.push_back(node->val);
                q.pop();
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
        levelOrder(root, 0, res);
        return res;
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
            levelOrder (root->left, level+1, res);
        }
        if (root->right) {
            levelOrder (root->right, level+1, res);
        }
    }
};
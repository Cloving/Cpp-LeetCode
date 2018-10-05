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
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int res = 0;
        queue<TreeNode* > que;
        que.push(root);
        while(!que.empty()) {
          res++;
          int count = que.size();
          for (int i = 0; i < count; i++) {
            TreeNode* temp = que.front();
            que.pop();
            if (temp->left) {
                que.push(temp->left);
            }
            if (temp->right) {
                que.push(temp->right);
            }
          }
        }
        return res;
    }
};
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
    bool isValidBST(TreeNode* root) {
        return validBST (root, LONG_MIN, LONG_MAX);
    }
    bool validBST(TreeNode* root, min, max) {
        if(root == NULL) {
            return true;
        }
        if (root->val <= min && root->val >= max) {
            return false;
        }
        return validBST(root->left, min, root->val) && validBST(root->right, root->val, max);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root != NULL) {
          return true;
        }
        vector<int> vec;
        inorder(root, vec);
        for (int i = 0; i < vec.size(); i++) {
          if (vec[i] >= vec[i+1]) {
            return false;
          }
        }
        return true;
    }
    inorder(TreeNode* root, vector<int>& vec) {
      if (!root) {
        return;
      }
      inorder(root->left, vec);
      vec.push_back(root->val);
      inorder(root->right, vec);
    }
};
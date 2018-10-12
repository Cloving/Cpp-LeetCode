/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//  一
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
// 二
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

// 三
class Solution {
public:
    TreeNode* pre;
    bool isValidBST(TreeNode* root) {
        int res = 1;
        pre = NULL;
        validBST(root, res);
        if (res == 1){
            return true;
        } else {
            return false;
        }
    }
    void validBST(TreeNode* root, int& res) {
        if (!root) {
            return; 
        }
        validBST(root->left, res);
        if (!pre) {
            pre = root;
        } else {
            if (pre->val >= root->val) {
                res = 0;
            }
            pre = root;
        }
        validBST(root->right, res);
    }
};

// 四
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode* > s;
        TreeNode *p = root, *pre = NULL;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            TreeNode* t = s.top();
            s.pop();
            if (pre && t->val <= pre->val) {
                return false;
            }
            pre = t;
            p = t->right;
        }
        return true;
    }
};
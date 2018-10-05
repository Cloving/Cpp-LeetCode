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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true;
        }
        if (!left&&right || left&&!right || left->val != right->val) {
            return false;
        }
        return isSymmetric(left->left, right->right) && isSymmetric(right->left, left->right);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()) {
            TreeNode* t1 = q1.front();
            TreeNode* t2 = q2.front();
            q1.pop();
            q2.pop();
            if (!t1 && t2 || t1 && !t2) {
                return false;
            }
            //  判断任何一个存在都可以            
            if (t2) {
                if (t1->val != t2->val) {
                    return false;
                }
                q1.push(t1->left);
                q1.push(t1->right);
                q2.push(t2->right);
                q2.push(t2->left);
            }
        }
        return true;
    }
};
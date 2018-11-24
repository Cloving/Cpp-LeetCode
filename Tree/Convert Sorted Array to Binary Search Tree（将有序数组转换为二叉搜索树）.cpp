/* Convert Sorted Array to Binary Search Tree（将有序数组转换为二叉搜索树） */

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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return setBST(nums, 0, nums.size()-1);
  }
  TreeNode* setBST(vector<int>& nums, int left, int right) {
    if (left > right) {
      return NULL;
    }
    int mid = left + (right - left) / 2;
    TreeNode* cur = new TreeNode(nums[mid]);
    cur->left = setBST(nums, left, mid-1);
    cur->right = setBST(nums, mid+1, right);
    return cur;
  }
};


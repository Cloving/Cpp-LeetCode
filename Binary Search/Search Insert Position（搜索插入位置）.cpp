/* Search Insert Position（搜索插入位置） */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      if (nums.empty()) {
        return 0;
      }
      int left = 0, right = nums.size() - 1;
      while (left <= right) {
        int mid = left + (right - left);
        if (nums[mid] == target) {
          return mid;
        } else if (nums[mid] < target) {
          left = mid + 1;
        } else if (nums[mid] > target) {
          right = mid - 1;
        }
      }
      return left;
    }
};

/* 此外还可以用线性循环O(N) 复杂度 */
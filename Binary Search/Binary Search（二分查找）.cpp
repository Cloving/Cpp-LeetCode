/* Binary Search（二分查找） */

/* 与题35基本一样 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
      if (nums.empty()) {
        return -1;
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
      return -1;
    }
};
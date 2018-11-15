/* Search in Rotated Sorted Array II（搜索旋转排序数组） */

/* 第一种：二分法 */
class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return true;
      } else if (nums[mid] < nums[right]) {
        if (nums[mid] < target && nums[right] >= target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else if (nums[mid] > nums[right]) {
        if (nums[mid] > target && nums[left] <= target) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        right--;
      }
    }
    return false;
  }
};

/* 第二种：直接遍历 */
class Solution {
public:
  bool search(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); ++i) {
      if (target == nums[i]) {
        return true;
      }
    }
    return false;
  }
};
/* Search in Rotated Sorted Array（搜索旋转排序数组） */

/* 第一种 */
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      // cout << left << right;
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > nums[right]) {
        if (nums[left] <= target && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }
    return -1;
  }
};

/* 第二种 */
class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) {
      return -1;
    }
    int firstArrayEndIndex = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > nums[i+1]) {
        firstArrayEndIndex = i;
        break;
      }
    }
    int res1 = binarySearch(nums, 0, firstArrayEndIndex, target);
    if (res1 != -1) {
      return res1;
    }
    int res2 = binarySearch(nums, firstArrayEndIndex+1, nums.size()-1, target);
    return res2 == -1 ? -1 : res2;
  }
  int binarySearch(vector<int>& nums, int left, int right, int target) {
    while(left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      }
    }
    return -1;
  }
};
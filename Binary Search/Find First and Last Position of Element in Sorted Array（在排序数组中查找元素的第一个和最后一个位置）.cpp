/* Find First and Last Position of Element in Sorted Array（在排序数组中查找元素的第一个和最后一个位置） */

/* 第一种：左右指针 */
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    while (left <= right) {
      if (nums[left] < target) {
        left++;
      }
      if (nums[right] > target) {
        right--;
      }
      if (nums[left] == target && nums[right] == target) {
        return {left, right};
      }
    }
    return {-1, -1};
  }
};


/* 第二种：二分查找 */
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) {
        return {-1, -1};
    }
    vector<int> res;
    int leftIndex = searchLeftIndex(nums, target);
    int rightIndex = searchRightIndex(nums, target);
    res.push_back(leftIndex != -1 ? leftIndex : -1);
    res.push_back(rightIndex != -1 ? rightIndex : -1);
    return res;
  }
  int searchLeftIndex(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return (left < nums.size() && nums[left] == target) ? left : -1; 
  }
  int searchRightIndex(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return (right >= 0 && nums[right] == target) ? right : -1; 
  }
};

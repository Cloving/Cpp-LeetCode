/* Two Sum - Input array is sorted Ⅱ（两数之和 - 输入有序数组Ⅱ） */

/**
 * 第一种：利用unordered_map，同时适用于没有排序的数组
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (temp.count(target-nums[i])) {
                return {temp[target-nums[i]], i};
            } else {
                temp[nums[i]] = i;
            }
        }
        return {};
    }
};

/**
 * 第二种：二分法，复杂度O(NlogN)
 */
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      int temp = target - nums[i], left = i+1, right = nums.size()-1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > temp) {
          right = mid - 1;
        } else if (nums[mid] < temp) {
          left = mid + 1;
        } else {
          return {i+1, mid+1};
        }
      }
    }
  }
};

/**
 * 第三种：左右对撞指针
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[left] + nums[right] == target) {
          return {left+1, right+1};
        } else if (nums[left] + nums[right] < target) {
          left++;
        } else {
          right--;
        }
      }
    }
};


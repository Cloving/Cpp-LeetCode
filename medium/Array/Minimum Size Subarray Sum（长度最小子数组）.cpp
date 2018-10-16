/* Minimum Size Subarray Sum（长度最小子数组） */

/* 第一种 */
class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int res = INT_MAX;
    int left = 0, sum = 0, len = nums.size();
    for (int i = 0; i < len; i++) {
      sum += nums[i];
      while (sum >= s && left <= i) {
        res = min(res, i-left+1);
        sum -= nums[left++];
      }
    }
    return res == INT_MAX ? 0 : res;
  }
};


/* 第二种 */
class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int res = INT_MAX, len = nums.size();
    vector<int> sum(len+1, 0);
    for (int i = 1; i < len+1; ++i) {
      sum[i] = sum[i-1] + nums[i-1];
    }
    for (int i = 0; i < len+1; ++i) {
      int left = i+1, right = n, target = sum[i] + s;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sum[mid] >= target) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
      if (left == n+1) {
        break;
      }
      res = min(res, left - i);
    }
    return res == INT_MAX ? 0 : res;
  }
};
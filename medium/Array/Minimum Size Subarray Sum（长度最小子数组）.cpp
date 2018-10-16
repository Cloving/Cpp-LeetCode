/* Minimum Size Subarray Sum（长度最小子数组） */


class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int res = INT_MAX;
    int left = 0, sum = 0, len = nums.size()-1;
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

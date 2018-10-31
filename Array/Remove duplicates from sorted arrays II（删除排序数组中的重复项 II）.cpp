class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    if (len <= 2) {
      return len;
    }
    int count = 1, i = 0, j = 1;
    while (j < len) {
      if (nums[i] == nums[j] && count == 0) {
        // 第二、三....次相等
        j++;
      } else {
        if (nums[i] == nums[j]) {
          // 第一次相等
          count--;
        } else {
          // 不相等
          count = 1;
        }
        nums[++i] = nums[j++];
      }
    }
    return i+1;
  }
};
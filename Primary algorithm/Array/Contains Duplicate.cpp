class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) {
      return false;
    } else {
      // 2018-8-13：不能使用sort(nums)
      sort(nums.begin(), nums.end());
      for (int i = 0, j = i+1; j < len; i++, j++) {
        if(!(nums[i]^nums[j])){
          return true;
        }
      }
      return false;
    }
  }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int sumValue = nums[0] + nums[1] + nums[2];
      int diff = abs(target - sumValue);
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); i++) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
          int tempSum = nums[i] + nums[left] + nums[right];
          int newDiff = abs(tempSum - target);
          if (newDiff < diff) {
            diff = newDiff;
            sumValue = tempSum;
          }
          if (tempSum > target) {
            right--;
          } else {
            left++;
          }
        }
      }
      return sumValue;
    }
};
/* Find Pivot Index（寻找数组的中心索引） */

/* 第一种：暴力求解 */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
          if (accumulate(nums.begin(), nums.begin() + i, 0) == accumulate(nums.begin()+i+1, nums.end(), 0)) {
            return i;
          }
        }
      return -1;
    }
};

/* 第二种：总和sum减去左边的和leftSum得到右边的和，然后对比 */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftSum = 0, rightSum = 0;
        for (int i = 0; i < nums.size(); i++) {
          sum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
          leftSum  = (i == 0) ? 0 : leftSum + nums[i-1];
          rightSum = sum - leftSum - nums[i];
          if (leftSum == rightSum) {
              return i;
          }
        }
      return -1;
    }
};

/* 第三种： 求总和给rightSum，然后逐渐减去左边的数，左边的和leftSum逐渐右移 */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int leftSum = 0, rightSum = 0;
        for (auto i : nums) {
            rightSum += i;
        }
        for (int i = 0; i < nums.size(); i++) {
            leftSum += nums[i];
            if (leftSum == rightSum) {
                return i;
            }
            rightSum -= nums[i];
        }
        return -1;
    }
};

/* 第四种： 自己看吧 */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int total = 0, sum = 0;
        for (auto i : nums) {
            total += i;
        }
        for (int i = 0; i < nums.size(); sum += nums[i++]) {
            if (sum * 2 == total - nums[i]) {
                return i;
            }
        }
        return -1;
    }
};


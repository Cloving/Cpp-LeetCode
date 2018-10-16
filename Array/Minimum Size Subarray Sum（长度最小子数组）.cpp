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
/*
 * 1、原数组2，3，1，2，4，3。新数组0，2，5，6，8，12，15
 * 2、遍历新数组的时候每次i相对于原数组都是前一个位置。第一个位置判断的就是0+s, 第二个位置判断的是2+s
 * 3、因为在第二个位置以后都有加上第一个位置的值，所以判断也需要2+s
 */
class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int res = INT_MAX, len = nums.size();
    vector<int> sum(len+1, 0);
    // 相当于在数组的前一位添加一个0，后面逐渐求和
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
      // 因为sum比nums多出一位，所以不用left-i+1
      res = min(res, left - i);
    }
    return res == INT_MAX ? 0 : res;
  }
};
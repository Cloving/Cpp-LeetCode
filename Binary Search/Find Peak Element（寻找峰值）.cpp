/* Find Peak Element（寻找峰值） */

/* 第一种：直接法 */
class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
     if (nums[i] < nums[i-1]) {
       return i-1;
     }
    }
    return nums.size() - 1;
  }
};

/* 第二种：二分查找法 */
class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < nums[mid + 1]) {
        /* left此时已经不再峰值可能的范围内 */
        left = mid + 1;
      } else {
        /* right还是有可能的 */
        right = mid;
      }
    }
    /* 最后一次一定是left = mid + 1导致的循环跳出 */
    /* 所以此时left == right, return left; 也可以*/
    return right;    
  }
};
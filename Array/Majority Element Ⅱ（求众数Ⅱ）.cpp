/* Majority Element Ⅱ（求众数Ⅱ） */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int> res;
      int m = 0, n = 0, mCount = 0, nCount = 0;
      for (int num : nums) {
        if (m == num) {
          mCount++;
        } else if (n == num) {
          nCount++;
        } else if (mCount == 0) {
          m = num;
          mCount = 1;
        } else if (nCount == 0) {
          n = num;
          nCount = 1;
        } else {
          mCount--;
          nCount--;
        }
      }
      mCount = 0, nCount = 0;
      for (int num : nums) {
        /* 以下两个if不能分开写*/
        /* 1、如果数组中都是一样的元素（m, n值相同） */
        /* 2、数组为全零数组(且由于m, n初始化为零) */
        /* 这样都会重复输出 */
        if (num == m) {
          mCount++;
        } else if (num == n) {
          nCount++;
        }
      }
      if (mCount > nums.size() / 3) {
        res.push_back(m);
      }
      if (nCount > nums.size() / 3) {
        res.push_back(n);
      }
      return res;
    }
};
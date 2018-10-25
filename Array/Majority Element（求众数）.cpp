/* Majority Element（求众数） */

/* 第一种：Hash表 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int, int> m;
      for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]]++;
        if (m[nums[i]] > nums.size()/2) {
          return nums[i];
        }
      }
    }
};

/* 第二种：摩尔投票法 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int res = 0, cur = 0;
      for (int k : nums) {
        if (cur == 0) {
          res = k;
          cur++;
        } else {
          (k == res) ? cur++ : cur--;
        }
      }
      return res;
    }
};

/* 第三种：位运算法 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int res = 0, len = nums.size();
      for (int i = 0; i < 32; i++) {
        int ones = 0, zeros = 0;
        for (int num : nums) {
          if (ones > len / 2) {
            break;
          }
          if (num & (1 << i)) {
            ones++;
          } else {
            zeros++;
          }
        }
        if (ones > zeros) {
          res |= (1 << i);
        }
      }
      return res;
    }
};

/* 第四种：排序法 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int left = 0, right = 0;
      while (right < nums.size()) {
        if (nums[right] != nums[right+1]) {
          if (right - left + 1 > nums.size() / 2) {
            return nums[right];
          } else {
            left = right + 1;
          }
        }
        right++;
      }
    }
};

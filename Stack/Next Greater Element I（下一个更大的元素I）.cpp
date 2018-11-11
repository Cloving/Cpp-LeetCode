/* Next Greater Element I（下一个更大的元素） */

/* 第一种 */
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < findNums.size(); i++) {
      int temp = findNums[i], j = 0;
      while (j < nums.size()) {
        if (temp == nums[j]) {
          break;
        }
        j++;
      }
      while (++j < nums.size()) {
        if (nums[j] > temp) {
          res.push_back(nums[j]);
          break;
        }
      }
      if (j >= nums.size()) {
        res.push_back(-1);
      }
    }
    return res;
  }
};

/* 第二种 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> ma;
        for (int i = 0; i < nums.size(); ++i) {
          ma[nums[i]] = i;
        }
        for (int i = 0; i < findNums.size(); ++i) {
          int index = ma[findNums[i]];
          while (++index < nums.size()) {
            if (nums[index] > findNums[i]) {
              res.push_back(nums[index]);
              break;
            }
          }
          if (index >= nums.size()) {
            res.push_back(-1);
          }
        }
        return res;
    }
};

/* 第三种 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
      vector<int> res;
      unordered_map<int, int> m;
      stack<int> s;
      for (int i = 0; i < nums.size(); ++i) {
        while (!s.empty() && s.top() < nums[i]) {
          m[s.top()] = nums[i];
          s.pop();
        }
        s.push(nums[i]);
      }
      for (int i = 0; i < findNums.size(); ++i) {
        res.push_back(m.count(findNums[i]) ? m[findNums[i]] : -1);
      }
      return res;
    }
};
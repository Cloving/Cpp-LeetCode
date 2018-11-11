/* Next Greater Element II（下一个更大的元素 II） */

/* 第一种 */
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int len = nums.size();
    vector<int> res(len, -1);
    for (int i = 0; i < len; ++i) {
      for (int j = i+1; j < i+len; ++j) {
        if (nums[j % len] > nums[i]) {
          res[i] = nums[j % len];
          break;
        }
      }
    }
    return res;
  }
};

/* 第二种 */
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int len = nums.size();
    vector<int> res(len, -1);
    stack<int> s;
    for (int i = 0; i < len * 2; ++i) {
      while (!s.empty() && nums[s.top()] < nums[i % len]) {
        res[s.top()] = nums[i % len];
        s.pop();
      }
      if (i < len) {
        s.push(i);
      }
    }
    return res;
  }
};
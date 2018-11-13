/* Largest Number（最大数） */

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    string res;
    /* 使用[](int& a, int& b){}也可以 */
    sort(nums.begin(), nums.end(), [](int a, int b) {
      return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });
    for (int i = 0; i < nums.size(); ++i) {
      res += to_string(nums[i]);
    }
    return res[0] == '0' ? "0" : res;
  }
};


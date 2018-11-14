/* Remove duplicates from sorted arrays（从排序数组中删除重复项） */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int len = nums.size();
        if (len <= 1) {
            return len; 
        }
        for (int j = 1; j < len; j++) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};

/* 如果不是排序数组呢 */
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i+1; j < len; j++) {
        if (nums[i] == nums[j]) {
          j = ++i;
        }
      }
      res.push_back(nums[i]);
    }
    return res;
  }
};


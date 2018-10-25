/* Maximum Subarray （最大子数组和）*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, curMax = 0;
        for (int num : nums) {
          /* curMax是循环到前一个位置时的最大值，
           * 如果加上num比当前的num小, 那么当前位置的最大值为num*/
          curMax = max(curMax + num, num);
          res = max(res, curMax);
        }
        return res;
    }
};


// 分治算法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    }
};
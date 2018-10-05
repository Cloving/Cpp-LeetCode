class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, curNum = 0;
        for (int num : nums) {
          curNum = max(curNum + num, num);
          res = max(res, curNum);
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
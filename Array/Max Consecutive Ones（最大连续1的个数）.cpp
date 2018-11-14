/* Max Consecutive Ones(最大连续1的个数) */

/* 第一种 */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt = (nums[i] == 0) ? 0 : cnt+1;
            res = max(res, cnt);
        }
        return res;
    }
};

/* 第二种 */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) * nums[i];
            res = max(res, sum);
        }
        return res;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= (i+1) ^ nums[i];
        }
        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n* (n+1)/2;
        for (int i = 0; i < nums.size(); i++) {
            res -= nums[i];
        }
        return res;
    }
};
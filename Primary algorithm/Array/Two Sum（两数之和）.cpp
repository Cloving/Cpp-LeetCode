/**
 * 利用unordered_map
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (temp.count(target-nums[i])) {
                return {temp[target-nums[i]], i};
            } else {
                temp[nums[i]] = i;
            }
        }
        return {};
    }
};
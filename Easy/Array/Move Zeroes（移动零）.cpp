/* Move Zeroes（移动零） */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 假设nums中都是零元素，那么直接返回
        if (accumulate(nums.begin(), nums.end(), 0) == 0) {
            return;
        }
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};
/* Move Zeroes（移动零） */

/* 第一种 */
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

/* 第二种 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                nums[left++] = nums[right];
            }
        }
        while (left < nums.size()) {
            nums[left++] = 0;
        }
    }
};
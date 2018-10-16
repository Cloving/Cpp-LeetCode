/* Remove Element（移除元素） */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                swap(nums[i], nums[j++]);
            }
        }
        return j;
    }
};
/**
 * 从排序数组中删除重复元素
 */
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
/**
 * 只出现一次的数字
 * 两个相同的元素按位异或后为0，只剩下最后一个单独的数字
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int value = nums[0];  
        for(int i = 1; i < len; i++) {
          	value ^= nums[i]; 
        }
        return value;
    }
};
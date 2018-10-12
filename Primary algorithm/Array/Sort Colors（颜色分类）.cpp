// 计数排序
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return;
        }
        vector<int> temp(3,0);
        for (int i = 0; i < len; i++) {
            temp[nums[i]]++;
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            while (temp[i]-- > 0) {
                nums.insert(nums.begin(), i);
                nums.pop_back();
            }
        }
    }
};

// 三路快排
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        for (int i = 0; i <= right; i++) {
            if (nums[i] == 0) {
                // left和right都是一个待存入的位置
                swap(nums[i], nums[left++]);
            } else if (nums[i] == 2) {
                swap(nums[i--], nums[right--]);
            }
        }
    }
};
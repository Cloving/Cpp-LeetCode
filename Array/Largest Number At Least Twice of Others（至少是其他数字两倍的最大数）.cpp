class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index = -1;
        int maxValue = *max_element(nums.begin(),nums.end());
        cout << maxValue;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxValue) {
                index = i;
            } else if (nums[i] * 2 > maxValue) {
                cout << nums[i] * 2;
                return -1;
            }
        }
        return index;
    }
};
/**
 * 首先将数组的前后部分反转，
 * 之后再反转整个数组
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (k>len) {
            k = k-len;
        }
        int n = len - k;
        nums = reverse(nums, 0, n - 1);
        nums = reverse(nums, n, len - 1);
        nums = reverse(nums, 0, len-1);
    }
    vector<int> reverse(vector<int>& array, int m, int n) {
        while (m < n) {
            int temp;
            temp = array[n];
            array[n] = array[m];
            array[m] = temp;
            m++;
            n--;
        }
        return array;
    }
};


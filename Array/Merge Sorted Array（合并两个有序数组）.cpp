/* Merge Sorted Array（合并两个有序数组） */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int length = m+n-1;
        m--;
        n--;
        while (m >= 0 && n >= 0) {
            nums1[length--] = (nums1[m] < nums2[n]) ? nums2[n--] : nums1[m--];
        }
        while (n >= 0) {
            nums1[length--] = nums2[n--];
        }
    }
};
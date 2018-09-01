/**
 * 第一种：
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

/**
 * 第二种：
 * 每一次都确定一个数组元素的新位置，
 * 总次数为数组的长度
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int tempValue, cur;
        int i = 0, start = 0, len = nums.size();
        int s = len;
        while (len < k) {
            k = k-len;
        }
        cur = nums[start];
        while (s--) {
            i = (i+k)%len;
            tempValue = nums[i];
            nums[i] = cur;
            // 2018-8-13：某个数组元素的新位置可能会在数组元素的开头
            if (start == i) {
                start++;
                i++;
                cur = nums[start];
            } else {
                cur = tempValue;
            }
        }
    }
};
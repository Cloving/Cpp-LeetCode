/**
 * 第一种：
 * 首先将数组的前后部分反转，
 * 之后再反转整个数组
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        while (nums.empty() || (k = k % len) == 0) {
            return;
        }
        reverse(nums.begin(), nums.begin()+len-k);
        reverse(nums.begin()+len-k, nums.end());
        reverse(nums.begin(), nums.end());
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
        int len = nums.size(), cur, tempValue;
        int s = len, start = 0, i = 0;
        if (k == len || k % len == 0) {
            return;
        }
        while (k > len) {
            k = k - len;
        }
        cur = nums[0];
        while (s--) {
            i = (i+k) % len;
            tempValue = nums[i];
            nums[i] = cur;
            // 2018-8-13：某个数组元素的新位置可能会在数组元素的开头
            // 如果新位置在数组的开头，下一个索引还没有被确定为哪个元素
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
/**
 * 第三种：
 * 建立新数组，直接旋转
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        if (nums.size() == 0) {
            return;
        }
        vector<int> t = nums;
        for (int i = 0; i < nums.size(); i++) {
            nums[(i+k) % length] = t[i];
        }
    }
};

// 第四种：利用STL的push_back和erase

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 0 || (k = k % len) == 0) {
            return;
        }
        for (int i = 0; i < len-k; i++) {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }
    }
};
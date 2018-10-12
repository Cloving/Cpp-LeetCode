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

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2) {
            if (nums[i] != nums[i+1]) {
                return nums[i];
            }
        }
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }
        // 基本迭代（second表示value, first表示key）
        for (auto& i : m) {
            if (i.second == 1) {
                return i.first;
            }
        }
        // 迭代器的迭代操作
        // for (auto it = m.begin(); it != m.end(); ++it) {
        //     if (it->second == 1) {
        //         return it->first;
        //     }
        // }
    }
};
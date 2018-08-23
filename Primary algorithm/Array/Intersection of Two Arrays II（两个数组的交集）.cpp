/**
 * 两个数组的交集
 * 第一种：将第一个数组的元素以及出现的个数分别作为键值对应起来
 * 遍历第二个数组，如果其中的元素在unordered_map中出现的个数大于1，
 * 说明是交集元素，如果仍然大于说明有重复
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ma;
        vector<int> res;
        for (auto i : nums1) {
            ma[i]++;
        }
        for (auto i : nums2) {
            if (ma[i]-- > 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};

/**
 * 两个数组的交集
 * 第二种：将两个数组分别排序
 * 如果元素相同则索引都自加1，如果1数组大于2数组，则2数组索引加一
 * 否则1数组索引加1
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        for (int i = 0, j = 0; i < nums1.size()&&j < nums2.size();) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        return res;
    }
};
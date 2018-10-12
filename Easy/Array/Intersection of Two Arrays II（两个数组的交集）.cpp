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


/*
 * 适用于一个数组元素少一个数组元素多的情况
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i < nums1.size(); i++) {
            int left = 0, right = nums2.size()-1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if (nums2[mid] == nums1[i]) {
                    res.push_back(nums1[i]);
                    nums2.erase(nums2.begin()+mid,nums2.begin()+mid+1);
                    break;
                } else if (nums2[mid] < nums1[i]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        return res;
    }
};


/*
 * 1、如果不排序，O(mn)
 * 2、如果m和n都在合理范围内，先排序，再一个一个对比，时间复杂度O(nlgn + mlgm + m+n)
 * 3、如果m远小于n, 对n排序。m排序（nlgn+mlgm+m+n）, m不排序(nlgn + mn)。
 *    如果在n里做binary search(二叉查找)，这样复杂度降低为nlgn+mlgn
 * 4、如果n很大，n只能存在disk上。只能把m load到内存，然后n一个一个的读进来，和m对比。
 *    这时m可以用hash存，这样复杂度就为O(n)
 */

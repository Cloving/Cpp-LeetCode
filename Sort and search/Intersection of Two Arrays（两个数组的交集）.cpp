/* Intersection of Two Arrays（两个数组的交集） */

/* 第一种 */
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> ma;
    vector<int> res;
    for (int i : nums1) {
      ma[i]++;
    }
    for (int j : nums2) {
      if (ma[j] > 0) {
        res.push_back(j);
        ma[j] = 0;
      }
    }
    return res;
  }
};

/* 第二种 */
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    for (int i = 0, j = 0; i < nums1.size() && j < num1.size();) {
      if (nums1[i] == nums2[j]) {
        if (!res.empty() && res.back() == nums1[i]) {
          i++;
          j++;
        } else {
          res.push_back(nums1[i]);
          i++;
          j++;
        }
      } else if (nums1[i] < nums2[j]) {
        i++;
      } else if (nums1[i] > nums2[j]) {
        j++;
      }
    }
    return res;
  }
};

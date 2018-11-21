/* Find the Duplicate Number（寻找重复数） */

/* 第一种：二分搜索 */
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size();
    while (left < right) {
      int mid = left + (right - left) / 2, cnt = 0;
      for (int num : nums) {
        if (num <= mid) {
          cnt++;
        }
      }
      /* cnt == mid说明1~mid之间的数都是正好只有1个不存在重复的 */
      if (cnt <= mid) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};

/* 第二种：快慢指针 */
/* 类似寻找有环链表 */
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0, t = 0;
    while (true) {
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow == fast) break;
    }
    while (true) {
      slow = nums[slow];
      t = nums[t];
      if (slow == t) break;
    }
    return slow;
  }
};

/* 第三种：位运算 */
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
      int bit = (1<<i), cnt1 = 0, cnt2 = 0;
      for (int j = 0; j < nums.size(); ++j) {
        if (j & bit) {
          cnt1++;
        }
        if (nums[j] & bit) {
          cnt2++;
        }
      }
      if (cnt2 > cnt1) {
        res += bit;
      }
    }
    return res;
  }
};


/* 第四种：排序(但是改变了数组) */
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] == nums[i+1]) {
        return nums[i];
      }
    }
  }
};

/* 第五种：hash表(但是增加了空间) */
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    unordered_map<int, int> ma;
    for (int num : nums) {
      ma[num]++;
    }
    for (int num : nums) {
      if (ma[num] != 1) {
        return num;
      }
    }
  }
};


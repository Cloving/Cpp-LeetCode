/**
 * 存在重复
 * 第一种：
 * 首先将数组排序，
 * 之后比较相邻两个数组是否相同
 */
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) {
      return false;
    } else {
      // 2018-8-13：不能使用sort(nums)
      sort(nums.begin(), nums.end());
      for (int i = 0, j = i+1; j < len; i++, j++) {
        if(!(nums[i]^nums[j])){
          return true;
        }
      }
      return false;
    }
  }
};

/**
 * 第二种：
 * 使用map
 */
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) {
      return false;
    } else {
      // 2018-8-13：int不是类类型，所以会进行零值初始化
      // 参考：https://stackoverflow.com/questions/25517794/default-contructor-of-unordered-map-the-bool-type-will-be-set-as-false
      map<int, int> res;
      for(auto i : nums) {
        if(++res[i]>1) {
          return true;
        }
      }
      return false;
    }
  }
};

/**
 * 第三种：
 * 使用unordered_map
 */
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) {
      return false;
    } else {
      unordered_map<int, bool> res;
      for(auto i : nums) {
        if(res[i] == true) {
          return true;
        }
        res[i] = true;
      }
      return false;
    }
  }
};

 /**
 * 第四种：
 * 使用set
 */
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) {
      return false;
    } else {
      set<int> res;
      for(auto i : nums) {
        if(res.find(i) != res.end()) {
          return true;
        } else {
          res.insert(i);
        }
      }
      return false;
    }
  }
};

 /**
 * 第五种：
 * 使用sort与unique
 */
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) {
      return false;
    } else {
      sort(nums.begin(), nums.end());
      return unique(nums.begin(), nums.end()) != nums.end();
    }
  }
};

/**
 * 第六种：
 * 使用set的构造函数
 */
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) {
      return false;
    } else {
      // 2018-8-13：构造指定范围的集合
      return set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
  }
};
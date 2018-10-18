/* Array Partition Ⅰ（数组拆分Ⅰ） */

/* 第一种 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

/* 第二种： 优化了一点*/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            sum += nums[i*2];
        }
        return sum;
    }
};

/*第三种: 手写快排实现*/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
      int sum = 0;
      quickSort(nums, 0, nums.size()-1);
      for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
      }
      return sum;
    }
    void quickSort(vector<int>& nums, int left, int right) {
      if (left < right) {
        int l = left, r = right;
        int target = nums[left];
        while (l < r) {
          while (l < r && nums[r] >= target) {
            r--;
          }
          nums[l] = nums[r];
          while (l < r && nums[l] <= target) {
            l++;
          }
          nums[r] = nums[l];
        }
        nums[l] = target;
        quickSort(nums, left, l-1);
        quickSort(nums, r+1, right);
      }
    }
};

/* 第四种：空间换时间 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {      
        int count[20001] = {0};
        for (auto num : nums) {
            ++count[num + 10000];
        }
        int sum = 0;
        int th = 0;
        for (int index = 0 ; index < 20001; ++index) {
            for (int i = 0; i < count[index]; ++i) {
                if (++th & 0x01) {
                    sum += index - 10000;  
                }
            }
        }
        return sum;
    }
};
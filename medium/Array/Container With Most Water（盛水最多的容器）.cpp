/* Container With Most Water（盛水最多的容器） */

/*
* 第一种：暴力破解
*/
class Solution {
public:
  int maxArea(vector<int>& height) {
    int res = 0;
    for (int i = 0; i < height.size(); i++) {
      for (int j = i; j < height.size(); j++) {
        res = max(res, (j-i) * min(height[i], height[j]));
      }
    }
    return res;
  }
};

/*
* 第二种：左右双指针
*/
class Solution {
public:
  int maxArea(vector<int>& height) {
    int left 
  }
};
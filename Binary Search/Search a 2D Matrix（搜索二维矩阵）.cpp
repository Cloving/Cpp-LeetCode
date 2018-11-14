/* Search a 2D Matrix（搜索二维矩阵） */

/* 二分查找 */
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    if (target < matrix[0][0] || target > matrix[m-1][n-1]) {
      return false;
    }
    int up = 0, down = m - 1;
    while (up <= down) {
      int mid = up + (down - up) / 2;
      if (matrix[mid][0] == target) {
        return true;
      } else if (matrix[mid][0] < target) {
        up = mid+1;
      } else if (matrix[mid][0] > target) {
        down = mid - 1;
      }
    }
    int left = 0, right = n - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (matrix[down][mid] == target) {
        return true;
      } else if (matrix[down][mid] > target) {
        right = mid - 1;
      } else if (matrix[down][mid] < target) {
        left = mid + 1;
      }
    }
    return false;
  }
};
/* Spiral Matrix（螺旋矩阵） */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> res;
      if (matrix.empty() || matrix[0].empty()) {
        return res;
      }
      // 不能使用if (matrix.size() == 0 || matrix[0].size() == 0)判断
      int m = matrix.size(), n = matrix[0].size();
      int circle = (min(m, n)+1)/2;
      for (int i = 0; i < circle; i++, m -= 2, n -=2) {
        for (int col = i; col < i + n; col++) {
          res.push_back(matrix[i][col]);
        }
        for (int row = i + 1; row < i + m; row++) {
          res.push_back(matrix[row][i+n-1])
        }
        if (m == 1 || n == 1) {
          break;
        }
        for (int col = i+n-2; col >= i; col--) {
          res.push_back(matrix[i+m-1][col])
        }
        for (int row = i+m-2; row > i; row--) {
          res.push_back(matrix[row][i]);
        }
      }
      return res;
    }
};


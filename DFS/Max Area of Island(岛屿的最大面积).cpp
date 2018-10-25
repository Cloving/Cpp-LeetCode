/* Max Area of Island(岛屿的最大面积) */

/* 第一种*/
class Solution {
public:
  vector<vector<int>> test{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int res = 0, m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] != 1) {
          continue;
        }
        int cnt = 0;
        calcMaxArea(grid, i, j, cnt, res);
      }
    }
    return res;
  }
  void calcMaxArea(vector<vector<int>>& grid, int i, int j, int& cnt, int& res) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) {
      return;
    }
    res = max(res, ++cnt);
    grid[i][j] *= -1;
    for (auto t : test) {
      calcMaxArea(grid, i+t[0], j+t[1], cnt, res);
    }
  }
};

/* 第二种*/
class Solution {
public:
  vector<vector<int>> test{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int res = 0, m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != 1) {
          continue;
        }
        int cnt = 0;
        queue<pair<int, int>> q{{{i, j}}};
        grid[i][j] *= -1;
        while (!q.empty()) {
          auto t = q.front();
          q.pop();
          res = max(res, ++cnt);
          for (auto te : test) {
            int x = t.first+te[0], y = t.second+te[1];
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] <= 0) {
              continue;
            }
            grid[x][y] *= -1;
            q.push({x,y});
          }
        }
      }
    }
    return res;
  }
};
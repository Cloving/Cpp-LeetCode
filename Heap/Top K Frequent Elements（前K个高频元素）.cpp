/* Top K Frequent Elements（前K个高频元素） */

/* 第一种 */
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int, int> ma;
    priority_queue<pair<int, int>> pr;
    for (int num : nums) {
      ++ma[num];
    }
    for (auto m : ma) {
      pr.push({m.second, m.first});
    }
    while (k--) {
      res.push_back(pr.top().second);
      pr.pop();
    }
    return res;
  }
};

/* 第二种 */
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    vector<vector<int>> temp(nums.size() + 1);
    unordered_map<int, int> ma;
    for (int num : nums) {
      ++ma[num];
    }
    for (auto m : ma) {
      temp[m.second].push_back(m.first);
    }
    for (int i = temp.size() - 1; i >= 0; --i) {
      for (int j = 0; j < temp[i].size(); ++j) {
        res.push_back(temp[i][j]);
        if (res.size() == k) {
          return res;
        }
      }
    }
  }
};

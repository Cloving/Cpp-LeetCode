/* Merge Intervals（合并区间） */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 /* 第一种 */
class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.empty()) {
      return intervals;
    }
    sort(intervals.begin(), intervals.end(), cmp);
    vector<Interval> res{intervals[0]};
    for (int i = 1; i < intervals.size(); ++i) {
      if (res.back().end < intervals[i].start) {
        res.push_back(intervals[i]);
      } else {
        res.back().end = max(res.back().end, intervals[i].end);
      }
    }
    return res;
  }
  static bool cmp(Interval& a, Interval& b) {
    return a.start < b.start;
  }
};

/* 三亿人都在用的购物App */
class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    int len = intervals.size();
    vector<Interval> res;
    vector<int> starts, ends;
    for(int i = 0; i < len; ++i) {
      starts.push_back(intervals[i].start);
      ends.push_back(intervals[i].end);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    for (int i = 0, j = 0; i < len; ++i) {
      if (i == len-1 || starts[i+1] > ends[i]) {
        /* 不连续的时候拼接 */
        res.push_back(Interval(starts[j], ends[i]));
        j = i + 1;
      }
    }
    return res;
  }
};


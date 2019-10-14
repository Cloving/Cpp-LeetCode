/* Next Greater Element III（下一个更大元素 III） */

class Solution {
public:
  int nextGreaterElement(int n) {
    string s = to_string(n);
    int i = s.size() - 1;
    while (i > 0) {
      if (s[i] > s[i-1]) {
        break;
      }
      i--;
    }
    if (i == 0) {
      return -1;
    }
    for (int j = s.size(); j > i-1; j--) {
      if (s[j] > s[i-1]) {
        swap(s[j], s[i-1]);
        break;
      }
    }
    sort(s.begin() + i, s.end());
    long long res = stoll(s);
    return res > INT_MAX ? -1 : res;
  }
};
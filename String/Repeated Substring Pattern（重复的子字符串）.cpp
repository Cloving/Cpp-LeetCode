/* Repeated Substring Pattern（重复的子字符串） */

/* 第一种 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      int len = s.size();
      for (int i = len/2; i > 0; --i) {
        if (len % i == 0) {
          int count = len / i;
          string t = "";
          for (int j = 0; j < count; ++j) {
            t += s.substr(0, i);
          }
          if (t == s) {
            return true;
          }
        }
      }
      return false;
    }
};

/* 第二种 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      int i = 1, j = 0, n = s.size();
      vector<int> dp(n + 1, 0);
      while (i < n) {
          if (s[i] == s[j]) dp[++i] = ++j;
          else if (j == 0) ++i;
          else j = dp[j];
      }
      return dp[n] && (dp[n] % (n - dp[n]) == 0);
    }
};


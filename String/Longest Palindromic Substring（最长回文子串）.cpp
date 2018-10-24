/* Longest Palindromic Substring（最长回文子串） */

/* 第一种 */
class Solution {
public:
    string longestPalindrome(string s) {
      if (s.size() < 2) {
        return s;
      }
      int len = s.size(), startIndex = 0, subLen = 0;
      for (int i = 0; i < len-1; i++) {
        verifyPalindrome(s, i, i, startIndex, subLen);
        verifyPalindrome(s, i, i+1, startIndex, subLen);
      }
      return s.substr(startIndex, subLen);
    }

    void verifyPalindrome(string s, int left, int right, int& startIndex, int& subLen) {
      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
      }
      if (subLen < right - left - 1) {
        subLen = right - left - 1;
        startIndex = left + 1;
      }
    }
};

/* 第二种 */
class Solution {
public:
    string longestPalindrome(string s) {
      if (s.size() < 2) {
        return s;
      }
      int i = 0, startIndex = 0, subLen = 0;
      while (i < s.size()) {
        if (s.size() - i <= subLen / 2) {
          break;
        }
        int left = i, right = i;
        while (right < s.size() - 1 && s[right+1] == s[right]) {
          right++;
        }
        i = right + 1;
        while (left > 0 && right < s.size() - 1 && s[left-1] == s[right+1]) {
          left--;
          right++;
        }
        if (subLen < right - left + 1) {
          subLen = right - left + 1;
          startIndex = left;
        }
      }
      return s.substr(startIndex, subLen);
    }
};

/* 第三种 */
class Solution {
public:
    string longestPalindrome(string s) {
      if (s.empty()) {
        return "";
      }
      int dp[s.size()][s.size()] = {0}, left = 0, right = 0, subLen = 0;
      for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < i; j++) {
          dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j+1][i-1]));
          if (dp[j][i] && subLen < i-j+1) {
            subLen = i-j+1;
            left = j;
            right = i;
          }
        }
        dp[i][i] = 1;
      }
      // 这里不能用subLen代替right-left+1，假如是单个字符组成的字符串就不符合
      return s.substr(left, right-left+1);
    }
};


/* 第四种 */
class Solution {
public:
    string longestPalindrome(string s) {
      
    }
};



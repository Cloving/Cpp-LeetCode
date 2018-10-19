/* Reverse Words in a String(翻转字符串里的单词) */

/* 第一种 */
class Solution {
public:
    void reverseWords(string &s) {
      reverse(s.begin(), s.end());
      int len = s.size(), cur = 0, storeIndex = 0;
      for (int i = 0; i < len; i++) {
        if (s[i] != ' ') {
          if (storeIndex != 0) {
            s[storeIndex++] = ' ';
          }
          cur = i;
          while (cur < len && s[cur] != ' ') {
            s[storeIndex++] = s[cur++];
          }
          reverse(s.begin()+storeIndex-(cur-i), s.begin()+storeIndex);
          i = cur;
        }
      }
      s.resize(storeIndex);
    }
};


/* 第二种 */
class Solution {
public:
    void reverseWords(string &s) {
      int i = 0, j = 0;
      while (s[0] == ' ') {
        s.erase(s.begin());
      }
      reverse(s.begin(), s.end());
      while (s[0] == ' ') {
        s.erase(s.begin());
      }
      while (j < s.size()) {
        if (s[j] == ' ') {
          reverse(s.begin() + i, s.begin() + j);
          i = ++j;
          while (j < s.size() && s[j] == ' ') {
            s.erase(s.begin() + j);
          }
        } else {
          j++;
        }
      }
      reverse(s.begin() + i, s.begin() + j);
    }
};

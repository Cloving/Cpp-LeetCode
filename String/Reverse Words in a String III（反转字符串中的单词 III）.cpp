/* Reverse Words in a String III（反转字符串中的单词 III） */

/* 第一种 */
class Solution {
public:
    string reverseWords(string s) {
       int left = 0, right = 0;
       while (right < s.size()) {
         if (s[right] == ' ') {
           reverse(s.begin() + left, s.begin() + right);
           left = ++right;
         } else {
           right++;
         }
       }
       reverse(s.begin() + left, s.begin() + right);
    }
};
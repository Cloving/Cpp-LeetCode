/* Reverse a Vowels of  a String（反转字符串中的原音字母） */

class Solution {
public:
  string reverseVowels(string s) {
    int left = 0, right = s.size() - 1;
    while (left <= right) {
      if (isVowels(s[left]) && isVowels(s[right])) {
        swap(s[left++], s[right--]);
      } else if (!isVowels(s[left])) {
        left++;
      } else {
        right--;
      }
    }
    return s;
  }
  bool isVowels(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};
/* String Compression（压缩字符串） */

/* Wrong Version */
class Solution {
public:
  int compress(vector<char>& chars) {
    if (chars.size() == 1) {
      return 1;
    }
    int i = 0, j = 0, cur = 0;
    while (i < chars.size()) {
      while (j < chars.size() && chars[i] == chars[j]) {
        j++;
      }
      chars[cur++] = chars[i];
      if (j-i == 1) {
        /* 即使字符只出现一次，仍然需要对i建立新的索引 */
        continue;
      }
      for (char c : to_string(j-i)) {
        chars[cur++] = c;
      }
      i = j;
    }
    return cur;
  }
};

/* Right Version */
class Solution {
public:
  int compress(vector<char>& chars) {
    if (chars.size() == 1) {
      return 1;
    }
    int cur = 0;
    for (int i = 0, j = 0; i < chars.size(); i = j) {
      while (j < chars.size() && chars[i] == chars[j]) {
        j++;
      }
      cout << j; 
      chars[cur++] = chars[i];
      if (j-i == 1) {
        continue;
      }
      for (char c : to_string(j-i)) {
        chars[cur++] = c;
      }
    }
    return cur;
  }
};
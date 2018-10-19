class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int len = s.size(), left = 0, right = 0, storeIndex = 0;
        for (int i = 0; i < len; i++) {
          while (s[i++] == ' ');
          left = i - 1;
          while (s[i++] != ' ');
          right = i - 2;
          reverse(s.begin()+left, s.begin()+right+1);
        }
    }
};

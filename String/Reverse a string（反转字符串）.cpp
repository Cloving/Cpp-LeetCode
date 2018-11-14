/*  Reverse a string（反转字符串） */

/* 第一种 */
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};


/* 第二种 */
class Solution {
public:
    string reverseString(string s) {
        for (int i = 0, j = s.size()-1; i <= j; i++, j--) {
            swap(s[i], s[j]);
        }
        return s;
    }
};
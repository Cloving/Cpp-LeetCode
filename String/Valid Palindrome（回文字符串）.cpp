/* Valid Palindrome（回文字符串） */

// 转换成小写字母tolower
class Solution {
public:
    bool isPalindrome(string s) {
        int i= 0, j = s.length()-1;
        while(i<j) {
            if (!isalnum(s[i])) {
                i++;
            } else if (!isalnum(s[j])) {
                j--;
            } else if (toupper(s[i]) != toupper(s[j])) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
};
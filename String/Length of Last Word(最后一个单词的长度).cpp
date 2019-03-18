/* Length of Last Word(最后一个单词的长度) */

/* 第一种 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int len = s.size(), res = 0;
        int index = len - 1;
        while (index >= 0) {
            if (s[index] == ' ') {
                index--;
            } else {
                break;
            }
        }
        if (index == -1) {
            return 0;
        }
        while (index >= 0) {
            if (s[index] != ' ') {
                res++;
                index--;
            } else {
                break;
            }
        }
        return res;
    }
};

/* 第二种 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        while (s[0] == ' '){
            s.erase(s.begin());
        }
        int index = s.find(' ');
        if (index == string::npos) {
            return s.size();
        } else {
            return index;
        }
    }
};


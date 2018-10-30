/* Longest Common Prefix（最长共同前缀）*/

/* 第一种: 与第二、三种差不多，只不过写法不一样 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string res = "";
        for (int col = 0; col < strs[0].size(); col++) {
            char c = strs[0][col];
            for (int row = 0; row < strs.size(); row++) {
                if (col >= strs[row].size() || c != strs[row][col]) {
                    return res;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};

/* 第二种 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        for (int col = 0; col < strs[0].size(); col++) {
            for (int row = 0; row < strs.size() - 1; row++) {
                if (col >= strs[row].size() || strs[row][col] != strs[row+1][col]) {
                    return strs[0].substr(0,col);
                }
            }
        }
        return strs[0];
    }
};

/* 第三种 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string res;
        for (int col = 0; col < strs[0].size(); col++){
            for (int row = 0; row < strs.size()-1; row++) {
                if (col >= strs[row].size() || strs[row][col] != strs[row+1][col]) {
                    return res;
                }
            }
            res.push_back(strs[0][col]);
        }
        return res;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string res = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 0; j < strs.size(); j++) {
                if (i > strs[j].size() || strs[j][i] != c) {
                    return res;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        } 
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 0; j < strs.size()-1; j++) {
                if (i > strs[j].size() || strs[j][i] != strs[j+1][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
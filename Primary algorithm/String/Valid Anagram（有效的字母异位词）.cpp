class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int test[26] = {0};
        for (auto i : s) {
            test[i-'a']++;
        }
        for (auto j : t) {
            test[j-'a']--;
            if (test[j-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
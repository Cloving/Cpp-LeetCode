class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) {
            return 0;
        }
        int hLength = haystack.size(), nLength = needle.size();
        if (hLength < nLength) {
            return -1;
        }
        for (int i = 0; i < hLength-nLength+1; i++) {
            for(int j = 0; j < nLength; j++) {
                if(haystack[i+j] != needle[j]) {
                    break;
                } else if (j == nLength-1){
                    return i;
                }
            }
        }
        return -1;
    }
};
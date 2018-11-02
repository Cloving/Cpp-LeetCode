/* Count and Say（计数与读法） */

// 递归
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string str = countAndSay(n-1);
        int count = 1;
        string res = "";
        for (int i = 0; i < str.size(); i++) {
            if (i+1 < str.size() && str[i] == str[i+1]) {
                count++;
            } else {
                res = res + to_string(count) + str[i];
                count = 1;
            }
        }
        return res;
    }
};

// 从头至尾
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) {
            return "0";
        }
        string res = "1";
        int count = 1;
        // 初始已有一次，所以执行--n
        while(--n) {
            string temp = "";
            for (int i = 0; i < res.size(); i++) {
                if (i+1<res.size() && res[i] == res[i+1]) {
                    count++;
                } else {
                    temp = temp + to_string(count) + res[i];
                    count = 1;
                }
            }
            res = temp;
        }
        return res;
    }
};
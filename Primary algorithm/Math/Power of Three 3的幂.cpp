class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && 1162261467 % n == 0;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        // log10()是log以10为底的，log()是log以e为底的，其他数利用换底公式
        return n > 0 && int(log10(n)/log10(3)) - log10(n)/log10(3) == 0;
    }
};

/* 循环 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && n % 3 == 0) {
            n = n / 3;
        }
        return n == 1;
    }
};

/* 递归 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        if (n % 3 == 0) {
            return isPowerOfThree(n/3);
        } else {
            return false;
        }
    }
};
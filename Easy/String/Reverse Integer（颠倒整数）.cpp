class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) {
                return 0;
            } else {
                res = res * 10 + x % 10;
                x = x / 10;
            }
        }
        return res;
    }
};

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int temp = res * 10 + x % 10;
            if (temp / 10 != res) {
                // 说明溢出了
                // 参考：https://blog.csdn.net/xiaofei0859/article/details/77285021
                return 0;
            } else {
                res = temp;
                x = x / 10;
            }
        }
        return res;
    }
};
/* Reverse Integer（反转整数） */

/* 第一种 */
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int temp = res * 10 + x % 10;
            if (temp / 10 != res) {
                return 0;
            } else {
                res = temp;
                x = x / 10;
            }
        }
        return res;
    }
};

/* 第二种 */
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX/10) {
                return 0;
            } else {
                res = res * 10 + x % 10;
                x = x / 10;
            }
        }
        return res;
    }
};
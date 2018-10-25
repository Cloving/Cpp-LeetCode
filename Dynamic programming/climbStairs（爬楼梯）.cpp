/* climbStairs（爬楼梯）*/


class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res.back();
    }
};

/* 递归也可以但是会超时 */
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 0) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
}

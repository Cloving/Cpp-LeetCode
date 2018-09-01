/**
 * 买卖股票的最佳时间 Ⅱ
 * 可以多次买卖的那种
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size(), res = 0;
        for (int i = 0; i < len-1; i++) {
            if (prices[i] < prices[i+1]) {
                res += prices[i+1] - prices[i];
            }
        }
        return res;
    }
};
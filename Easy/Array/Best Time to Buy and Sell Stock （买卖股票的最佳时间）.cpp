/* Best Time to Buy and Sell Stock （买卖股票的最佳时间） */

/**
 * 买卖股票的最佳时间 Ⅱ
 * 单次买卖的那种
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size(), buyPrice = INT_MAX;
        int res = 0;
        for(int i = 0; i < len; i++) {
            buyPrice = min(buyPrice, prices[i]);
            res = max(res, prices[i] - buyPrice);
        }
        return res;
    }
};
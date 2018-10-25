/* Best Time to Buy and Sell Stock （买卖股票的最佳时间） */

/**
 * 买卖股票的最佳时间 Ⅱ
 * 单次买卖的那种
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, curMinBuyPrice = INT_MAX;
        for (int price : prices) {
            curMinBuyPrice = min(curMinBuyPrice, price);
            res = max(res, price - curMinBuyPrice);
        }
        return res;
    }
};

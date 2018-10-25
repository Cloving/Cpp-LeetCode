/* Best Time to Buy and Sell Stock Ⅱ（买卖股票的最佳时间 Ⅱ） */

/**
 * 买卖股票的最佳时间 Ⅱ
 * 可以多次买卖的那种
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* prices.size()的类型是unsigned long int类型，如果列表为空那么prices.size()-1为2^64-1 */
        int len = prices.size(), res = 0;
        for (int i = 0; i < len-1; i++) {
            if (prices[i] < prices[i+1]) {
                res += prices[i+1] - prices[i];
            }
        }
        return res;
    }
};
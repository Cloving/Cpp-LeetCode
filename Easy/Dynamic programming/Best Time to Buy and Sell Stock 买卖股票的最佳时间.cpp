class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, buyPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            buyPrice = min(buyPrice, prices[i]);
            res = max(res, prices[i] - buyPrice);
        }
        return res;
    }
};
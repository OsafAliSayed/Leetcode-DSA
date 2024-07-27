class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int buyPrice = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            maxP = max(maxP, prices[i] - buyPrice);
            buyPrice = min(prices[i], buyPrice);
        }
        return maxP;
    }
};
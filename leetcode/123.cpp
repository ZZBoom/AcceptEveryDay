class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int buy1 = -prices[0], sale1 = 0;
        int buy2 = -prices[0], sale2 = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            buy1 = std::max(buy1, -prices[i]);
            sale1 = std::max(sale1, buy1 + prices[i]);
            buy2 = std::max(buy2, sale1 - prices[i]);
            sale2 = std::max(sale2, buy2 + prices[i]);
        }
        return sale2;
    }
};

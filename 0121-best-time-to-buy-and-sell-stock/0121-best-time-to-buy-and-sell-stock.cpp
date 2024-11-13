class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int result = 0;

        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);

            result = max(result, prices[i]-minPrice);
        }
        return result;
    }
};
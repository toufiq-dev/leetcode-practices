class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    int maxProfit(vector<int>& prices) {
        int dayPrice = INT_MAX;
        int profit = 0;

        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < dayPrice) {
                dayPrice = prices[i];
            }

            if(prices[i] - dayPrice > profit) {
                profit = prices[i] - dayPrice;
            }
        }

        return profit;
    }
};
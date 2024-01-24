class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest_price = INT_MAX, profit = 0;
        for (int price : prices) {
            lowest_price = min(lowest_price, price);
            profit = max(profit, price - lowest_price);
        }

        return profit;
    }
};
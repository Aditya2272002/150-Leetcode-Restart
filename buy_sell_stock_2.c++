class Solution {
public:
    int helper(vector<int>& prices, int i, int canBuy, int profit, vector<vector<int>>& dp) {
        if (i >= prices.size())
            return 0;

        if(dp[i][canBuy]!=-1){
            return dp[i][canBuy];
        }

        // Can Buy
        if (canBuy)
            profit = max(-prices[i] + helper(prices, i + 1, 0, profit, dp),
                         0 + helper(prices, i + 1, 1, profit, dp));

        // Can NotBuy
        else
            profit = max(prices[i] + helper(prices, i + 1, 1, profit, dp),
                         0 + helper(prices, i + 1, 0, profit, dp));

        return dp[i][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int i = 0;
        int canBuy = 1;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, i, canBuy, profit, dp);
    }
};

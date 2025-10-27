class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        vector<vector<int>> dp(n+1, vector<int>(2, INT_MIN / 2));

        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);

            if (i == n) {
                dp[i][0] = max(dp[i][0], dp[i-1][1] + prices[i]);
            }
        }
        return max(dp[n][0], dp[n][1]);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(prices.size()+1, vector<int>(5, INT_MIN / 2));
        prices.insert(prices.begin(), 0);

        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
        }

        int res = 0;
        for (int i = 0; i < 5; i++) {
            res = max(res, dp[n][i]);
        }
        return res;
    }
};


// dp[i][j]

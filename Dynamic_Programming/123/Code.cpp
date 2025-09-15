class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector(4, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = INT_MIN;
        dp[0][3] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = max(dp[i-1][1], prices[i] + dp[i-1][0]);
            dp[i][2] = max(dp[i-1][2], -prices[i] + dp[i-1][1]);
            dp[i][3] = max(dp[i-1][3], prices[i] + dp[i-1][2]);
        }

        return max(dp[n-1][3],max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]));
    }
};


// dp[i][0] : the maximum profit during ith day holding the first stock
// dp[i][1] : the maximum profit during ith day selling the first stock
// dp[i][2] : the maximum profit during ith day holding the second stock
// dp[i][3] : the maximum profit during ith day selling the second stock



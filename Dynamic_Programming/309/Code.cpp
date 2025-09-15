class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(4, 0));

        dp[0][0] = -10000;
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        dp[0][3] = -10000;
        //0: cooldown
        //1: idle
        //2: hold
        //3: sell
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][3];
            dp[i][1] = max(max(dp[i-1][0],dp[i-1][1]),max(dp[i-1][2],dp[i-1][3]));
            dp[i][2] = max(max(dp[i-1][2], dp[i-1][1]-prices[i]), dp[i-1][0]-prices[i]);
            dp[i][3] = dp[i-1][2] + prices[i];
        }

        return max(max(dp[n-1][0],dp[n-1][1]),max(dp[n-1][2],dp[n-1][3]));
    }
};

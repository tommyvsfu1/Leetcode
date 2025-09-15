// dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + costs[i]
// dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + costs[i]
// dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + costs[i]

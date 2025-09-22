// dp[i][c] : the number of different expressions in nums[1:i] that you can build, which evaluates to c.


// dp[i][c] = dp[i-1][c-nums[i]] + dp[i-1][c+nums[i]]

注意: 實作上會把array用offset來處理negative target

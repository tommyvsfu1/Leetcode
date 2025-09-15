dp[i][0]: maximum number of consecutive 1's until i-th element, and hasn't fliped the 0 yet
dp[i][1]: maximum number of consecutive 1's until i-th element, and has fliped the 0.

這題最後的aggregation是要考慮max(dp[i][j]) for all i and j=0,1 ，因為dp[i][]是會考量i-th element必須在consecutive 1中


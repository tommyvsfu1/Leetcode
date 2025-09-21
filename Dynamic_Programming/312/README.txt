這題難點在於，在構思dp[i][j]如何得到時候，要透過決定最後一個設爆的ballon k-th，來去沿用dp[i][k-1]跟dp[k+1][j]的結果。正常DP題目通常是決定先設爆i,i-1,i+1,j-1,j,j+1之類，但這題要從最後一個射爆來想  
而k-th ballon則是會跟nums[i-1]跟nums[j+1]配對，因為如果從小區間慢慢求到大區間，代表外面區間還沒有被設爆 (反過來從top down想的話也是)

// dp[i][j] : maximum coins you can collect in nums[i:j]

// dp[i][j] = dp[i][k-1] + dp[k+1][j] + nums[k] * nums[i-1] * nums[j+1]


// {i .... k-1}{k}{k+1 ... j}

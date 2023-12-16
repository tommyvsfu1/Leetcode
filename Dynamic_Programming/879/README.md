```
轉移方程: dp[i][person][profit]: from the first i projects, how many of schemes s.t. we just use person and earn profit.

dp[i][person][profit] = dp[i-1][person][profit] + dp[i-1][person-x][profit-y] // 不選擇i方案或選擇i方案 

但因為這題為了降低時間複雜度，我們要把大於minProfit的部分全部歸類在minProfit，所以我們會把轉移方程的寫法改成從i 推演到 i+1 這種方式
dp[i][person][profit] =>
    dp[i+1][person][profit] += dp[i][person][profit]
    dp[i+1][person+x][min(minProfit, profit+y)] += dp[i][person][profit]
```
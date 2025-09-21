375. Guess Number Higher or Lower II

規則：猜一個數字 k → 馬上付出 cost = k。

然後根據結果：

答案在左邊 → 縮小到 [i, k-1]

答案在右邊 → 縮小到 [k+1, j]

題目要求 最壞情況下的最小花費，所以要：
dp[i][j] = min(dp[i][j], k + max(dp[i][k-1],dp[k+1][j]))

i  X X X X X X k X X X X X X X X  j

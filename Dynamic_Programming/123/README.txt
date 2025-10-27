Version 1
// dp[i][0] : the maximum profit during ith day holding the first stock
// dp[i][1] : the maximum profit during ith day selling the first stock
// dp[i][2] : the maximum profit during ith day holding the second stock
// dp[i][3] : the maximum profit during ith day selling the second stock


Version 2
// dp[i][0] : the maximum profit during ith day no hold
// dp[i][1] : the maximum profit during ith day holding the first stock
// dp[i][2] : the maximum profit during ith day selling the first stock (實際上value也等同於the maximum profit during ith day to after selling the first stock and no hold 2nd stock，所以這裡直接忽略這個state，但實際上是因為value相等，就直接不recurrence)
// dp[i][3] : the maximum profit during ith day holding the second stock
// dp[i][4] : the maximum profit during ith day selling the second stock

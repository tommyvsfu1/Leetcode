// dp[i][k] : the minimal number of characters that you need to change to divide the s[1:i] into k substrings.
/*
X X X X X X [j ... i]
<   k-1    ><kth set>

dp[i][k] = min {dp[j-1][k-1] + helper(s, j, i) }, j = 1 ... i
*/

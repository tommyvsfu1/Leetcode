// dp[i][k] : the minimal number of characters that you need to change to divide the s[1:i] into k substrings.

code.cpp是最新版本，改用另一個Palin提前計算好[j...i]區間需要改多少個字元才能變成Palindrome


/*
X X X X X X [j ... i]
<   k-1    ><kth set>

dp[i][k] = min {dp[j-1][k-1] + helper(s, j, i) }, j = 1 ... i
*/

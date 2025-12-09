class Solution {
public:
    int palindromePartition(string s, int K) {
        int n = s.size();
        s.insert(s.begin(), '#');
        vector<vector<int>> Palin(n+1, vector<int>(n+1, 0));
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i+len-1 <= n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j])  {
                    if (i+1 <= n && j-1 >= 1) {
                        if (len >= 3) {
                            Palin[i][j] = Palin[i+1][j-1];
                        }
                    }
                }
                else {
                    if (i+1 <= n && j-1 >= 1) {
                        if (len == 2) {
                            Palin[i][j] = 1;
                        }
                        else {
                            Palin[i][j] = 1 + Palin[i+1][j-1];
                        }
                    }
                }
            }
        }

        vector<vector<int>> dp(K+1, vector<int>(n+1, INT_MAX/2));
        dp[0][0] = 0;
        for (int k = 1; k <= K; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = i; j >= 0; j--) {
                    if (j-1 < k-1) break;
                    dp[k][i] = min(dp[k][i], dp[k-1][j-1] + Palin[j][i]);
                }
            }
        }
        return dp[K][n];
    }
};


// [X X X X X X X X][X X X X]
//                   j     i

// dp[k][i] = min(dp[k][i], dp[k-1][j-1] + Count(j, i));
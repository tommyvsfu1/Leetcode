class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<int>> IsPalin(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            IsPalin[i][i] = true;
        for (int i = 0; i + 1 < n; i++) {
            IsPalin[i][i+1] = (s[i] == s[i+1]);
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j])
                    IsPalin[i][j] = IsPalin[i+1][j-1];
            }
        }

        vector<int> dp(n, 0);
        for (int i = k-1; i < n; i++) {
            dp[i] = ((i>=1) ? dp[i-1] : 0);
            for (int j = 0; j <= i-k+1; j++) {
                if (j >= 1)
                    dp[i] = max(dp[i], dp[j-1] + IsPalin[j][i]);
                else
                    dp[i] = max(dp[i], IsPalin[j][i]);
            }
        }
        return dp[n-1];
    }
};

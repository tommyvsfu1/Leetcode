class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        s1.insert(s1.begin(), '0');
        s2.insert(s2.begin(), '0');

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= m; i++)
            dp[i][0] = 0;
        for (int j = 1; j <= n; j++)
            dp[0][j] = INT_MAX / 2;


        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = dp[i-1][j] + 1;
                }
            }
        }


        int len = INT_MAX / 2;
        int pos = 0;
        for (int i = 1; i <= m; i++) {
            if (dp[i][n] < len) {
                len = dp[i][n];
                pos = i;
            }
        }

        if (len >= (INT_MAX/2)) return "";

        return s1.substr(pos-len+1, len);



    }
};

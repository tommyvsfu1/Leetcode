class Solution {
public:
    int countOne(string s) {
        int res = 0;
        for (auto c : s) {
            if (c == '1') res++;
        }
        return res;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();

        vector<vector<int>> count(N, vector<int>(2, 0));
        for (int i = 0; i < N; i++) {
            int cnt = countOne(strs[i]);
            count[i][1] = cnt;
            count[i][0] = strs[i].size() - cnt;
        }

        vector<vector<int>> dp(101, vector<int>(101, 0));

        for (int i = 0; i < N; i++) {
            int one = count[i][1];
            int zero = count[i][0];

            auto dp2 = dp;
            for (int a = 0; a <= 100; a++) {
                for (int b = 0; b <= 100; b++) {
                    if (a >= zero && b >= one) {
                        dp[a][b] = max(dp[a][b], dp2[a-zero][b-one] + 1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int N = rods.size();
        int offset = 5000;

        vector<int> dp(2*offset+1, -1);

        dp[0 + offset] = 0;
        for (int i = 0; i < N; i++) {
            int l = rods[i];

            auto dp_old = dp;

            for (int diff = -offset; diff <= offset; diff++) {

                if (dp_old[diff + offset] == -1) continue;

                if (diff + l < offset)
                    dp[diff+l+offset] = max(dp[diff+l+offset], dp_old[diff+offset] + l);
                if (diff - l >= -offset)
                    dp[diff-l+offset] = max(dp[diff-l+offset], dp_old[diff+offset]);
            }
        }
        return dp[offset];
    }
};




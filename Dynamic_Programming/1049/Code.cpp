class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int n = stones.size();
        stones.insert(stones.begin(), 0);
        vector<vector<int>> dp(n+1, vector<int>(2*3000+1, 0));

        int offset = 3000;
        dp[0][0 + offset] = 1;
        for (int i = 1; i <= n; i++) {
            auto dp2 = dp;

            for (int c = -3000; c <= 3000; c++) {
                if (c + stones[i] + offset <= 6000)
                    dp[i][c+offset] |= dp2[i-1][c+stones[i]+offset];
                if (c - stones[i] + offset >= 0)
                    dp[i][c+offset] |= dp2[i-1][c-stones[i]+offset];
            }
        }

        for (int c = 0; c <= 3000; c++)
            if (dp[n][c+offset]) return c;
        return 0;

    }
};
// class Solution {
// public:
//     int lastStoneWeightII(vector<int>& stones) {
//         int n = stones.size();
//         stones.insert(stones.begin(), 0);
//         vector<vector<int>> dp(n+1, vector<int>(3001, 0));

//         dp[0][0] = 1;
//         for (int i = 1; i <= n; i++) {
//             auto dp2 = dp;
//             for (int c = 0; c <= 3000; c++) {
//                 if (c + stones[i] <= 3000)
//                     dp[i][c] |= dp2[i-1][c+stones[i]];
//                 if (stones[i] - c >= 0)
//                     dp[i][c] |= dp2[i-1][stones[i] - c];
//                 if (c - stones[i] >= 0)
//                     dp[i][c] |= dp2[i-1][c-stones[i]];
//             }
//         }

//         int res = 0;

//         for (int c = 0; c <= 3000; c++)
//             if (dp[n][c] == 1) return c;
//         return 0;        
//     }
// };

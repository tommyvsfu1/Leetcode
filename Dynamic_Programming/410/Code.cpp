class Solution {
public:
    int splitArray(vector<int>& nums, int K) {
        

        int n = nums.size();
        nums.insert(nums.begin(), 0);

        vector<vector<int>> dp(K+1, vector<int>(n+1, INT_MAX/2));
        dp[0][0] = 0;
        for (int k = 1; k <= K; k++) {
            for (int i = 1; i <= n; i++) {
                int sum = 0;
                for (int j = i; j >= 0; j--) {
                    if (j-1 < k-1) break;
                    sum += nums[j];
                    dp[k][i] = min(dp[k][i], max(dp[k-1][j-1], sum));
                }
            }
        }
        return dp[K][n];
    }
};

// //       k-1          
// // [X X X X X X X X][X X X X]
// //                   j     i

// // dp[k][j]

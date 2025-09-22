class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);
        int B = 1000;
        vector<vector<int>> dp(n+1, vector<int>(2*B+1, 0)); // -1000(0) ... 1000(2000)

        dp[0][B] = 1;
        for (int i = 1; i <= n; i++) {
            for (int c = -B; c <= B; c++) {
                int j = c + B;
                int left = (j-nums[i] >= 0) ? dp[i-1][j-nums[i]] : 0;
                int right = (j+nums[i] <= 2*B) ? dp[i-1][j+nums[i]] : 0;
                dp[i][j] = left + right;
            }
        }
        return dp[n][target+B];
    }
};

// dp[i][c] : the number of different expressions in nums[1:i] that you can build, which evaluates to c.


// dp[i][c] = dp[i-1][c-nums[i]] + dp[i-1][c+nums[i]]

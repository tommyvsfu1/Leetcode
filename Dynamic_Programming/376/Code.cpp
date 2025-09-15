class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2, 0));

        if (n == 1) return 1;
    
        dp[0][0] = 1;
        dp[0][1] = 1;
        if (nums[1]-nums[0] < 0)
            dp[1][0] = 2;
        else if (nums[1] - nums[0] > 0)
            dp[1][1] = 2;
        else {
            dp[1][0] = 1;
            dp[1][1] = 1;
        }
        for (int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], (nums[i] - nums[i-1] < 0) ? (dp[i-1][1] + 1) : 1);
            dp[i][1] = max(dp[i-1][1], (nums[i] - nums[i-1] > 0) ? (dp[i-1][0] + 1) : 1);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};

// dp[n][0] // ending difference is negative
// dp[n][1] // ending difference is positive

// dp[i][0] = max(dp[i-1][0], (nums[i] - nums[i-1] < 0) ? dp[i-1][1] : 0);
// dp[i][1] = max(dp[i-1][1], (nums[i] - nums[i-1] > 0) ? dp[i-1][0] : 0);

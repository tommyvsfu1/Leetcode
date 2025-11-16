class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        int n = nums.size();

        reverse(nums.begin(), nums.end());

        vector<vector<long long>> dp(n+1, vector<long long>(2, INT_MIN / 2));
        nums.insert(nums.begin(), 0);

        dp[0][0] = 0;
        dp[0][1] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max((long long)nums[i], (long long)(nums[i] + dp[i-1][1]) );
            dp[i][1] = max((long long)-nums[i], (long long)(-nums[i] + dp[i-1][0]));
        }

        long long res = INT_MIN;
        for (int i = 1; i <= n; i++) {
            res = max(res, dp[i][0]);
        }
        return res;
    }
};

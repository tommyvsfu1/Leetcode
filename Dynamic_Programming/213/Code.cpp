class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0],nums[1]);
        if (n == 3) return max(nums[0], max(nums[1],nums[2]));

        int res1 = nums[0] + houseRobber1(nums, 2, n-2);
        int res2 = nums[n-1] + houseRobber1(nums, 1, n-3);
        int res3 = houseRobber1(nums, 1, n-2);

        return max(res1, max(res2, res3));
    }
    int houseRobber1(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        vector<vector<int>> dp(n, vector<int>(2, 0));

        if (n <= 0) return 0;
        if (n == 1) return nums[start];

        dp[0][1] = nums[start];
        for (int i = start + 1; i <= end; i++) {
            int index = i - start;
            dp[index][0] = max(dp[index-1][0], dp[index-1][1]);
            dp[index][1] = nums[i] + dp[index-1][0];
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> seq(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            auto iter = lower_bound(seq.begin(), seq.end(), nums[i]);
            *iter = nums[i];
        }

        for (int i=n-1; i>= 0; i--) {
            if (seq[i] != INT_MAX) return i+1;
        }

        return 0;
    }
};
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();

//         vector<int> dp(n+1, 1);

//         nums.insert(nums.begin(), 0);
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j < i; j++) {
//                 if (nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//         }
        
//         int res = 0;
//         for (int i = 1; i <= n; i++) {
//             res = max(res, dp[i]);
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> presum;
    int splitArray(vector<int>& nums, int K) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);
        vector<vector<int>> dp(n+1, vector<int>(K+1, INT_MAX));

        presum.resize(n+1, 0);
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += nums[i];
            presum[i] = sum;
        }

        dp[0][0] = -1;
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= min(K,i); k++) {
                for (int j = k; j <= i; j++) {
                    dp[i][k] = min(dp[i][k], max(helper(nums, j, i) , dp[j-1][k-1])); 
                }
            }
        }

        return dp[n][K];
    }
    int helper(vector<int>& nums, int j, int i) {
        return presum[i] - presum[j] + nums[j];
    }
};

// dp[i][j] :  the minimized largest sum of the split nums[1:i] into k subarrays

// X X X X X [j ... i]
// <   k-1  ><   k   >


// dp[i][j] = m

//     for (int i = 1; i <= n; i++) {
//         for (int k = 1; k <= min(K,i); k++) {
//             for (int j = k; j <= i; j++) {
//                 dp[i][j] = min(dp[i][j], max(helper(nums, j, i) , dp[j-1][k-1])); 
//             }
//         }
//     }
    

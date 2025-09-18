class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        vector<vector<double>> dp(n+1, vector<double>(K+1, 0));

        for (int i = 1; i <= n; i++)
            dp[i][0] = INT_MIN / 2; // Invalid State 
        
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= min(i,K); k++) {
                for (int j = 1; j <= i; j++) {
                    dp[i][k] = max(dp[i][k], dp[j-1][k-1] + helper(nums, j, i));
                }
            }
        }

        double ans = 0;
        for (int k = 1; k <= K; k++) {
            ans = max(ans, dp[n][k]);
        }
        return ans;
    }
    double helper(vector<int>& nums, int j, int i) {
        int m = i - j + 1;
        double res = 0;
        for (int index = j; index <= i; index++)
            res += nums[index];
        res = res / (double)m;
        return res;
    }
};


/*
dp[i][k] : the maximum score you can achieve of all the possible partitions in nums[1:i] with k partitions.

X X X X X X [j ... i]
< k-1     ><kth>
 
dp[i][k] = max { dp[j-1][k-1] + helper(nums, j, i)}; 

*/

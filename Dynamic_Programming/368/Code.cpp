class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 0);
        vector<int> index(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[i] == dp[j]+1) {
                        index[i] = j;
                    }
                }
            }
        }

        vector<int> res;
        int max_index = max_element(dp.begin(), dp.end()) - dp.begin();
        
        res.push_back(nums[max_index]);
        int next_index = index[max_index];
        while (next_index != -1) {
            res.push_back(nums[next_index]);
            next_index = index[next_index];
        }

        return res;
    }
};

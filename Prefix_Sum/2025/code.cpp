class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        long sum = accumulate(nums.begin(), nums.end(), 0L); 
        vector<long> presum(n, 0);
        vector<long> sufsum(n, 0);

        presum[0] = nums[0];
        for (int i = 1; i < n; i++) 
            presum[i] = presum[i-1] + nums[i];
        
        sufsum[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--)
            sufsum[i] = sufsum[i+1] + nums[i];


        vector<int> res(n,0);
        unordered_map<long, int> mp;
        for (int i = 0; i < n; i++) {
            long new_sum = sum - nums[i] + k;

            if (new_sum % 2 == 0) {
                res[i] += mp[new_sum/2]; 
            }

            mp[presum[i]] += 1;
        }

        mp.clear();
        for (int i = n-1; i >= 0; i--) {
            long new_sum = sum - nums[i] + k;

            if (new_sum % 2 == 0) {
                res[i] += mp[new_sum/2]; 
            }

            mp[sufsum[i]] += 1;
        }

        int res0 = 0;
        for (int i = 1; i < n; i++) {
            if (sum % 2 == 0 && presum[i-1] == sum / 2)
                res0++;
        }

        int ans = 0;
        ans = *max_element(res.begin(), res.end());

        ans = max(ans, res0);
        return ans;
    }
};
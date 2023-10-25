class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long res = 0;
        unordered_map<int, int> mp;
        if (n < k) return 0;

        int j = 0;
        long long sum = 0;
        for (int i = 0; i < n && j < n;) {
            mp[nums[j]] += 1;
            sum += nums[j];
            if (j < k - 1) {
                j++;
                continue;
            }
            if (mp.size() == k) {
                res = max(res, sum);
            }
            
            mp[nums[i]]--;
            sum -= nums[i];
            if (mp[nums[i]] == 0)
                mp.erase(nums[i]);
            i++;
            j++;
        }

        return res;
    }
};
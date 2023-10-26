class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
    int helper(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int res = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while(j < n) {
                mp[nums[j]]++;
                if (mp.size() > k) {
                    mp[nums[j]]--;
                    if (mp[nums[j]] == 0)
                        mp.erase(nums[j]);
                    break;
                }
                j++;
            }
            if (mp.size() <= k)
                res += (j-i);

            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
                mp.erase(nums[i]);
        }
        return res;
    }
};
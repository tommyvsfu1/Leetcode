class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                sum += 1;
            else
                sum -= 1;
            presum[i] = sum;
        }

        int res = 0;
        unordered_map<int, int> mp;
        mp[0] = -1; // 當[0,n-1] subarray equal to 0時要特殊處理的情況
        for (int i = 0; i < n; i++) {
            if (mp.find(presum[i]) == mp.end()) {
                mp[presum[i]] = i;
            }
            else {
                res = max(res, i - mp[presum[i]]);
            }
        }
        return res;
    }
};
using LL = long long;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        
        LL sum = 0;
        for (auto &a : nums)
            sum += a;
        LL target = sum % p;

        if (target == 0) return 0;

        int res = INT_MAX;
        unordered_map<int, int> mp;
        LL presum = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            presum += nums[i];
            int key = ( (presum - target) % p + p) % p;
            if (mp.find(key) != mp.end()) {
                res = min(res, i - mp[key]);
            }
            mp[presum % p] = i;
        }

        return (res >= n) ? -1 : res;



    }
};
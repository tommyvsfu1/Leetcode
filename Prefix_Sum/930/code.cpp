class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1; // handle the case that entire array is a subarray sum equal to goal
        int res = 0;
        int prefix = 0;
        for (int j = 0; j < nums.size(); j++) {
            prefix += nums[j];
            if (mp.find(prefix - goal) != mp.end()) {
                res += mp[prefix - goal];
            }
            mp[prefix]+=1;
        }
        return res;
    }
};
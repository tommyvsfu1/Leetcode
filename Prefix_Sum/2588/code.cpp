using LL = long long;
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, LL> mp;
        mp[0] = 1; // 因為比如考慮整個nums數組是一個beautiful subarray時，state會是0x0
        int state = 0;
        LL res = 0;
        for (int i = 0; i < nums.size(); i++) {
            state ^= nums[i];
            res += mp[state];
            mp[state]++;
        }
        return res;
    }
};
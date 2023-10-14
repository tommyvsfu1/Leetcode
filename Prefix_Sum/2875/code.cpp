using LL = long long;
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();

        LL sum = 0;
        for (auto &a : nums) 
            sum += a;        
        LL turns = target / sum;
        LL mod = target % sum;

        for (int i = 0; i < n; i++)
            nums.push_back(nums[i]);
        
        LL res = LLONG_MAX;
        LL prefix = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < 2*n; i++) {
            prefix += nums[i];
            
            mp[prefix] = i;

            if (mp.find(prefix - mod) != mp.end()) {
                res = min(res, i - mp[prefix - mod] + turns * n);

            }
        }

        return (res == LLONG_MAX) ? -1 : res; 

    }
};
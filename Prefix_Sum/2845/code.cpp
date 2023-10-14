class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int precount = 0;
        long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % modulo == k) precount++;
            
            precount = precount % modulo;

            int target = (precount - k + modulo) % modulo;
            if (mp.find(target) != mp.end()) {
                res += mp[target];
            }

            mp[precount] += 1;
            
        }
        return res;
    }
};


// X X X X X X X 
//     j       i

// (pre[i] - pre[j-1])%m == k
// (pre[i] - k + m) % m = pre[j-1] % m
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        sort(nums.begin(), nums.end());
        
        for (auto& x : nums) {
            
            // [lower - x, upper - x]
            int a = lower_bound(nums.begin(),nums.end(), lower - x) - nums.begin();
            int b = upper_bound(nums.begin(), nums.end(), upper - x) - nums.begin();
            
            
            if (b >= a) {
                res += (b - a);
                if ( (x >= (lower-x)) && (x <= (upper-x)) ) {
                    res--;
                }
            }
        }
        res = res / 2;
        return res;
    }
};

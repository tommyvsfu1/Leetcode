class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int res = 1;
        int j = 1;
        long count = 0;
        for (int i = 0; i < n; i++) {
            while(j < n && (count + (nums[i]-nums[j]) <=k) ) {
                count += nums[i] - nums[j];
                j++;
            }
            res = max(res, j-i);

            if (i+1 < n) {
                count -= (nums[i]-nums[i+1])*(j-i-1);
            }
        }
        return res;
    }
};

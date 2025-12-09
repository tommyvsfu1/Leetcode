class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int i = 0;
        int cur = 0;
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            while (j < n && cur < target) {
                cur += nums[j];
                j++;
            }

            if (cur >= target)
                res = min(res, j-i);

            if (cur >= 0)
                cur -= nums[i];
        }
        if (res == INT_MAX) return 0;
        return res;
    }
};
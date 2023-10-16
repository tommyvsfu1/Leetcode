class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftLIS(n,1);
        vector<int> rightLIS(n,1);

        vector<int> arr;
        for (int i = 0; i < n; i++) {
            if (arr.empty() || arr.back() < nums[i]) {
                arr.push_back(nums[i]);
                leftLIS[i] = arr.size();
            }
            else {
                auto iter = lower_bound(arr.begin(), arr.end(), nums[i]);
                *iter = nums[i];
                leftLIS[i] = iter - arr.begin() + 1;
            }
        }

        arr.clear();
        for (int i = n-1; i >= 0; i--) {
            if (arr.empty() || arr.back() < nums[i]) {
                arr.push_back(nums[i]);
                rightLIS[i] = arr.size();
            }
            else {
                auto iter = lower_bound(arr.begin(), arr.end(), nums[i]);
                *iter = nums[i];
                rightLIS[i] = iter - arr.begin() + 1;
            }
        }

        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (leftLIS[i] >= 2 && rightLIS[i] >= 2) {
                res = max(res, leftLIS[i] + rightLIS[i] - 1);
            }
        }

        return n - res;
    }
};
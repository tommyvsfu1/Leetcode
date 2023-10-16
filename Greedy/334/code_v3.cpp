class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr;
        for (int i = 0; i < n; i++) {
            if (arr.empty() || arr.back() < nums[i]) {
                arr.push_back(nums[i]);
            }
            else {
                auto iter = lower_bound(arr.begin(), arr.end(), nums[i]);
                *iter = nums[i];
            }
            if (arr.size() == 3)
                return true;
        }
        return false;

    }
};
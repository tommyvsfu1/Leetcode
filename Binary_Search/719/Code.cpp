class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int right = nums.back() - nums[0];
        int left = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            left = min(left, nums[i] - nums[i-1]);
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                auto pos = upper_bound(nums.begin() + i, nums.end(), mid + nums[i]);
                count += (pos - (nums.begin() + i) - 1);
            }

            if (count < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};


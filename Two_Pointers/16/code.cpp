class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long res = INT_MAX;
        for (int k = n-1; k >= 2; k--) {
            int i = 0;
            int j = k-1;
            while (i < j) {
                int sum = nums[i]+nums[j]+nums[k];
                if (sum == target) {
                    return target;
                }
                else if (sum > target) {
                    if (abs(sum-target) < abs(res-target)) {
                        res = sum;
                    }
                    j--;
                }
                else {
                    if (abs(sum-target) < abs(res-target)) {
                        res = sum;
                    }
                    i++;
                }
            }
        }
        return res;
    }
};
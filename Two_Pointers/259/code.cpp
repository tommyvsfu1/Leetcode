class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int k = n-1; k >= 2; k--) {
            int i = 0;
            int j = k-1;
            while (i < j) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target) {
                    res += (j-i);
                    i++;
                }
                else {
                    j--;
                }
            }
        }
        return res;
    }
};

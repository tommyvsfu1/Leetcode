class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        set<vector<int>> res;
        for (int k = n-1; k >= 2; k--) {
            int i = 0;
            int j = k-1;
            while (i < j) {
                if (nums[k] + nums[i] + nums[j] == 0) {
                    res.insert({nums[i],nums[j],nums[k]});
                    j--;
                    i++;
                }
                else if (nums[k] + nums[i] + nums[j] > 0) {
                    j--;
                }
                else {
                    i++;
                }
            }
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
};
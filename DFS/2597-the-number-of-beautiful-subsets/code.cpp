class Solution {
public:
    void dfs(vector<int>& nums, int k, int index, unordered_map<int, int>& curr, int& res) {
        if (index >= nums.size()) {
            res++;
            return;
        }
        
        if (!curr[nums[index] - k] && !curr[nums[index] + k]) {
            curr[nums[index]]++;
            dfs(nums, k, index+1, curr, res);
            curr[nums[index]]--;
            
        }
            
        dfs(nums, k, index+1, curr, res);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> curr;
        dfs(nums, k, 0, curr, res);
        return res - 1;
    }
};
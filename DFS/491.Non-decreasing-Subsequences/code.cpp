class Solution {
public:
    void dfs(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& res) {
        if (curr.size() >= 2) res.push_back(curr);
        if (index >= nums.size()) return;

        unordered_set<int> Set;
        for (int i = index; i < nums.size(); i++) {
            if (curr.size() != 0 && curr.back() > nums[i]) continue;
            if (Set.find(nums[i]) != Set.end()) continue;
            Set.insert(nums[i]);
            curr.push_back(nums[i]);
            dfs(nums, i+1, curr, res);
            curr.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(nums, 0, curr, res);
        return res;
    }
};
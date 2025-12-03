class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        dfs(nums, cur, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& cur, int index) {
        res.push_back(cur);
        
        for (int i = index; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(nums, cur, i+1);
            cur.pop_back();
        }
        return;
    }
};
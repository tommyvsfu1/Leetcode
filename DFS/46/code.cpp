class Solution {
    vector<bool> visited;
    vector<vector<int>> res;
public:
    void dfs(vector<int>& nums, vector<int> curr) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == false) {
                visited[i] = true;
                curr.push_back(nums[i]);
                dfs(nums, curr);
                visited[i] = false;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        visited.resize(nums.size(), false);
        vector<int> curr;
        dfs(nums, curr);
        return res;
    }
};
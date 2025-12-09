class Solution {
public:
    int count;
    int k;
    int beautifulSubsets(vector<int>& nums, int k) {
        this->count = 0;
        this->k = k;
        int n = nums.size();
        unordered_set<int> Set;
        vector<int> visited(n, 0);
        dfs(nums, Set, visited, 0, 0);
        return count;
    }
    void dfs(vector<int>& nums, unordered_set<int>& Set, vector<int>& visited, int index, int depth) {
        

        if (Set.size() != 0) count++;

        
        for (int i = index; i < nums.size(); i++) {
            if (visited[i] == 0) {
                if (Set.find(nums[i] + k) != Set.end()) continue;
                if (Set.find(nums[i] - k) != Set.end()) continue;
                visited[i] = 1;
                if (Set.find(nums[i]) != Set.end()) {
                    dfs(nums, Set, visited, i+1, depth + 1);
                }
                else {
                    Set.insert(nums[i]);
                    dfs(nums, Set, visited, i+1, depth + 1);
                    Set.erase(nums[i]);
                }
                visited[i] = 0;     
            }
        }

    }
};
class Solution {
    int groupSum;
    int totalGroup;
    bool visited[16]; // Backtracking 常用手段，避免拜訪以前用過的index
public:
    bool dfs(vector<int>& nums, int index, int curr, int group) {
        if (group == totalGroup) {
            return true;
        }

        if (curr > groupSum)
            return false;
        
        if (curr == groupSum)
            return dfs(nums, 0, 0, group+1);

        int last = -1;
        for (int i = index; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (nums[i] == last) continue;
            visited[i] = true;
            last = nums[i];
            if (dfs(nums, i+1, curr + nums[i], group))
                return true;
            visited[i] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        if (total % k != 0) return false;
        totalGroup = k;
        groupSum = total / k;
        for (int i = 0; i < 16; i++)
            visited[i] = false;

        return dfs(nums, 0, 0, 0);

    }
};

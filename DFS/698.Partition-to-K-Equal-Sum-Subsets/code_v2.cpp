class Solution {
public:
    int sum;
    int k;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sum = accumulate(nums.begin(), nums.end(), 0) / k;
        if (accumulate(nums.begin(), nums.end(), 0) % k != 0) return false;
        this->k = k;
        int n = nums.size();
        vector<int> visited(n, 0);
        int cur = 0;
        int count = 0;
        int remain = n;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        if (nums[0] > sum) return false;
        return dfs(nums, cur, count, remain, visited, 0);
    }
    bool dfs(vector<int>& nums, int cur, int count, int remain, vector<int>& visited, int index) {
        
        if (cur > sum) return false;
        if (cur == sum) {
            count++;
            cur = 0;
            index = 0;
        }
        if (remain == 0) {
            if (count == k) return true;
            return false;
        }

        bool res = false;
        for (int i = index; i < nums.size(); i++) {
            if (visited[i] == 0) {
                if (nums[i] > sum) return false;
                if (cur + nums[i] <= sum) {
                    visited[i] = 1;
                    cur += nums[i];
                    remain--;
                    res |= dfs(nums, cur, count, remain, visited, i+1);
                    if (res == true) break;
                    remain++;
                    cur -= nums[i];
                    visited[i] = 0;
                }
            }
        }
        return res;
    }
};
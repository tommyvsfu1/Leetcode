class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int res = 0;
        for (auto [key, pos] : mp) {
            int j = 0;
            for (int i = 0; i < pos.size(); i++) {
                while(j < pos.size() && ((pos[j]-pos[i]+1) - (j-i+1) <= k) ) {
                    res = max(res, j-i+1);
                    j++;
                }
            }
        }
        return res;
    }
};
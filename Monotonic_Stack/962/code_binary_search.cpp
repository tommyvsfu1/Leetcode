class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> q;
        vector<int> idx;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (q.empty() || (q.size() > 0 && q.back() > nums[i])) {
                q.push_back(nums[i]);
                idx.push_back(i);
            }
            else {
                auto pos = upper_bound(q.rbegin(), q.rend(), nums[i]);
                int k = pos - q.rbegin();
                k = q.size() - k - 1 + 1;
                res = max(res, i - idx[k]);
            }
        }
        return res;
    }
};

// 6 0 8 2 1 5
//     
class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for (int i = 0; i < nums1.size(); i++) {
            nums.push_back(nums1[i] - nums2[i]);
        }

        int res = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int presum = 0;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];

            if (mp.find(presum) != mp.end()) {
                int width = i - mp[presum];
                res = max(res, width);
            }
            else {
                mp[presum] = i;
            }

        }
        return res;
    }
};
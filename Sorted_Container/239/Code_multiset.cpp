class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> Set;

        for (int i = 0; i < k; i++) {
            Set.insert(nums[i]);
        }

        vector<int> res;
        res.push_back(*Set.rbegin());

        for (int i = k; i < nums.size(); i++) {
            Set.erase(Set.lower_bound(nums[i-k]));
            Set.insert(nums[i]);
            res.push_back(*Set.rbegin());
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        set<vector<int>> res;
        for (int k = n-1; k >= 3; k--) {
            for (int j = k-1; j >= 2; j--) {
                int low = 0;
                int high = j-1;
                while (low < high) {
                    long long sum = (long long)nums[low] + (long long)nums[high] + (long long)nums[j] + (long long)nums[k];
                    if (sum == target) {
                        res.insert({nums[low],nums[high],nums[j],nums[k]});
                        low++;
                        high--;
                    }
                    else if (sum > target) {
                        high--;
                    }
                    else {
                        low++;
                    }
                }
            }
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};
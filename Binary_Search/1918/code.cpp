
class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }


        int left = 0;
        int right = INT_MAX;

        while (left < right) {
            int mid = left + (right - left) / 2;

            int nu = NumLessOrEqual(prefix, mid);

            if (nu >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }

    int NumLessOrEqual(vector<int>& presum, int t) {
        int res = 0;

        int j = 0;
        for (int i = 0; i < presum.size(); i++) {

            while (j < presum.size() && presum[j] - presum[i] <= t) {
                j++;
            }
            // [i+1, j-1]
            res = res + (j - (i+1));

        }
        return res;
    }
};


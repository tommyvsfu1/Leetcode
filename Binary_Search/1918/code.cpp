class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<long long> presum(n+1, 0);
        long long pre = 0;
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i-1] + nums[i-1];
        }

        long long right = LONG_MAX;
        long long left = 0;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (count(nums, presum, mid) >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
    int count(vector<int>& nums, vector<long long>& presum, long long mid) {
        int n = nums.size();
        int res = 0;
        // for (int i = 1; i <= n; i++) {
        //     auto iter = upper_bound(presum.begin(), presum.end(), mid + presum[i-1]);
        //     res += (iter - (presum.begin() + i)); // [i, j-1]
        // }
        int j = 1;
        for (int i = 1; i <= n; i++) {
            while (j <= n && presum[j]-presum[i-1] <= mid) {
                j++;
            }
            res += (j-i);
        }
        return res;
    }
};


// prefix[i:j] = prefix[j] - prefix[i] == 0

// prefix[j] - mid >= prefix[i]

// nlog(n) * log(c)

// subarray sum = prefix[j] - prefix[i-1] <= mid


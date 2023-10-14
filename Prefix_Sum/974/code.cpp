class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; // 如果sum(nums) % k == 0 也算一種可能
        int presum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];

            int r = (presum % k + k) % k; // 因為這題的數組可能有負數，所以取餘數的時候要避免負數
            if (mp.find(r) != mp.end()) {
                res += mp[r];
            }

            mp[r]++;
        }
        return res;
    }
};

// sum(arr[j:i]) % K == 0

// presum[i] % K == presum[j-1] % K
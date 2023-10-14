class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        for (auto &x : nums) {
            if (x == k) {
                x = 0;
            }
            else if (x > k) {
                x = 1;
            }
            else {
                x = -1;
            }
        }

        unordered_map<int, int> mp_odd_len;
        unordered_map<int, int> mp_even_len;

        mp_even_len[0] = 1; // 這個初始條件很難想，你可以用代入的方法歸納出要加這個初始值

        int res = 0;
        int presum = 0;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];

            if (i % 2 == 0) { // odd length 
                res += mp_odd_len[presum - 1];
                res += mp_even_len[presum];
                mp_odd_len[presum] += 1;
            }
            else { // even length
                res += mp_even_len[presum - 1];
                res += mp_odd_len[presum];
                mp_even_len[presum] += 1;
            }
        }
        return res;
    }
};


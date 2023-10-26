class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long count = 0;
        int n = nums.size();
        long long res = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while(j < n && count < k) {
                count += update(mp, nums[j], 1);
                mp[nums[j]]++;
                j++;
            }
            if (count >= k) {
                res += (n-j+1);
            }
            
            count += update(mp, nums[i], -1);
            mp[nums[i]]--;
        }
        return res;
    }

    long long update(unordered_map<int, int>& mp, int num, int d) {
        long long count = mp[num];
        long long old_pairs = count*(count-1)/2;
        count += d;
        long long new_pairs = count*(count-1)/2;
        return new_pairs - old_pairs;
    }
};
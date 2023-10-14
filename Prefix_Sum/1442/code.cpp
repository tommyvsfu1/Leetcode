class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        mp[0].push_back(-1);
        int xor_sum = 0;
        int res = 0;
        for (int k = 0; k < arr.size(); k++) {
            xor_sum ^= arr[k];
            for (auto i : mp[xor_sum^0]) {
                res += k - (i+1);
            }
            mp[xor_sum].push_back(k);
        }
        return res;
    }
};
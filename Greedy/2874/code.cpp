using LL = long long;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> preMax(n, -1);
        vector<int> sufMax(n, -1);

        for (int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i-1], nums[i-1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            sufMax[i] = max(sufMax[i+1], nums[i+1]);
        }

        LL res = 0;
        for (int i = 1; i <= n-2; i++) {
            LL value = (LL)sufMax[i] * ((LL)preMax[i] - (LL)nums[i]);
            res = max(res, value);
        }
        return res;
    }
};
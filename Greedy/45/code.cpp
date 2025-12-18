class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int next_end = 0;
        int curr_end = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {

            next_end = max(next_end, i + nums[i]);

            if (i == curr_end) {
                res++;
                curr_end = next_end;
                if (curr_end >= n-1) return res;
            }
        }
        return res;
    }
};
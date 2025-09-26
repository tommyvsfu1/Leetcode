class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();

        vector<int> dp(1<<n, INT_MAX);

        dp[0] = 0;
        for (int status = 0; status < (1<<n); status++) {
            if (dp[status] == INT_MAX) continue;
            for (auto str : stickers) {
                int new_status = FindNextStatus(status, target, str);
                dp[new_status] = min(dp[new_status], dp[status] + 1);
            }
        }

        if (dp[(1 << n) - 1] == INT_MAX) return -1;

        return dp[(1 << n) - 1];
    }
    int FindNextStatus(int status, string& target, string& str) {
        int n = target.size();
        for (auto ch : str) {
            for (int k = 0; k < n; k++) {
                if ((ch == target[k]) && (((status >> k) & 0x1) == 0) ) {
                    status |= (1 << k);
                    break;
                }
            }
        }
        return status;
    }
};

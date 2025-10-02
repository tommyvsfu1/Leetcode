class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int C = 1 << (target.size());
        vector<int> dp(1 << (target.size()), INT_MAX / 2);

        dp[0] = 0;
        for (int i = 0; i < stickers.size(); i++) {
            for (int c = 0; c < C; c++) {
                int newC = FindC(c, stickers[i], target);
                dp[newC] = min(dp[newC], dp[c] + 1);
            }
        }

        if (dp[(1 << target.size()) - 1] == (INT_MAX / 2)) return -1;

        return dp[(1 << target.size()) - 1];
    }
    int FindC(int old, string& s, string& target) {
        int nxt = old;
        

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < target.size(); j++) {
                char chr = s[i];
                if ((chr == target[j]) && ( ((nxt >> j) & 0x1) == 0 ) ) {
                    nxt = nxt | (1 << j);
                    break;
                }
            }
        }
        return nxt;
    }
};

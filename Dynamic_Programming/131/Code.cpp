class Solution {
public:
    vector<vector<string>> res;
    int dp[20][20];
    vector<vector<string>> partition(string s) {
        int n = s.size();

        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        for (int i = 0; i + 1 < n; i++) {
            dp[i][i+1] = (s[i] == s[i+1]);
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                }
            }
        }

        vector<string> sub;
        dfs(0, s, sub);
        return res;
    }
    void dfs(int i, string& s, vector<string>& sub) {
        int n = s.size();

        if (i == n) {
            res.push_back(sub);
        }
        for (int j = i; j < n; j++) {
            if (dp[i][j]) {
                sub.push_back(s.substr(i, j-i+1));
                dfs(j+1, s, sub);
                sub.pop_back();
            }
        }
        // 以下寫法也可以，是我第一個寫法，比較複雜一點，上面的寫法比較簡潔，建議用上面
        // if (start == s.size()) {
        //     res.push_back(sub);
        //     return;
        // }
        // else if (start > s.size()) {
        //     return;
        // }

        // for (int len = 1; len <= s.size(); len++) {
        //     if (start + len - 1 < s.size()) {
        //         if (dp[start][start+len-1] == true) {
        //             sub.push_back(s.substr(start, len));
        //             dfs(start+len, s, sub);
        //             sub.pop_back();
        //         }
        //     }
        // }
    }
};

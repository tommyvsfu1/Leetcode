class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();

        vector<vector<int>> dp(n+1, vector<int>(6, INT_MIN));
        unordered_map<char, int> Map = {{'a',1},{'e',2},{'i',3},{'o',4},{'u',5}};
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        int res = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 5; j++) {
                if (Map[word[i-1]] == j)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + 1;
                else
                    dp[i][j] = INT_MIN;
            }

            res = max(res, dp[i][5]);
        }

        return res;

    }
};
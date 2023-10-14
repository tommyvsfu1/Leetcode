class Solution {
    int dp[100][100];
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = INT_MAX / 2;
            }
        }

        for (int i = 0; i < n; i++)
            dp[i][i] = 0;
        
        for (auto &e : edges) {
            dp[e[0]][e[1]] = e[2];
            dp[e[1]][e[0]] = e[2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }

        int res = 0;
        int max_count = INT_MAX;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dp[i][j] <= distanceThreshold)
                    count++;
            }

            if (count <= max_count) {
                max_count = count;
                res = i;
            }
        }
        return res;
    }
};
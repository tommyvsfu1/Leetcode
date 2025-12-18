class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> I;

        for (int i = 0; i < n; i++) {
            vector<int> cur;
            cur.push_back(startTime[i]);
            cur.push_back(endTime[i]);
            cur.push_back(profit[i]);
            I.push_back(cur);
        }

        sort(I.begin(), I.end(), cmp);

        vector<int> dp(n, 0); 
        dp[0] = I[0][2];

        for (int i = 1; i < n; i++) {      
            auto it = upper_bound(I.begin(), I.begin() + i, vector<int>{0, I[i][0], 0}, cmp);

            int noPick = dp[i-1];
            int Pick = I[i][2];
            
            if (it != I.begin()) {
                int j = distance(I.begin(), it) - 1;
                Pick += dp[j];
            }

            dp[i] = max(noPick, Pick);
        }   


        return dp[n-1];
    }
};

// dp[i]: max profit from index 0 to index i 
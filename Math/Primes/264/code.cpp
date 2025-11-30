class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> dp(n+1);
        dp[1] = 1;
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        for (int i = 2; i <= n; i++) {
            int next2 = dp[p2] * 2;
            int next3 = dp[p3] * 3;
            int next5 = dp[p5] * 5;

            int min_value = min(next2,min(next3,next5));

            dp[i] = min_value;
            if (next2 == min_value) p2++;
            if (next3 == min_value) p3++;
            if (next5 == min_value) p5++;
        }
        return dp[n];
    }
};
class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        arr.insert(arr.begin(), 0);
        arr.push_back(0);


        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = INT_MAX / 2;

                for (int k = i; k <= j; k++) {

                    if (arr[k] == arr[j]) {
                        dp[i][j] = min(dp[i][j], dp[i][k-1] + max(1, dp[k+1][j-1]));
                    }

                }

            }
        }

        return dp[1][n];
    }
};

// X X X X X X X X
// i             j 

// if (i == j) {
//     dp[i][j] = 1;
// }
// else {
//     if (arr[i] == arr[j]) {
//         dp[i][j] = dp[i+1][j-1];
//     }
//     else {
//         dp[i][j] = min(dp[i+1][j] + 1, dp[i][j-1] + 1);
//     }
// }


// 1 3 1 4 5



// 1 2 2 3 1

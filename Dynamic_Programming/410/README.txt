// dp[i][j] :  the minimized largest sum of the split nums[1:i] into k subarrays

// X X X X X [j ... i]
// <   k-1  ><   k   >


// dp[i][j] = m

//     for (int i = 1; i <= n; i++) {
//         for (int k = 1; k <= min(K,i); k++) {
//             for (int j = k; j <= i; j++) {
//                 dp[i][j] = min(dp[i][j], max(helper(nums, j, i) , dp[j-1][k-1])); 
//             }
//         }
//     }

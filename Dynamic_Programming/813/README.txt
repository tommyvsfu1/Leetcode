/*
dp[i][k] : the maximum score you can achieve of all the possible partitions in nums[1:i] with k partitions.

X X X X X X [j ... i]
< k-1     ><kth>
 
dp[i][k] = max { dp[j-1][k-1] + helper(nums, j, i)}; 

*/

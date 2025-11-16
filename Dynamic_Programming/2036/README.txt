1.dp[i]狀態只取決於dp[i-1] -> 基本型I
2.dp[i][0], dp[i][1] 代表以nums[i] 跟 -nums[i] 為起點的maximum subarray sum，之所以要保留這兩個資訊，是因為下一個state都會用到
3.一開始要reverse，因為題目定義是以nums[i] ~ nums[j]的區間，只能確定nums[i]為+，所以為了最終答案的正確性，要先reverse 

基本型II

定義dp[i]: 為包含nums[i]的largest divisible subset
狀態轉移可以寫成
for (int j = i-1; j >= 0; j--) {
    if (nums[i] % nums[j] == 0) {
        dp[i] = max(dp[i], dp[j] + 1);
    }
}
由於dp[j]會繼承之前的狀態(包含nums[j]的largest divisible subset)，因此只需要比較nums[i] % nums[j] == 0即可

另外因為這題要求回傳subset，可以用index table的概念，index[i]代表在包含i的largest divisible subset中前一個index

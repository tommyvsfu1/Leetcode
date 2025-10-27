

Version 1
dp[i][]
//0: cooldown
//1: idle
//2: hold
//3: sell


Version 2:
dp[i][]
// 0: no hold
// 1: hold
概念是cooldown實際上就是一種no hold，所以刻意在for loop更新時把no hold考慮cooldown情況，這種方法好處是精簡，不過小缺點要處理最後一輪(因為最後一天可以直接sell)

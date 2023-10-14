其實剛看到就要能想到這題可以轉化成prefix sum的問題，也就是先把數組轉成1跟-1組成的數組，然後算prefix sum  
這時候我們就可以發現prefix sum[j] - prefix sum[i-1] > 0 代表[i,j]是一個well performing interval 
接著把不等式轉化一下，prefix sum[j] > prefix sum[i-1]，其實可以想到這題Leetcode 962的問題，可以用monotonic stack維護一個遞減序列，然後再從後面往前來算longest well performing interval
>monotonic stack的部分可以看962那邊的筆記

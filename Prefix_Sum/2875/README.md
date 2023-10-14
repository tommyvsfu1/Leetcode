這題因為是循環數組，要能夠想到任意的target = turns * sum(nums) + nums[i:j]\
所以我們其實可以先計算 tunrs = target / sum，然後剩餘的部分為 target % sum = nums[i:j]\
其中因為i可能會是從數組最後一個，j可能會是數組倒數第二個，所以我們可以先把數組擴張成2*n，計算上才能考慮到循環的情況。接下來就是跟subarray equal to K的問題一樣了。
>只是這邊要算的是shortest subarray，所以會看到mp[prefix] = i那行會放在檢查hash map之前，因為要考慮一種edge case是prefix本身就是答案
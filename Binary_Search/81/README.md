二分搜索  
關鍵在於  
1. 透過nums[mid] > nums[right] 來判斷原本index 0 是在mid的右邊還左邊
2. 用mid, left(right), target三者關係來判斷怎麼移動left或right(這就是單純要仔細想一下，沒有技巧)
這題的關鍵在於先找最小值，再找subarray  (一般題目的思路可能會是先找subarray)
因為如果先找subarry，一定會是O(n^2)，但最小值如果把每個元素作為當前最小值找最大區間的subarray(因為要maximum)，就可以發現其實可以用到monotonic stack  



或者你可以這樣想  
假設把所有subarray都列出來，其實最糟的情況會有N種最小值(也就是每個index都有可能當作最小值)，但每個最小值所對應的max subarray都是唯一的(因為要把左邊界和右邊界盡量擴大)，從這個思考你就可以想到這是要找nextGreater和prevGreater，所以可以用monotonic stack

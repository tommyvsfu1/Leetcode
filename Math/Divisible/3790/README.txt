由於這題用硬算的一定會overflow，數字非常大，要利用兩個原理

1. 因為我們實際上只關心remainder == 0(整除)，所以只需計算餘數就好
new_remainder = (old_remainder * 10 + 1) % k

2. 鴿籠原理 (Pigeonhole Principle)
=>由於1.只需要看餘數，而只有k個餘數(0~k-1)，最多只需要k次的(old_remainder * 10 + 1) % k運算，就能嘗試過所有可能的情況 (可以想像成是一直重複的數列，最多只有連續k個不同的數字，接下來一定會重複pattern)

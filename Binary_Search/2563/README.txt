這題答案不需要考量index，還有一個巧思是可以先找出所有可能(不管順序)，之後再除以2
如果這樣想就變成
Given a list of numbers, find all the pairs with the sum >= lower and sum <= upper
馬上想到sort + binary search + counting

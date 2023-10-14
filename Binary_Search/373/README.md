Binary search 來猜sum是多少  

這題關鍵在於  
1. countLessOrEqual 要用O(n)寫法，可以用雙指針  
2. 用binary search確定sum是多少後，要先加入<m的情況，再加入等於m的情況(因為result的順序要是從小到大的)  
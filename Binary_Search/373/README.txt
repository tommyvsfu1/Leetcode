Binary search 來猜sum是多少  

這題關鍵在於  
1. countLessOrEqual 要用O(n)寫法，可以用雙指針，或binary search
2. 用binary search確定sum是多少後，要先加入<m的情況，再加入等於m的情況(因為result的順序要是從小到大的)
3. 這題很容易MLE，盡量不要用太多的型態轉換，然後最多用到long就好

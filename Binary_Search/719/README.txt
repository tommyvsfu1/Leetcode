1. 這題看到k-th element -> 想到binary search
2. 一定要排序，不然沒有規律情況下一定O(N^2)
3. 如果排序過，至少是NlogN，需要想到這樣可以最多用for loop + binary search來查找
4. 如果直接binary search on sorted list，是沒辦法直接解出的，因為沒辦法一刀切開說，左右邊的區域不滿足
但如果用猜答案的方式，先猜min dist，接著for loop整個list 配合 binary search，就可以查到這個猜測的min dist是否就是答案
所以這題是binary search in solution space的變形題

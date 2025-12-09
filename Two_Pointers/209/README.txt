這題經典解法-> sliding window

另一種想法是 prefix sum + binary search 
-> 建立prefix sum array，由於題目想找區間合 >= target
-> Prefix[j+1] - Prefix[i] >= target
-> Prefix[j+1] >= target + Prefix[i]
代表如果固定起始點i，可以用binary search找到j+1 (由於prefix sum array是從小到大，可以用binary search)
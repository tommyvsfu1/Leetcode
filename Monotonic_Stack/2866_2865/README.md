2865 和 2866兩題除了input size(length)不同，其它完全一樣  
brute force方法就把每個index當作peak，所以會是O(n^2)    
O(n)的解法是來自於，當把每個index當作peak的時候，能不能夠用O(1)時間把sum算出來  
這時候你如果把圖畫出來(比如你把index=1當作peak，然後把其他元素按照constraint畫出來，會得到一個山型，你會發現其實要快速的把山型算出來，其實就是要用prefix sum 跟 monotonic stack(因為山型可以拆分成很多個水平線方塊組成，有點像微積分談到積分的方塊，每個方塊的邊界可以用monotonic stack的prevSmaller或nextSmaller求出來，接著用prefix sum的概念就可以快速算出水平方塊))
```
以下是一個把index=4當作peak的山型
              *
        * * *   * *
      *           
index 0 1 2 3 4 5 6
```
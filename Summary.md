# Leetcode
## Prefix Sum

### Subarray equal to K
```
prefix[i:j] = prefix[j] - prefix[i-1] = S
prefix[i-1] = prefix[j] - S
```
所以，我們只要one pass，每次看有多少個prefix[i-1] == prefix[j] - S

### Divisible or Modulo Related Problems
大方向就是把數學式子寫出來，看要怎麼hash map查找\
比如Divisible的問題用到的概念就是arr[j:i]如果要divisible，就代表```sum(arr[j:i]) % k == 0```，其實就代表```presum[i] % k - presum[j-1] % k = 0```，也就是```presum[i] % k == presum[j-1] % k```


## Greedy
### Three Pass
目前感覺是同時用到prefix/suffix的概念都會算是Three Pass問題

## BFS
Queue  
起始點要注意一下    
每層loop有沒有一定要pop完，要看題目(比如有些題目是多節點開始BFS看shortest path到某些方格，那這樣就要pop完才能確保算cost/step時能正確)  

### Topological Sort
預先算好每個node的indegree，從indegree=0的nodes開始剝洋蔥

## Graph

### Dijkstra
BFS + Priority Queue
>pq 存的是從source node到某個node的cost
>注意在每個iteration在 pq.top()完跟檢查neighbor的loop時，都要檢查visited (因為priority queue這邊的寫法不會是pop完，而是每次都pop一個而已。也就是說有可能會發生某個節點會被加入pq好幾次)

### Floyd Warshall
總共三層for loop  
每次加入node k 就兩層for loop更新dp[i][j]  
```dp[i][j]``` is the shortest path from node i to node j
```
dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
```
## DFS
### Backtracking
通常可以用index或visited來避免重複拜訪
基本上就是recursion暴力解就對了

## Binary Search
1. Search in sorted data
2. Guess a solution in solution space (solution space usually be monotonic such as 0~INT_MAX)
3. Top-k problem
>跟2.很類似，都是猜答案，然後count有多少個符合。正確答案會發生在cout==K的時候  
>在算count >, =, < k的時候，等號"="到底是放在大於還是小於，可以單獨先想是等號時是移動left還是right  
>或者就直接分成>, =, <三種情況也可以，思考會比較清楚
## Monotonic Stack
1. Next/Prev Greater/Smaller element
2. subarray minimum/maximum (把元素當作最小值，找區間的左邊界/右邊界)
3. 遞減序列/遞增序列
4. (tricky) Largest Rectangle in Histogram related problems
>idea: 先找高度，然後找左右邊界

## Union Find
1. Undirected Graph cycle detection (E.g redundant connection problem)
2. connected components相關問題    
3. Minimum Spanning Tree (MST) : 用Kruskal (先排序edges，再依序從最小edge開始加入。判斷cycle用union find) 
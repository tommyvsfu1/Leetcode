# Leetcode
## Two Pointer
1.控制left, right，從左右往中間移動
>移動left還是移動right  ，取決於題目定義，預期可以用constant time知道要移動left還right

2. 控制i, j 從同邊開始移動 (sliding window)

## Sliding Window
Template  
```
int j = 0;
for (int i = 0; i < boundary condition; i++) {
    while (j < boundary condition && something) {
      j++;
    }
}
```
通常會需要constant time的處理來維護這個sliding window的一些資訊  

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
不一定每個pass都是O(n)，有可能O(nlogn)，看題目\
對於prefix/suffix的資訊，可以很多種比如 leftMax, leftMin, rightMax, rightMin, Prefix Sum, Suffix Sum, Monotoinc Stack, ...\
承上，比較難的題目會多用到其他技巧如DP/Monotonic Stack/Prefix Sum/...

## BFS
Queue  
起始點要注意一下    
每層loop有沒有一定要pop完，要看題目(比如有些題目是多節點開始BFS看shortest path到某些方格，那這樣就要pop完才能確保算cost/step時能正確)  

>另外也有multi-source BFS的題目，比如最經典的是grid分成1跟0，問0到最近的1距離，就可以從1開始用multi-source BFS，接著就變成minimum distance(equal weight)問題

### Minimum Dist (Equal Weight)
如果是minimum distance，並且都是equal weight，BFS是一種求法

### Topological Sort
預先算好每個node的indegree，從indegree=0的nodes開始剝洋蔥

## Tree
### Traversal
三種深度優先遍歷（DFS）只差在「拜訪節點（visit）發生的時機」
<img width="670" height="411" alt="image" src="https://github.com/user-attachments/assets/1cbec5dd-e0d1-4c36-adae-88ff34fb1ccf" />

### LCA
DFS+counter，如果curr node的右子樹 + 左子樹為2，代表當下的curr node為LCA
```
class Solution {
    TreeNode* res = NULL;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
    int dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == NULL) return 0;

        int left = dfs(node->left, p, q);
        int right = dfs(node->right, p, q);
        int self = ((node == p) || (node == q));
        int total = left + right + self;
        if (total == 2 && res == NULL)
            res = node;
        return total;

    }
};
```
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

### Coloring
經典題785.Is Graph Bipartite?
對每個點做BFS，開始0,1塗色，如果違反塗色規則，代表存在奇數環，不是Bipartite

## DFS
### Backtracking
通常可以用index或visited來避免重複拜訪
基本上就是recursion暴力解就對了

## Binary Search
1. Search in sorted data
2. Guess a solution in solution space (solution space usually be monotonic such as 0~INT_MAX)
3. Find kth element / Top-k problem
>跟2.很類似，都是猜答案，然後count有多少個符合。正確答案會發生在cout==K的時候  
>在算count >, =, < k的時候，等號"="到底是放在大於還是小於，可以單獨先想是等號時是移動left還是right  
>或者就直接分成>, =, <三種情況也可以，思考會比較清楚

注意: Maximum 跟 Minimum ，要注意left, right移動的方向  

#### Note 1
對於Top-K problem，很常用到GreaterThanOrEqual或是SmallerThanOrEqual兩種函式\
count = GreaterThanOrEqual(nums, mid)，若count == k，那麼會讓low = mid，因為當count == k，代表目前mid一定小於或等於K-th largest element，如果大於那count就會是k-1了，你可以心理想一個實數軸，把K-th largest element和mid的值放在軸上想\
反之，如果用SmallerThanOrEqual，則是反過來讓high = mid
#### Note 2
```
int mid = low + (high - low) / 2; // 更新: low=mid+1，high=mid
int mid = low + (higt - low+1) / 2; // 更新: low=mid，high=mid-1
```
>注意如果是用while(left < high)的寫法，low,high只有一個會是mid的offset
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

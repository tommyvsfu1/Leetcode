# Leetcode
# Two Pointer
1.控制left, right，從左右往中間移動
>移動left還是移動right  ，取決於題目定義，預期可以用constant time知道要移動left還right

2. 控制i, j 從同邊開始移動 (sliding window)

---


# Sliding Window
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

---


# Prefix Sum

### Subarray equal to K
```
prefix[i:j] = prefix[j] - prefix[i-1] = S
prefix[i-1] = prefix[j] - S
```
所以，我們只要one pass，每次看有多少個prefix[i-1] == prefix[j] - S   
**多少個index滿足，可以維護一個unordered_map，對應mp[prefix_sum] = counter或index**

### Divisible or Modulo Related Problems
大方向就是把數學式子寫出來，看要怎麼hash map查找\
比如Divisible的問題用到的概念就是arr[j:i]如果要divisible，就代表```sum(arr[j:i]) % k == 0```，其實就代表```presum[i] % k - presum[j-1] % k = 0```，也就是```presum[i] % k == presum[j-1] % k```

---

# Greedy
### Three Pass
目前感覺是同時用到prefix/suffix的概念都會算是Three Pass問題
不一定每個pass都是O(n)，有可能O(nlogn)，看題目\
對於prefix/suffix的資訊，可以很多種比如 leftMax, leftMin, rightMax, rightMin, Prefix Sum, Suffix Sum, Monotoinc Stack, ...\
承上，比較難的題目會多用到其他技巧如DP/Monotonic Stack/Prefix Sum/...

---

# BFS
Queue  
起始點要注意一下    
每層loop有沒有一定要pop完，要看題目(比如有些題目是多節點開始BFS看shortest path到某些方格，那這樣就要pop完才能確保算cost/step時能正確)  

>另外也有multi-source BFS的題目，比如最經典的是grid分成1跟0，問0到最近的1距離，就可以從1開始用multi-source BFS，接著就變成minimum distance(equal weight)問題

### Minimum Dist (Equal Weight)
如果是minimum distance，並且都是equal weight，BFS是一種求法

### Topological Sort
預先算好每個node的indegree，從indegree=0的nodes開始剝洋蔥  
如果要把先前的node資訊帶給這層的node，可以用vector<unordered_set<int>> PreSet

---

# Tree
### Traversal
三種深度優先遍歷（DFS）只差在「拜訪節點（visit）發生的時機」
<img width="670" height="411" alt="image" src="https://github.com/user-attachments/assets/1cbec5dd-e0d1-4c36-adae-88ff34fb1ccf" />
### Level Order Traversal
BFS剝洋蔥   
類似題: 199. Binary Tree Right Side View  
```
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;

        if (root)
            q.push(root);

        while(!q.empty()) {
            int len = q.size();
            
            vector<int> r;

            while(len--) {
                TreeNode* node = q.front();

                r.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                q.pop();
            }

            res.push_back(r);
        }
        return res;
    }
};
```
### Diameter and LongestPathToLeaf
```
class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        LongestPathToLeaf(root);
        return res - 1; // -1是因為res最後拿到的值是#(左子樹最深節點 + 右子樹最深節點 + 該Node)，所以要-1才能得到edge number 
    }
    int LongestPathToLeaf(TreeNode* curr) { 
        if (curr == NULL) return 0;

        int leftSum = LongestPathToLeaf(curr->left); // curr->left 到最深的leaf有幾個節點 (包含curr->left)
        int rightSum = LongestPathToLeaf(curr->right); // curr->right 到最深的leaf有幾個節點 (包含curr->right)

        res = max(res, leftSum + rightSum + 1);

        return max(leftSum, rightSum) + 1;
    }
};
```
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
### Binary Tree Construction (using inorder traversal + preorder/postorder traversal)
核心概念: 建立hashMap mp[inorder[i]] = i  
接著DFS 從上層一路recursive建立node，每次切分右子樹與左子樹，從preorder/postorder traversal的數列知道root，接著左子樹數量可以透過inorder 數列判斷  
Inorder + Preorder
```
class Solution {
public:
    TreeNode* root;
    unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        root = dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

        return root;
    }
    TreeNode* dfs(vector<int>& pre, int a, int b, vector<int>& in, int m, int n) {
        if (a > b || m > n) return NULL;

        TreeNode* root = new TreeNode(pre[a]);

        int pos = mp[pre[a]];
        int L = pos - m;

        root->left = dfs(pre, a + 1, a + L, in, m, pos-1);
        root->right = dfs(pre, a + L + 1, b, in, pos + 1, n);
        return root;
    }
};
```

---

# Graph

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

---

# DFS
### Backtracking
通常可以用index或visited來避免重複拜訪
基本上就是recursion暴力解就對了

---

# Binary Search
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

---

# Monotonic Stack
1. Next/Prev Greater/Smaller element
2. subarray minimum/maximum (把元素當作最小值，找區間的左邊界/右邊界)
3. 遞減序列/遞增序列
4. (tricky) Largest Rectangle in Histogram related problems
>idea: 先找高度，然後找左右邊界

---

# Union Find
1. Undirected Graph cycle detection (E.g redundant connection problem)
2. connected components相關問題    
3. Minimum Spanning Tree (MST) : 用Kruskal (先排序edges，再依序從最小edge開始加入。判斷cycle用union find)

---

# Dynamic Programming
#### 基本型I
給出一個序列(數組/字符串)，其中每一個元素可以認為"一天"，並且"今天"的狀態只取決於"昨天"的狀態
* 定義dp[i][j]: 表示第i-th輪的第j種狀態 (j=1...k)
* 千方百計將dp[i][j] 與 前一輪的dp[i-1][j]產生關係 (j=1...k)
* 最終結果是dp[last][j]中的某種aggregation (sum, max, min)

#### 雙序列型
* 定義dp[i][j] : 表示s[1:i] and t[1:j] 的數列/字串 子問題求解
* 千方百計將dp[i][j] 跟 dp[i-1][j], dp[i][j-1], dp[i-1][j-1] 產生關係
* 如果是字串問題，通常可以分成s[i] == t[j] 跟 s[i] != t[j] 的情況 建立 dp[i][j] 關係
* 最終解答是 dp[m][n]  
> 目前認為這類問題之所以不用考量前面的i,j，是因為通常需要考量s,t兩個完整字串去求解，而因為我們定義dp[i][j]只考慮子字串，所以答案是dp[m][n]
> 因為dp[i][j]是代表s[1:i], t[1:j]，所以一定要包含i, j兩個的字符，因此不需要跟基本型II要往前考慮更早的state (比如Leetcode 727我一開始寫以為要考慮更早的state，但不用)

#### 第I類區間型
給出一個序列，明確要求切割成K個連續區間，要計算這些區間的某個最優特質
* 定義dp[i][k] 表示 s[1:i] 分成k個區間，此時能得到最優解
* 計算思路: 定義最後一個區間的起始位置是j，接著將dp[i][k]分割成dp[j-1][k-1]和s[j:i]兩部分
```
X X X X X X X [j ... i]  
< 前K-1區間  > <第K 區間>
```
* 答案為dp[N][K]

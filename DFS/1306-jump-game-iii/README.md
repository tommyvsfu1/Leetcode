DFS(backtracking)

這題算是有一點點DP(memorization)跟Graph的影子在裡面，但本質上就是backtracking，因為我們只要找出一組解可行就好，不是最優解(不需要DP)
因為我們只需要找出DFS中一條路徑是可以成立的，但又要避免cycle無限迴圈(graph的概念)，所以可以用visited的方式避免重新訪問同個index
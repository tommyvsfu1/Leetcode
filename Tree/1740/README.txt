看到LCA問題 -> DFS 
由於題目要判斷LCA 到 兩端點(p,q)距離，因為兩端點距離可以DFS bottom up順便計算，所以DFS設計兩個回傳值
1. count (count判斷node以下的subtree是否包含p,q)
2. distance to current node (這個設計要有點巧思，需要從遇到p,q後bottom up才能++)


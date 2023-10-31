1. 給node的parents，可以直接用vector<vector<int>>來記錄每個node的child，因為它就是一種graph。不要想說Tree只有Node那種資料結構表示方法\
2. 每個node可以拆分成三部分，左子樹,右子樹, parent部分。parent部分的節點數量，其實就是 n - 1 - 左子樹節點數 - 右子樹節點數
3. 這題一樣可以利用在DFS求左子樹, 右子樹的節點數的同時來算答案
DFS (backtracking)

這題為了避免產生重複的結果
1. 用for loop來選擇第index個元素是誰
2. 承1. 這樣的好處是可以用一個unordered_set來避免重複結果

但由於用以上的方法，會在每個recursive開頭就直接視為一種結果
The idea of solving this problem is

First, I get the LCA of the source node and destiniation node

Then i record the path from the root to source and destination node and represent them as string.

Finally i concatenate the two strings to get the answer.


Note that Wisdompeak solution:
直接找path to source/destination node
接著比對兩個路徑，分岔點代表LCA，直接做字串處理
因為這題要打印路徑，所以Wisdompeak說可以直接從root dfs紀錄路徑就好，不用包成LCA的recursion

這題其實概念不難，只是寫起來比較複雜\
longest consecutive 本身就可以想成拐點 + 左部分 + 右部分\
基本上有兩種情況，一種是左部分是increasing右部分decreasing，另一種是反過來。\
我們可以用一個DFS求longest increasing path from node to leaf，一個DFS求longest decreasing path from node to leaf，最後再用一個DFS求longest consecutive sequence
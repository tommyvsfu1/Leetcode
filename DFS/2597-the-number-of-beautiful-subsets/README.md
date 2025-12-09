DFS(backtracking)

code_v2 是最新寫法


code_v1 貌似是之前寫法遇到TLE，改用unordered_map，但code_v2是最直觀的，且也確定可以pass
單純用unordered_set 的insert/find/erase 會TLE
所以用unordered_map 快速檢查
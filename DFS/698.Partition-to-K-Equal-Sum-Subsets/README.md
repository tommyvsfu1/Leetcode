這題是Backtracking的題目，Backtracking的概念就是DFS
> 每個group因為都是equal sum，所以我們只需要湊group(subsets)就好

DFS的過程，可以先湊group，等確定能湊到euqal sum後，再往下湊


另外這題有一些speedup的skills
比如以下兩行的目的是先從比較大的數開始湊，這樣能更快的確定某個分支是不是可行的
```
sort(nums.begin(), nums.end());
reverse(nums.begin(), nums.end());
```


code_v2 是2025/12/4寫的版本，基本上就是自己寫的pruning方式
這題主要需用到pruning技巧
1.sorting, 2. start index(也就是先湊group) 
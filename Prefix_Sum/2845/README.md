這題一看到最直觀就是O(n^2)解法，為了降低時間複雜度，可以聯想到應該會跟prefix sum + hash map有關\
遇到prefix sum的modulo問題，就是把數學表示法寫出來看我們到底要求什麼才能快速找到區間\
基本上我們可以紀錄那些nums[i] % modulo == k的元素數量，也就是pre[i]為nums[i] % modulo == k的元素數量，這樣如果要快速找到區間的起點，就需要滿足以下條件
X X X X X X X 
    j       i

(pre[i] - pre[j-1])%m == k
(pre[i] - k + m) % m = pre[j-1] % m
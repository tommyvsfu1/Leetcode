1. kth missing number -> kth element -> 想到用 binary search
2. binary search 搜尋: 若mid index 之前的missing number < k，則往右找(移動left)，反之則固定right，這樣一定會收斂
3. 收斂完的element，代表跟k-th missing number是最靠近的數字，但element前的missing number 可能 大於 小於 k，也可能是0，所以要分開計算 (1,2點最重要，3就是分開討論就好)

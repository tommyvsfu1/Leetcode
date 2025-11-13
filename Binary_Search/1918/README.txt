binary search來猜subarray sum
關鍵在於
1. 要先算好prefix sum
2. NumLessOrEqual 函式的寫法可以用雙指針(因為prefix sum本身是monotonic的)，或是binary search

binary search的概念在於:
subarray[i:j] sum = prefix[j] - prefix[i-1] <= mid
=> prefix[j] <= mid + prefix[i-1]

為了快速計算當固定i時候，有多少j滿足，我們直接反過來思考prefix[j] > mid + prefix[i-1] 的情況，也就是upper_bound(prefix.begin(), prefix.end(), mid + prefix[i-1])之前的位置 ~ i都滿足
所以可以寫成
for (int i = 1; i <= n; i++) {
     auto iter = upper_bound(presum.begin(), presum.end(), mid + presum[i-1]); // 更正確的寫法是從presum.begin() + i開始搜尋
     res += (iter - (presum.begin() + i)); // [i, j-1]
}

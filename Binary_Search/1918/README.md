binary search來猜subarray sum
關鍵在於
1. 要先算好prefix sum
2. NumLessOrEqual 函式的寫法可以用雙指針(因為prefix sum本身是monotonic的)
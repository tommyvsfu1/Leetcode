因為我們是要找出符合條件的subarray，而不是真的先選subarray找median看是不是k\
所以可以轉化1,0,-1數組，直接看\
如果 arr[j:i] odd length, sum(arr[j:i]) = 0 就代表是一個合法的subarray\
而如果 arr[j:i] even length, sum(arr[j:i]) = 1 就代表是一個合法的subarray
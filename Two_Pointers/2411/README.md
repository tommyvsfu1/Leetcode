首先要先理解從index i開始，如果要往右得到最大值，那一定無腦選n-1就可以了，因為OR會越用越大，所以題目要求的是對於每個index i，求一個最小的subarray使得j st. OR arr[i:j] == OR arr[i:n-1]\
所以可以想像我們的滑窗是固定左端點i，然後右端點從後面往前滑\
而右端點如果可以往前移動，代表arr[j]所含有的bit，一定都存在於 OR arr[i:j-1]
```
X X X X X X X X X X
      i       j 
```
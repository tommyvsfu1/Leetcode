首先有兩個數組，我們可以發現可以變換成一個數組，就會是一個subarray sum equal to K的問題\
prefix[i:j] = prefix[j] - prefix[i-1] = S\
prefix[i-1] = prefix[j] - S\
所以，我們只要one pass，每次看有多少個prefix[i-1] == prefix[j] - S\
本題的S = 0 
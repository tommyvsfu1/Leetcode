一般XOR題目有很高機率會用到性質 A^A = 0\
這題用到arr[i:j-1] 跟 arr[j:k]兩個區間，如果arr[i:j-1]和arr[j:k]相等，其實就代表arr[i:j-1] ^ arr[j:k] = arr[i:k] = 0。\
同時，如果一個區間arr[i:k] = 0，代表我們只要有辦法拆分成兩個區間，兩個區間的XOR一定為0，也就代表兩區間各自XOR會是相等的 (C = A^B = 0，代表A = B，故A^B=0)\

有了以上的想法之後，要知道 XOR[i:k] = XOR[k] ^ XOR[i-1] \
>跟prefix sum的性質很相似，要背起來
其實就會變成跟prefix sum很像的問題，因為我們就是要找 XOR[i:k] = 0 = XOR[k] ^ XOR[i-1]，所以代表我們要找的區間數量，就是每次index到k之後，看先前有多少個XOR[i-1] (然後XOR[i:k]之間又可以拆成k-(i+1)個區間)
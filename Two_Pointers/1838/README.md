蠻好想的，因為每個operation是把數字往上加，所以我們可以先sort完後，就是對於每個index i ，看能容納多少個較小的數字\
比較要注意的是，當從i 更新到 i+1的時候，可以利用arr[i] - arr[i+1]的差距，來快速更新接下來的window需要的operation
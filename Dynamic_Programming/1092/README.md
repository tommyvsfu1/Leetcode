common supersequence其實可以想像成類似str1和str2的聯集，因為必須包含str1和str2\
若str1[i] == str2[j]，那這樣就直接dp[i-1][j-1] + 1\
如果不相等，common supersequence可以從str1[1:i-1]跟str2[1:j]找common supersequence之後再+1，或是從str1[1:i]跟str2[1:j-1]找common supersequence之後再+1\
最後要把實際的supersequence打印出來，其實用雙指針根據之前的條件反向回溯就好
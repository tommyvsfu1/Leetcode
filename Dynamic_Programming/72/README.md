如果word1[i] == word2[j]，那沿用dp[i-1][j-1]\
如果不相等，那就要分別從先前狀態讓它變成相等，然後看三種情況哪種最小\
1. 如果要insert，代表增加一個字符讓跟word2[j]相等，接著看dp[i][j-1]需要多少operations\
2. 如果要delete，代表刪除目前字符word1[i]，接著看dp[i-1][j]要需要多少operations\
3. 如果要replace，代表replace，看dp[i-1][j-1]